# Quansheng UV-K5 driver (c) 2023 Jacek Lipkowski <sq5bpf@lipkowski.org>
# Adapted For UV-K5 EGZUMER custom software By EGZUMER, JOC2
#
# based on template.py Copyright 2012 Dan Smith <dsmith@danplanet.com>

# 0x03E9 to 0x1DFF VFO params
# 0x1F00 to 0x2000 calibration

# 0x2000 to 0x5E7F channels freqs and params 16 bytes
# 0x5E80 to 0x6267 channel attributes 1 byte

# 0x6280 to 0xA0FF channels names 16 bytes
# 0xA100 to XXXX history record 6bytes (chirp read only see PROG_SIZE)
# MEM_SIZE 0xA100

import struct
import logging
import wx

from chirp import chirp_common, directory, bitwise, memmap, errors, util
from chirp.settings import RadioSetting, RadioSettingGroup, \
    RadioSettingValueBoolean, RadioSettingValueList, \
    RadioSettingValueInteger, RadioSettingValueString, \
    RadioSettings, InvalidValueError

LOG = logging.getLogger(__name__)

# Show the obfuscated version of commands. Not needed normally, but
# might be useful for someone who is debugging a similar radio
DEBUG_SHOW_OBFUSCATED_COMMANDS = True

# Show the memory being written/received. Not needed normally, because
# this is the same information as in the packet hexdumps, but
# might be useful for someone debugging some obscure memory issue
DEBUG_SHOW_MEMORY_ACTIONS = True

DRIVER_VERSION = "Quansheng UV-K5/K6/5R driver (c)"
VALEUR_COMPILER = "ENABLE"

MEM_FORMAT = """
#seekto 0x5E80;
struct {
u8 scanlist:4,
band:4;
} ch_attr[999];

#seekto 0x2000;
struct {
  ul32 freq;
  ul32 offset;
  u8 rxcode;
  u8 txcode;
  u8 txcodeflag:4,
  rxcodeflag:4;
  u8 modulation:4,
  offsetDir:4;
  u8 __UNUSED1:1,
  bandwidth_ext:2,
  busyChLockout:1,
  txpower:2,
  bandwidth:1,
  freq_reverse:1;
  u8 __UNUSED2;
  u8 step;
  u8 scrambler;
} Channel[999];

#seekto 0x6280;
struct {
char name[16];
} Channelname[999];

#seekto 0xe70;
u8 unused1;
u8 squelch;
u8 max_talk_time;
u8 unused2;
u8 key_lock;
u8 mic_gain;


u8 backlight_min:4,
backlight_max:4;

u8 Channel_display_mode;
u8 unused3;
u8 battery_save;
u8 backlight_time;
u8 ste;
u8 freq_mode_allowed;

#seekto 0xe90;

u8 keyM_longpress_action:7,
    button_beep:1;

u8 key1_shortpress_action;
u8 key1_longpress_action;
u8 key2_shortpress_action;
u8 key2_longpress_action;
u8 scan_resume_mode;
u8 auto_keypad_lock;
u8 power_on_dispmode;
ul32 password;

#seekto 0xea0;
u8 voice;
u8 s0_level;
u8 s9_level;

#seekto 0xea8;
u8 roger_beep;
u8 rp_ste;
u8 TX_VFO;
u8 Battery_type;

#seekto 0xeb0;
char logo_line1[16];
char logo_line2[16];

//#seekto 0xf18;
u8 slDef;
u8 sl1PriorEnab;
u8 sl1PriorCh1;
u8 sl1PriorCh2;
u8 sl2PriorEnab;
u8 sl2PriorCh1;
u8 sl2PriorCh2;

#seekto 0xf47;
u8  backlight_on_TX_RX:2,
    AM_fix:1,
    mic_bar:1,
    battery_text:2,
    unused4:1,
    unknown:1;



struct {
    struct {
        #seekto 0x1E00;
        u8 openRssiThr[10];
        #seekto 0x1E10;
        u8 closeRssiThr[10];
        #seekto 0x1E20;
        u8 openNoiseThr[10];
        #seekto 0x1E30;
        u8 closeNoiseThr[10];
        #seekto 0x1E40;
        u8 closeGlitchThr[10];
        #seekto 0x1E50;
        u8 openGlitchThr[10];
    } sqlBand4_7;

    struct {
        #seekto 0x1E60;
        u8 openRssiThr[10];
        #seekto 0x1E70;
        u8 closeRssiThr[10];
        #seekto 0x1E80;
        u8 openNoiseThr[10];
        #seekto 0x1E90;
        u8 closeNoiseThr[10];
        #seekto 0x1EA0;
        u8 closeGlitchThr[10];
        #seekto 0x1EB0;
        u8 openGlitchThr[10];
    } sqlBand1_3;

    #seekto 0x1EC0;
    struct {
        ul16 level1;
        ul16 level2;
        ul16 level4;
        ul16 level6;
    } rssiLevelsBands3_7;

    struct {
        ul16 level1;
        ul16 level2;
        ul16 level4;
        ul16 level6;
    } rssiLevelsBands1_2;

    struct {
        struct {
            u8 lower;
            u8 center;
            u8 upper;
        } low;
        struct {
            u8 lower;
            u8 center;
            u8 upper;
        } mid;
        struct {
            u8 lower;
            u8 center;
            u8 upper;
        } hi;
        #seek 7;
    } txp[7];

    #seekto 0x1F40;
    ul16 batLvl[6];

    #seekto 0x1F80;
    u8 micLevel[5];

    #seekto 0x1F88;
    il16 xtalFreqLow;

    #seekto 0x1F8E;
    u8 volumeGain;
    u8 dacGain;
} cal;

"""


# flags1
FLAGS1_OFFSET_NONE = 0b00
FLAGS1_OFFSET_MINUS = 0b10
FLAGS1_OFFSET_PLUS = 0b01

POWER_HIGH = 0b10
POWER_MEDIUM = 0b01
POWER_LOW = 0b00

# power
UVK5_POWER_LEVELS = [chirp_common.PowerLevel("Low",  watts=1.50),
                     chirp_common.PowerLevel("Med",  watts=3.00),
                     chirp_common.PowerLevel("High", watts=5.00),
                     ]

# scrambler
SCRAMBLER_LIST = ["OFF", "2600Hz", "2700Hz", "2800Hz", "2900Hz", "3000Hz",
                   "3100Hz", "3200Hz", "3300Hz", "3400Hz", "3500Hz"]
# rx mode
RXMODE_LIST = ["MAIN ONLY", "DUAL RX RESPOND", "CROSS BAND", "MAIN TX DUAL RX"]
# Channel display mode
CHANNELDISP_LIST = ["Frequency", "Channel Number", "Name", "Name + Frequency"]

# TalkTime
TALK_TIME_LIST = ["30 sec", "1 min", "2 min", "3 min", "4 min", "5 min",
                   "6 min", "7 min", "8 min", "9 min", "15 min"]

# battery save
BATSAVE_LIST = ["OFF", "1:1", "1:2", "1:3", "1:4"]

# battery type
BATTYPE_LIST = ["1600 mAh", "2200 mAh"]
# bat txt
BAT_TXT_LIST = ["NONE", "VOLTAGE", "PERCENT"]
# Backlight auto mode
BACKLIGHT_LIST = ["OFF", "5s", "10s", "20s", "1min", "2min", "4min",
                  "Always On"]

# Backlight LVL
BACKLIGHT_LVL_LIST = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]

# Backlight _TX_RX_LIST
BACKLIGHT_TX_RX_LIST = ["OFF", "TX", "RX", "TX/RX"]

# steps TODO: change order
STEPS = [2.5, 5, 6.25, 10, 12.5, 25, 8.33, 0.01, 0.05, 0.1, 0.25, 0.5, 1, 1.25,
         9, 15, 20, 30, 50, 100, 125, 200, 250, 500]

# ctcss/dcs codes
TMODES = ["", "Tone", "DTCS", "DTCS"]
TONE_NONE = 0
TONE_CTCSS = 1
TONE_DCS = 2
TONE_RDCS = 3


CTCSS_TONES = [
    67.0, 69.3, 71.9, 74.4, 77.0, 79.7, 82.5, 85.4,
    88.5, 91.5, 94.8, 97.4, 100.0, 103.5, 107.2, 110.9,
    114.8, 118.8, 123.0, 127.3, 131.8, 136.5, 141.3, 146.2,
    151.4, 156.7, 159.8, 162.2, 165.5, 167.9, 171.3, 173.8,
    177.3, 179.9, 183.5, 186.2, 189.9, 192.8, 196.6, 199.5,
    203.5, 206.5, 210.7, 218.1, 225.7, 229.1, 233.6, 241.8,
    250.3, 254.1
]

# lifted from ft4.py
DTCS_CODES = [ # TODO: add negative codes
    23,  25,  26,  31,  32,  36,  43,  47,  51,  53,  54,
    65,  71,  72,  73,  74,  114, 115, 116, 122, 125, 131,
    132, 134, 143, 145, 152, 155, 156, 162, 165, 172, 174,
    205, 212, 223, 225, 226, 243, 244, 245, 246, 251, 252,
    255, 261, 263, 265, 266, 271, 274, 306, 311, 315, 325,
    331, 332, 343, 346, 351, 356, 364, 365, 371, 411, 412,
    413, 423, 431, 432, 445, 446, 452, 454, 455, 462, 464,
    465, 466, 503, 506, 516, 523, 526, 532, 546, 565, 606,
    612, 624, 627, 631, 632, 654, 662, 664, 703, 712, 723,
    731, 732, 734, 743, 754
]

# flock list extended
FLOCK_LIST = ["DEFAULT+ (137-174, 400-470 + Tx200, Tx350, Tx500)",
              "FCC HAM (144-148, 420-450)", 
              "CE HAM (144-146, 430-440)", 
              "GB HAM (144-148, 430-440)", 
              "137-174, 400-430", 
              "137-174, 400-438", 
              "PMR446",
              "Disable All",
              "Unlock All"]

SCANRESUME_LIST = ["Listen 5 seconds and resume (TIMEOUT)",
                   "Listen until signal dissapears (CARRIER)",
                   "Stop scanning after receiving a signal (STOP)"]
WELCOME_LIST = ["FULL", "MESSAGE", "VOLTAGE", "NONE"]
VOICE_LIST = ["OFF", "Chinese", "English"]

# ACTIVE CHANNEL
TX_VFO_LIST = ["A", "B"]
REMENDOFTALK_LIST = ["OFF", "Morse", "Mario"]
RTE_LIST = ["OFF", "100ms", "200ms", "300ms", "400ms",
            "500ms", "600ms", "700ms", "800ms", "900ms", "1000ms"]

MEM_SIZE = 0xA100   # size of all memory
PROG_SIZE = 0xA100  # size of the memory that we will write
MEM_BLOCK = 0x80    # largest block of memory that we can reliably write
BANDS_WIDE = {
        0: [ 14.0, 108.0],
        1: [108.0, 136.9999],
        2: [137.0, 173.9999],
        3: [174.0, 349.9999],
        4: [350.0, 399.9999],
        5: [400.0, 469.9999],
        6: [470.0, 1300.0]
        }

SCANLIST_LIST = ["None", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]
SCANLIST_SELECT_LIST = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]

KEYACTIONS_LIST = ["NONE",
                   "FLASH LIGHT",
                   "TOGGLE PTT", # rajouté & fonctionnel
                   "POWER",
                   "MONITOR",
                   "SCAN", #not on radio ??? -> possible de le supprimer sans provoquer d'erreur / disparait alors de Chirp
                   "FM RADIO",
                   "1750Hz TONE", # 1750HZ on radio
                   "LOCK KEYPAD",
                   "Switch main VFO (SWITCH VFO)", # SWITCH VFO on radio
                   "Switch frequency/memory mode (VFO/MR)", # VFO/MR on radio
                   "Switch demodulation (SWITCH DEMODUL)", # SWITCH DEMODUL on radio
                   "Switch banwidth (SWITCH BANDWID)", # SWITCH BANDWID on radio
                   "Spectrum analyzer (SPECTRUM)" # SPECTRUM on radio
                   ]

MIC_GAIN_LIST = ["+1.1dB","+4.0dB","+8.0dB","+12.0dB","+15.1dB"]

def xorarr(data: bytes):
    """the communication is obfuscated using this fine mechanism"""
    tbl = [22, 108, 20, 230, 46, 145, 13, 64, 33, 53, 213, 64, 19, 3, 233, 128]
    ret = b""
    idx = 0
    for byte in data:
        ret += bytes([byte ^ tbl[idx]])
        idx = (idx+1) % len(tbl)
    return ret


def calculate_crc16_xmodem(data: bytes):
    """
    if this crc was used for communication to AND from the radio, then it
    would be a measure to increase reliability.
    but it's only used towards the radio, so it's for further obfuscation
    """
    poly = 0x1021
    crc = 0x0
    for byte in data:
        crc = crc ^ (byte << 8)
        for _ in range(8):
            crc = crc << 1
            if crc & 0x10000:
                crc = (crc ^ poly) & 0xFFFF
    return crc & 0xFFFF


def _send_command(serport, data: bytes):
    """Send a command to UV-K5 radio"""
    LOG.debug("Sending command (unobfuscated) len=0x%4.4x:\n%s",
              len(data), util.hexprint(data))

    crc = calculate_crc16_xmodem(data)
    data2 = data + struct.pack("<H", crc)

    command = struct.pack(">HBB", 0xabcd, len(data), 0) + \
        xorarr(data2) + \
        struct.pack(">H", 0xdcba)
    if DEBUG_SHOW_OBFUSCATED_COMMANDS:
        LOG.debug("Sending command (obfuscated):\n%s", util.hexprint(command))
    try:
        result = serport.write(command)
    except Exception as e:
        raise errors.RadioError("Error writing data to radio") from e
    return result


def _receive_reply(serport):
    header = serport.read(4)
    if len(header) != 4:
        LOG.warning("Header short read: [%s] len=%i",
                    util.hexprint(header), len(header))
        raise errors.RadioError("Header short read")
    if header[0] != 0xAB or header[1] != 0xCD or header[3] != 0x00:
        LOG.warning("Bad response header: %s len=%i",
                    util.hexprint(header), len(header))
        raise errors.RadioError("Bad response header")

    cmd = serport.read(int(header[2]))
    if len(cmd) != int(header[2]):
        LOG.warning("Body short read: [%s] len=%i",
                    util.hexprint(cmd), len(cmd))
        raise errors.RadioError("Command body short read")

    footer = serport.read(4)

    if len(footer) != 4:
        LOG.warning("Footer short read: [%s] len=%i",
                    util.hexprint(footer), len(footer))
        raise errors.RadioError("Footer short read")

    if footer[2] != 0xDC or footer[3] != 0xBA:
        LOG.debug("Reply before bad response footer (obfuscated)"
                "len=0x%4.4x:\n%s", len(cmd), util.hexprint(cmd))
        LOG.warning("Bad response footer: %s len=%i",
                    util.hexprint(footer), len(footer))
        raise errors.RadioError("Bad response footer")

    if DEBUG_SHOW_OBFUSCATED_COMMANDS:
        LOG.debug("Received reply (obfuscated) len=0x%4.4x:\n%s",
                  len(cmd), util.hexprint(cmd))

    cmd2 = xorarr(cmd)

    LOG.debug("Received reply (unobfuscated) len=0x%4.4x:\n%s",
              len(cmd2), util.hexprint(cmd2))

    return cmd2


def _getstring(data: bytes, begin, maxlen):
    tmplen = min(maxlen+1, len(data))
    ss = [data[i] for i in range(begin, tmplen)]
    key = 0
    for key, val in enumerate(ss):
        if val < ord(' ') or val > ord('~'):
            return ''.join(chr(x) for x in ss[0:key])
    return ''


def _sayhello(serport):
    hellopacket = b"\x14\x05\x04\x00\x6a\x39\x57\x64"

    tries = 5
    while True:
        LOG.debug("Sending hello packet")
        _send_command(serport, hellopacket)
        rep = _receive_reply(serport)
        if rep:
            break
        tries -= 1
        if tries == 0:
            LOG.warning("Failed to initialise radio")
            raise errors.RadioError("Failed to initialize radio")
    if rep.startswith(b'\x18\x05'):
        raise errors.RadioError("Radio is in programming mode, "
                                "restart radio into normal mode")
    firmware = _getstring(rep, 4, 24)

    LOG.info("Found firmware: %s", firmware)
    return firmware


def _readmem(serport, offset, length):
    LOG.debug("Sending readmem offset=0x%4.4x len=0x%4.4x", offset, length)

    readmem = b"\x1b\x05\x08\x00" + \
        struct.pack("<HBB", offset, length, 0) + \
        b"\x6a\x39\x57\x64"
    _send_command(serport, readmem)
    rep = _receive_reply(serport)
    if DEBUG_SHOW_MEMORY_ACTIONS:
        LOG.debug("readmem Received data len=0x%4.4x:\n%s",
                  len(rep), util.hexprint(rep))
    return rep[8:]


def _writemem(serport, data, offset):
    LOG.debug("Sending writemem offset=0x%4.4x len=0x%4.4x",
              offset, len(data))

    if DEBUG_SHOW_MEMORY_ACTIONS:
        LOG.debug("writemem sent data offset=0x%4.4x len=0x%4.4x:\n%s",
                  offset, len(data), util.hexprint(data))

    dlen = len(data)
    writemem = b"\x1d\x05" + \
        struct.pack("<BBHBB", dlen+8, 0, offset, dlen, 1) + \
        b"\x6a\x39\x57\x64"+data

    _send_command(serport, writemem)
    rep = _receive_reply(serport)

    LOG.debug("writemem Received data: %s len=%i", util.hexprint(rep), len(rep))

    if (rep[0] == 0x1e and
        rep[4] == (offset & 0xff) and
        rep[5] == (offset >> 8) & 0xff):
        return True

    LOG.warning("Bad data from writemem")
    raise errors.RadioError("Bad response to writemem")


def _resetradio(serport):
    resetpacket = b"\xdd\x05\x00\x00"
    _send_command(serport, resetpacket)


def do_download(radio):
    """download eeprom from radio"""
    serport = radio.pipe
    serport.timeout = 0.5
    status = chirp_common.Status()
    status.cur = 0
    status.max = MEM_SIZE
    status.msg = "Downloading from radio"
    radio.status_fn(status)

    eeprom = b""
    f = _sayhello(serport)
    if f:
        radio.FIRMWARE_VERSION = f
    else:
        raise errors.RadioError("Failed to initialize radio")

    addr = 0
    while addr < MEM_SIZE:
        data = _readmem(serport, addr, MEM_BLOCK)
        status.cur = addr
        radio.status_fn(status)

        if data and len(data) == MEM_BLOCK:
            eeprom += data
            addr += MEM_BLOCK
        else:
            raise errors.RadioError("Memory download incomplete")

    return memmap.MemoryMapBytes(eeprom)


def do_upload(radio):
    """upload configuration to radio eeprom"""
    serport = radio.pipe
    serport.timeout = 0.5
    status = chirp_common.Status()
    status.cur = 0
    status.msg = "Uploading to radio"
    status.max = PROG_SIZE
    start_addr = 0
    stop_addr = PROG_SIZE

    radio.status_fn(status)

    f = _sayhello(serport)
    if f:
        radio.FIRMWARE_VERSION = f
    else:
        return False

    addr = start_addr
    while addr < stop_addr:
        dat = radio.get_mmap()[addr:addr+MEM_BLOCK]
        _writemem(serport, dat, addr)
        status.cur = addr - start_addr
        radio.status_fn(status)
        if dat:
            addr += MEM_BLOCK
        else:
            raise errors.RadioError("Memory upload incomplete")
    status.msg = "Uploaded OK"

    _resetradio(serport)

    return True


def min_max_def(value, min_val, max_val, default):
    """returns value if in bounds or default otherwise"""
    if min_val is not None and value < min_val:
        return default
    if max_val is not None and value > max_val:
        return default
    return value

def list_def(value, lst, default):
    """return value if is in the list, default otherwise"""
    if isinstance(default, str):
        default = lst.index(default)
    if value < 0 or value >= len(lst):
        return default
    return value

@directory.register
class UVK5Radio(chirp_common.CloneModeRadio):
    """Quansheng UV-K5"""
    VENDOR = "Quansheng"
    MODEL = "UV-K5 ROBZYL 512K"
    BAUD_RATE = 38400
    NEEDS_COMPAT_SERIAL = False
    FIRMWARE_VERSION = ""
    
    def _find_band(self, hz):
        mhz = hz/1000000.0
        bands = BANDS_WIDE 
        for bnd, rng in bands.items():
            if rng[0] <= mhz <= rng[1]:
                return bnd
        return True

    @classmethod
    def get_prompts(cls):
        rp = chirp_common.RadioPrompts()
        rp.experimental = \
            _('This is an experimental driver for the Quansheng UV-K5. '
             'It may harm your radio, or worse. Use at your own risk.\n\n'
             'Before attempting to do any changes please download'
             'the memory image from the radio with chirp '
             'and keep it. This can be later used to recover the '
             'original settings. \n\n'
             'some details are not yet implemented')
        rp.pre_download = _(
            "1. Turn radio on.\n"
            "2. Connect cable to mic/spkr connector.\n"
            "3. Make sure connector is firmly connected.\n"
            "4. Click OK to download image from device.\n\n"
            "It may not work if you turn on the radio "
            "with the cable already attached\n")
        rp.pre_upload = _(
            "1. Turn radio on.\n"
            "2. Connect cable to mic/spkr connector.\n"
            "3. Make sure connector is firmly connected.\n"
            "4. Click OK to upload the image to device.\n\n"
            "It may not work if you turn on the radio "
            "with the cable already attached")
        return rp

    # Return information about this radio's features, including
    # how many memories it has, what bands it supports, etc
    def get_features(self):
        rf = chirp_common.RadioFeatures()
        rf.has_bank = False
        rf.valid_dtcs_codes = DTCS_CODES
        rf.has_rx_dtcs = True
        rf.has_ctone = True
        rf.has_comment = False
        rf.valid_name_length = 10
        rf.valid_power_levels = UVK5_POWER_LEVELS
        rf.valid_duplexes = ["", "-", "+", "off"]

        steps = STEPS.copy()
        steps.sort()
        rf.valid_tuning_steps = steps

        rf.valid_tmodes = ["", "Tone", "TSQL", "DTCS", "Cross"]
        rf.valid_cross_modes = ["Tone->Tone", "Tone->DTCS", "DTCS->Tone",
                                "->Tone", "->DTCS", "DTCS->", "DTCS->DTCS"]

        rf.valid_characters = chirp_common.CHARSET_ASCII
        rf.valid_modes = ["FM", "NFM", "AM", "NAM", "AIR", "USB"]

        rf.valid_skips = [""]

        rf.memory_bounds = (1, 999)
        # This is what the BK4819 chip supports
        # Will leave it in a comment, might be useful someday
        rf.valid_bands = [(14000000,  630000000),
                          (760000000, 1300000000)
                         ]
        rf.valid_bands = []
        bands = BANDS_WIDE
        for _, rng in bands.items():
            rf.valid_bands.append(
                    (int(rng[0]*1000000), int(rng[1]*1000000)))
        return rf

    # Do a download of the radio from the serial port
    def sync_in(self):
        self._mmap = do_download(self)
        self.process_mmap()

    # Do an upload of the radio to the serial port
    def sync_out(self):
        do_upload(self)

    # Convert the raw byte array into a memory object structure
    def process_mmap(self):
        self._memobj = bitwise.parse(MEM_FORMAT, self._mmap)

    # Return a raw representation of the memory object, which
    # is very helpful for development
    def get_raw_memory(self, number):
        return repr(self._memobj.Channel[number-1])

    def validate_memory(self, mem):
        msgs = super().validate_memory(mem)

        if mem.duplex == 'off':
            return msgs

        # find tx frequency
        if mem.duplex == '-':
            txfreq = mem.freq - mem.offset
        elif mem.duplex == '+':
            txfreq = mem.freq + mem.offset
        else:
            txfreq = mem.freq
        # find band
        band = self._find_band(txfreq)
        if band is False:
            msg = f"Transmit frequency {txfreq/1000000.0:.4f}MHz " \
                   "is not supported by this radio"
            msgs.append(chirp_common.ValidationWarning(msg))

        band = self._find_band(mem.freq)
        if band is False:
            msg = f"The frequency {mem.freq/1000000.0:.4f} MHz " \
                   "is not supported by this radio"
            msgs.append(chirp_common.ValidationWarning(msg))

        return msgs

    def _set_tone(self, mem, _mem):
        ((txmode, txtone, txpol),
         (rxmode, rxtone, rxpol)) = chirp_common.split_tone_encode(mem)

        if txmode == "Tone":
            txtoval = CTCSS_TONES.index(txtone)
            txmoval = 0b01
        elif txmode == "DTCS":
            txmoval = txpol == "R" and 0b11 or 0b10
            txtoval = DTCS_CODES.index(txtone)
        else:
            txmoval = 0
            txtoval = 0

        if rxmode == "Tone":
            rxtoval = CTCSS_TONES.index(rxtone)
            rxmoval = 0b01
        elif rxmode == "DTCS":
            rxmoval = rxpol == "R" and 0b11 or 0b10
            rxtoval = DTCS_CODES.index(rxtone)
        else:
            rxmoval = 0
            rxtoval = 0

        _mem.rxcodeflag = rxmoval
        _mem.txcodeflag = txmoval
        _mem.rxcode = rxtoval
        _mem.txcode = txtoval

    def _get_tone(self, mem, _mem):
        rxtype = int(_mem.rxcodeflag)
        if rxtype >= len(TMODES):
            rxtype = 0
        rx_tmode = TMODES[rxtype]
        txtype = int(_mem.txcodeflag)
        if txtype >= len(TMODES):
            txtype = 0
        tx_tmode = TMODES[txtype]

        rx_tone = tx_tone = None

        if tx_tmode == "Tone":
            if _mem.txcode < len(CTCSS_TONES):
                tx_tone = CTCSS_TONES[_mem.txcode]
            else:
                tx_tone = 0
                tx_tmode = ""
        elif tx_tmode == "DTCS":
            if _mem.txcode < len(DTCS_CODES):
                tx_tone = DTCS_CODES[_mem.txcode]
            else:
                tx_tone = 0
                tx_tmode = ""

        if rx_tmode == "Tone":
            if _mem.rxcode < len(CTCSS_TONES):
                rx_tone = CTCSS_TONES[_mem.rxcode]
            else:
                rx_tone = 0
                rx_tmode = ""
        elif rx_tmode == "DTCS":
            if _mem.rxcode < len(DTCS_CODES):
                rx_tone = DTCS_CODES[_mem.rxcode]
            else:
                rx_tone = 0
                rx_tmode = ""

        tx_pol = txtype == 0x03 and "R" or "N"
        rx_pol = rxtype == 0x03 and "R" or "N"

        chirp_common.split_tone_decode(mem, (tx_tmode, tx_tone, tx_pol),
                                       (rx_tmode, rx_tone, rx_pol))

    # Extract a high-level memory object from the low-level memory map
    # This is called to populate a memory in the UI
    def get_memory(self, number):

        mem = chirp_common.Memory()

        if isinstance(number, str):
            ch_num = self._get_specials()[number]
            mem.extd_number = number
        else:
            ch_num = number - 1

        mem.number = ch_num + 1

        _mem = self._memobj.Channel[ch_num]

        is_empty = False
        # We'll consider any blank (i.e. 0MHz frequency) to be empty
        if (_mem.freq == 0xffffffff) or (_mem.freq == 0):
            is_empty = True

        # We'll also look at the Channel attributes if a memory has them
        tmpscn = SCANLIST_LIST[0]

        if ch_num < 999:
            _mem3 = self._memobj.ch_attr[ch_num]
            # scanlists
            temp_val = _mem3.scanlist
            tmpscn = SCANLIST_LIST[temp_val]

        if is_empty:
            mem.empty = True
            # set some sane defaults:
            mem.power = UVK5_POWER_LEVELS[2]
            mem.extra = RadioSettingGroup("Extra", "extra")

            val = RadioSettingValueBoolean(False)
            rs = RadioSetting("busyChLockout", "BusyCL", val)
            mem.extra.append(rs)

            val = RadioSettingValueBoolean(False)
            rs = RadioSetting("frev", "FreqRev", val)
            mem.extra.append(rs)

            val = RadioSettingValueList(SCRAMBLER_LIST)
            rs = RadioSetting("scrambler", "Scrambler", val)
            mem.extra.append(rs)

            val = RadioSettingValueList(SCANLIST_LIST)
            rs = RadioSetting("scanlist", "Scanlist", val)
            mem.extra.append(rs)

            # actually the step and duplex are overwritten by chirp based on
            # bandplan. they are here to document sane defaults for IARU r1
            # mem.tuning_step = 25.0
            # mem.duplex = "off"

            return mem

        _mem2 = self._memobj.Channelname[ch_num]
        for char in _mem2.name:
            if str(char) == "\xFF" or str(char) == "\x00":
                break
            mem.name += str(char)
        mem.name = mem.name.rstrip()

        # Convert your low-level frequency to Hertz
        mem.freq = int(_mem.freq)*10
        mem.offset = int(_mem.offset)*10

        if mem.offset == 0:
            mem.duplex = ''
        else:
            if _mem.offsetDir == FLAGS1_OFFSET_MINUS:
                if _mem.freq == _mem.offset:
                    # fake tx disable by setting tx to 0 MHz
                    mem.duplex = 'off'
                    mem.offset = 0
                else:
                    mem.duplex = '-'
            elif _mem.offsetDir == FLAGS1_OFFSET_PLUS:
                mem.duplex = '+'
            else:
                mem.duplex = ''

        # tone data
        self._get_tone(mem, _mem)

        # mode
        temp_modes = self.get_features().valid_modes
        mode_map = {
            0: {
                0: 0,
                1: 1
            },
            1: {
                0: 2,
                1: 3,
                2: 4
            },
            2: {
                1: 5
            }
        }

        temp_bandwidth = int(_mem.bandwidth)
        if temp_bandwidth == 1:
            temp_bandwidth = int(_mem.bandwidth_ext) + 1

        try:
            mem.mode = temp_modes[mode_map[int(_mem.modulation)][temp_bandwidth]]
        except KeyError:
            mem.mode = temp_modes[0]

        # tuning step
        tstep = _mem.step
        if tstep < len(STEPS):
            mem.tuning_step = STEPS[tstep]
        else:
            mem.tuning_step = 2.5

        # power
        if _mem.txpower == POWER_HIGH:
            mem.power = UVK5_POWER_LEVELS[2]
        elif _mem.txpower == POWER_MEDIUM:
            mem.power = UVK5_POWER_LEVELS[1]
        else:
            mem.power = UVK5_POWER_LEVELS[0]

        # We'll consider any blank (i.e. 0MHz frequency) to be empty
        if (_mem.freq == 0xffffffff) or (_mem.freq == 0):
            mem.empty = True
        else:
            mem.empty = False

        mem.extra = RadioSettingGroup("Extra", "extra")

        # BusyCL
        val = RadioSettingValueBoolean(_mem.busyChLockout)
        rs = RadioSetting("busyChLockout", "Busy Ch Lockout    (BusyCL)", val)
        mem.extra.append(rs)

        # Frequency reverse
        val = RadioSettingValueBoolean(_mem.freq_reverse)
        rs = RadioSetting("frev", "Reverse Frequencies (R)", val)
        mem.extra.append(rs)

        # Scrambler
        enc = list_def(_mem.scrambler, SCRAMBLER_LIST, 0)
        val = RadioSettingValueList(SCRAMBLER_LIST, None, enc)
        rs = RadioSetting("scrambler", "Scrambler (Scramb)", val)
        mem.extra.append(rs)

        # Scanlist
        val = RadioSettingValueList(SCANLIST_LIST, tmpscn)
        rs = RadioSetting("scanlist", "Scanlist (SList)", val)
        mem.extra.append(rs)

        return mem

    def set_memory(self, memory):
        """
        Store details about a high-level memory to the memory map
        This is called when a user edits a memory in the UI
        """
        number = memory.number-1

        # Get a low-level memory object mapped to the image
        _mem = self._memobj.Channel[number]
        _mem4 = self._memobj.ch_attr[number]
        # empty memory
        if memory.empty:
            _mem.set_raw("\xFF" * 16)
            _mem2 = self._memobj.Channelname[number]
            _mem2.set_raw("\xFF" * 16)
            _mem4.scanlist = 0
            
            _mem4.band = 0xF
            return memory

        
        _mem4.scanlist = 0
        _mem4.band = 0xF

        # mode ["FM", "NFM", "AM", "NAM", "AIR", "USB"]
        # 0 = FM, 1 = AM, 2 = USB
        _mem.bandwidth_ext = 0
        if memory.mode == "FM":
            _mem.modulation = 0
            _mem.bandwidth = 0
        elif memory.mode == "NFM":
            _mem.modulation = 0
            _mem.bandwidth = 1
        elif memory.mode == "AM":
            _mem.modulation = 1
            _mem.bandwidth = 0
        elif memory.mode == "NAM":
            _mem.modulation = 1
            _mem.bandwidth = 1
        elif memory.mode == "AIR":
            _mem.modulation = 1
            _mem.bandwidth = 1
            _mem.bandwidth_ext = 1
        elif memory.mode == "USB":
            _mem.modulation = 2
            _mem.bandwidth = 1

        # frequency/offset
        _mem.freq = memory.freq/10
        _mem.offset = memory.offset/10

        if memory.duplex == "":
            _mem.offset = 0
            _mem.offsetDir = 0
        elif memory.duplex == '-':
            _mem.offsetDir = FLAGS1_OFFSET_MINUS
        elif memory.duplex == '+':
            _mem.offsetDir = FLAGS1_OFFSET_PLUS
        elif memory.duplex == 'off':
            # we fake tx disable by setting the tx freq to 0 MHz
            _mem.offsetDir = FLAGS1_OFFSET_MINUS
            _mem.offset = _mem.freq
        # set band
        band = self._find_band(_mem.freq)
        _mem4.band = band

        _mem2 = self._memobj.Channelname[number]
        tag = memory.name.ljust(10) + "\x00"*6
        _mem2.name = tag  # Store the alpha tag

        # tone data
        self._set_tone(memory, _mem)

        # step
        _mem.step = STEPS.index(memory.tuning_step)

        # tx power
        if str(memory.power) == str(UVK5_POWER_LEVELS[2]):
            _mem.txpower = POWER_HIGH
        elif str(memory.power) == str(UVK5_POWER_LEVELS[1]):
            _mem.txpower = POWER_MEDIUM
        else:
            _mem.txpower = POWER_LOW


        ######### EXTRA SETTINGS

        def get_setting(name, def_val):
            if name in memory.extra:
                return int(memory.extra[name].value)
            return def_val

        _mem.busyChLockout = get_setting("busyChLockout", False)
        _mem.freq_reverse = get_setting("frev", False)
        _mem.scrambler = get_setting("scrambler", 0)
        tmp_val = get_setting("scanlist", 0)
        _mem4.scanlist = tmp_val

        return memory
