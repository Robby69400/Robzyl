/* 
  Frequencies are 10Hz: 100M is written 10000000
  Max bandname length is 11
  AVAILABLE STEPS ARE 
  S_STEP_0_01kHz,
  S_STEP_0_1kHz,
  S_STEP_0_5kHz,
  S_STEP_1_0kHz,
  S_STEP_2_5kHz,
  S_STEP_5_0kHz,
  S_STEP_6_25kHz,
  S_STEP_8_33kHz,
  S_STEP_10_0kHz,
  S_STEP_12_5kHz,
  S_STEP_25_0kHz,
  S_STEP_100kHz,
  S_STEP_500kHz, */


#ifdef ENABLE_FI_BAND
static const bandparameters BParams[32] = {
    // BandName        Startfrequency    Stopfrequency    scanStep           modulationType
    {"PMR446",         44600625,         44619375,        S_STEP_12_5kHz,    MODULATION_FM},
    {"CB40",           2696500,          2740500,         S_STEP_10_0kHz,    MODULATION_AM},
    {"RHA68",          6750000,          7232500,         S_STEP_25_0kHz,    MODULATION_FM},
    {"MARINE",         15550000,         16215000,        S_STEP_25_0kHz,    MODULATION_FM},
    {"AIR",            11800000,         13700000,        S_STEP_8_33kHz,    MODULATION_AM},
    {"MIL 1",          13800000,         14400000,        S_STEP_25_0kHz,    MODULATION_AM},
    {"MIL 2",          22500000,         32800000,        S_STEP_25_0kHz,    MODULATION_AM},
    {"MIL 3",          33600000,         37800000,        S_STEP_25_0kHz,    MODULATION_AM},
    {"17M USB",        1811000,          1816800,         S_STEP_1_0kHz,     MODULATION_SSB},
    {"15M USB",        2115000,          2145000,         S_STEP_1_0kHz,     MODULATION_SSB},
    {"12M USB",        2493100,          2499000,         S_STEP_1_0kHz,     MODULATION_SSB},
    {"11M AM",         2651500,          2830500,         S_STEP_5_0kHz,     MODULATION_AM}, 
    {"10M USB",        2832000,          2910000,         S_STEP_1_0kHz,     MODULATION_SSB}, 
    {"10M FM",         2910000,          16202500,        S_STEP_1_0kHz,     MODULATION_FM},
    {"6M FM",          5010000,          5200000,         S_STEP_10_0kHz,    MODULATION_FM},
    {"4M USB",         7010000,          7025000,         S_STEP_12_5kHz,    MODULATION_SSB},
    {"4M FM",          7025000,          7030000,         S_STEP_12_5kHz,    MODULATION_FM},
    {"2M FM",          14400000,         14600000,        S_STEP_12_5kHz,    MODULATION_FM},
    {"70cm FM",        43250000,         43498100,        S_STEP_12_5kHz,    MODULATION_FM},
    {"FM 29-47",       2971000,          4699000,         S_STEP_5_0kHz,     MODULATION_FM},
    {"FM 68-74",       675000,           7480000,         S_STEP_25_0kHz,    MODULATION_FM},
    {"FM 75-87",       752000,           8747500,         S_STEP_25_0kHz,    MODULATION_FM},
    {"FM 146-155",     14600000,         15550000,        S_STEP_12_5kHz,    MODULATION_FM},
    {"FM 162-174",     16205000,         17400000,        S_STEP_25_0kHz,    MODULATION_FM},
    {"FM 406-429",     40610000,         42952500,        S_STEP_12_5kHz,    MODULATION_FM},
    {"FM 440-447",     44001250,         44770625,        S_STEP_12_5kHz,    MODULATION_FM},
    {"FM 450-470",     45032500,         47000000,        S_STEP_25_0kHz,    MODULATION_FM},
    {"Jakt31 SE",      3093000,          3137000,         S_STEP_10_0kHz,    MODULATION_FM},
    {"CB69 SE",        6901250,          6971875,         S_STEP_12_5kHz,    MODULATION_FM},
    {"Jakt155 SE",     15540000,         1560000,         S_STEP_25_0kHz,    MODULATION_FM},
    {"KDR444 SE",      44460000,         44497500,        S_STEP_25_0kHz,    MODULATION_FM},
    {"FULL",           1400000,          130000000,       S_STEP_500kHz,   MODULATION_AM}
}; 
#endif


#ifdef ENABLE_IN_BAND
static const bandparameters BParams[32] = {
    // BandName       Startfrequency    Stopfrequency   scanStep          modulationType
    {"AIR 8.33k",     11800000,         13700000,       S_STEP_8_33kHz,   MODULATION_AM},
    {"AIR MIL1",      13800000,         14400000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR MIL2",      22500000,         24107500,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR MIL3",      33540000,         33970000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"PMR 446",       44600625,         44619375,       S_STEP_12_5kHz,   MODULATION_FM},
    {"FRS",           46256250,         46772500,       S_STEP_5_0kHz,    MODULATION_FM},
    {"MARINE",        15550000,         16202500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"CB",             2651500,          2830500,       S_STEP_5_0kHz,    MODULATION_AM},
    }; 
#endif

#ifdef ENABLE_BR_BAND
static const bandparameters BParams[32] = {
    // BandName       Startfrequency    Stopfrequency     scanStep          modulationType
    {"CB (27MHz)",         2696500,         2740500,      S_STEP_10_0kHz,   MODULATION_FM},
    {"6M (50MHz)",         5000000,         5400000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"FM 88-108MHz",       8800000,        10800000,      S_STEP_100kHz,    MODULATION_FM},  
    {"2M (144MHz)",       14400000,        14800000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"AIR VHF",           11800000,        13700000,      S_STEP_25_0kHz,   MODULATION_AM},
    {"MARINE VHF",        15600000,        16200000,      S_STEP_25_0kHz,   MODULATION_FM},
    {"PUBLIC SAFE",     15000000,        15600000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"70cm 430MHz",     43000000,        44000000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"UHF 400-470",       40000000,        47000000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"LPD 433",           43305000,        43479000,      S_STEP_25_0kHz,   MODULATION_FM},
    {"PMR 446",           44600625,        44620000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"TAXI UHF",          45000000,        46000000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"PABX",              45700000,        45800000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"RADIO TAXI",        46000000,        46200000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"SECURITY",          46600000,        46800000,      S_STEP_12_5kHz,   MODULATION_FM},
    {"AIR UHF",           22500000,        40000000,      S_STEP_25_0kHz,   MODULATION_AM},
    {"EMERGMARINE",      15550000,        15550000,      S_STEP_25_0kHz,   MODULATION_FM},  
    {"EMERG AIR",         12150000,        12150000,      S_STEP_8_33kHz,   MODULATION_AM},  
    {"EMERGAIRUHF",     24300000,        24300000,      S_STEP_25_0kHz,   MODULATION_AM},  
    {"SAT 2m DOWN",       14580000,        14600000,      S_STEP_25_0kHz,   MODULATION_FM},
    {"SAT70cmDOWN",     43500000,        43800000,      S_STEP_25_0kHz,   MODULATION_FM},
    {"WWV 10MHz",          1000000,         1000000,      S_STEP_25_0kHz,   MODULATION_AM},
    {"CHU 7.85MHz",         785000,          785000,      S_STEP_25_0kHz,   MODULATION_AM},
    }; 
#endif

#ifdef ENABLE_FR_BAND
static const bandparameters BParams[32] = {
    // BandName       Startfrequency    Stopfrequency   scanStep          modulationType
    {"AIR 8.33k",     11800000,         13700000,       S_STEP_8_33kHz,   MODULATION_AM},
    {"HAM 144M",      14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"HAM 430M",      43000000,         44000000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"AIR MIL1",      13800000,         14400000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR MIL2",      22500000,         24107500,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR MIL3",      33540000,         33970000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"PMR 446",       44600625,         44619375,       S_STEP_12_5kHz,   MODULATION_FM},
    {"PMR 446b",      44600000,         44620000,       S_STEP_6_25kHz,   MODULATION_FM},
    {"FREENET",       14902500,         14911250,       S_STEP_12_5kHz,   MODULATION_FM},
    {"DMR VHF",       14600000,         17000000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"DMR UHF1",      45000000,         46600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"DMR UHF2",      46620000,         47000000,       S_STEP_12_5kHz,   MODULATION_FM}, //Pocsag FR removed 466-466.2
    {"REMOTE CT",     43200000,         43400000,       S_STEP_0_5kHz,    MODULATION_FM}, //Remote control search
    {"MARINE",        15550000,         16202500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"CB40",           2696500,          2740500,       S_STEP_10_0kHz,   MODULATION_AM},
    {"CB",             2651500,          2830500,       S_STEP_5_0kHz,    MODULATION_AM},
    {"SRD868",        86800000,         87000000,       S_STEP_6_25kHz,   MODULATION_FM},
    {"LPD433",        43307500,         43377500,       S_STEP_6_25kHz,   MODULATION_FM},
    {"14MHz",          1400000,          1430000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"17MHz",          1740000,          1780000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"18MHz",          1806800,          1816800,       S_STEP_1_0kHz,    MODULATION_AM},
    {"21MHz",          2100000,          2145000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"24MHz",          2489000,          2499000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"HAM 28MHz",      2800000,          2970000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"HAM 50MHz",      5000000,          5200000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"70 Mhz",         7000000,          7050000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"220Mhz",        22000000,         22500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"1240MHz",      124000000,        130000000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"SATCOM",        24000000,         27500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"AIR 25k",       11800000,         13700000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"FULL",           1400000,        130000000,        S_STEP_500kHz,   MODULATION_FM},
    {"NOT USED",      40000000,         50000000,        S_STEP_100kHz,   MODULATION_FM}
    }; 
#endif

#ifdef ENABLE_PL_BAND
static const bandparameters BParams[32] = {
    // BandName       Startfrequency    Stopfrequency   scanStep        modulationType
    {"HAM 144",       14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"HAM 430",       43000000,         44000000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"AIR 25k",       11800000,         13600000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR 8.33k",     11800000,         13600000,       S_STEP_8_33kHz,   MODULATION_AM},
    {"DMR-VHF",       14600000,         17000000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"DMR-UHF1",      45000000,         46600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"DMR-UHF2",      46620000,         47000000,       S_STEP_12_5kHz,   MODULATION_FM}, //Pocsag FR removed 466-466.2
    {"50-52MHz",       5000000,          5256000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"Remote433",     43200000,         43400000,       S_STEP_0_5kHz,    MODULATION_FM}, //Remote control search
    {"LPD433",        43307500,         43377500,       S_STEP_6_25kHz,   MODULATION_FM},
    {"SRD868",        86800000,         87000000,       S_STEP_6_25kHz,   MODULATION_FM},
    {"SATCOM",        24000000,         27500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"14MHz",          1400000,          1430000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"17MHz",          1740000,          1780000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"18MHz",          1806800,          1816800,       S_STEP_1_0kHz,    MODULATION_AM},
    {"21MHz",          2100000,          2145000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"24MHz",          2489000,          2499000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"CB",             2651500,          2830500,       S_STEP_5_0kHz,    MODULATION_AM},
    {"28MHz",          2800000,          2970000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"50-52MHz",       5000000,          5200000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"70 Mhz",         7000000,          7050000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"144 Mhz",       14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"220Mhz",        22000000,         22500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"430 Mhz",       43000000,         44000000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"1240MHz",      124000000,        130000000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"PKP FAST",      15050000,         15197500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"PKP MAX",       15000000,         15600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"CB PL",          2696000,          2740000,       S_STEP_10_0kHz,   MODULATION_AM},
    {"POGOTOWIE",     16852500,         16937500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"POLICJA",       17200000,         17397500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"PSP",           14866250,         14933750,       S_STEP_25_0kHz,   MODULATION_FM},
    {"MARINE",        15550000,         16202500,       S_STEP_25_0kHz,   MODULATION_FM}
    }; 
#endif

#ifdef ENABLE_RO_BAND
static const bandparameters BParams[32] = {
// BandName Startfrequency Stopfrequency scanStep modulationType
    {"20M",           1400000,           1435000,       S_STEP_1_0kHz,   MODULATION_AM},
    {"17M",           1806800,           1816800,       S_STEP_1_0kHz,   MODULATION_AM},
    {"15M",           2100000,           2145000,       S_STEP_1_0kHz,   MODULATION_AM},
    {"12M",           2489000,           2499000,       S_STEP_1_0kHz,   MODULATION_AM},
    {"10M",           2800000,           2970000,       S_STEP_1_0kHz,   MODULATION_AM},
    {"6M",            5000000,           5200000,       S_STEP_10_0kHz,  MODULATION_FM},
    {"2M",           14400000,          14600000,       S_STEP_12_5kHz,  MODULATION_FM},
    {"70CM",         43000000,          44000000,       S_STEP_10_0kHz,  MODULATION_FM},
    {"TAXI",         46000000,          47000000,       S_STEP_12_5kHz,  MODULATION_FM}, // Banda taxi UHF
    {"CB",            2696500,           2740500,       S_STEP_10_0kHz,  MODULATION_FM},
    {"AIR 25kHz",    11800000,          13700000,       S_STEP_25_0kHz,  MODULATION_AM},
    {"AIR 8.33kHz",  11800000,          13700000,       S_STEP_8_33kHz,  MODULATION_AM},
    {"AMBULANTA",    16920000,          16937500,       S_STEP_25_0kHz,  MODULATION_FM},
    {"POLITIA",      17200000,          17397500,       S_STEP_25_0kHz,  MODULATION_FM},
    {"POMPIERI",     14866250,          14933750,       S_STEP_25_0kHz,  MODULATION_FM}
    };          
#endif

#ifdef ENABLE_KO_BAND
static const bandparameters BParams[32] = {
    // BandName       Startfrequency    Stopfrequency   scanStep          modulationType
    {"AIR 25k",       11800000,         13600000,       S_STEP_25_0kHz,   MODULATION_AM},
	{"SATCOM",        24000000,         27000000,       S_STEP_10_0kHz,   MODULATION_FM},
	{"HAM 144",      14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
	{"136-144",      13600000,         14400000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"146-150",      14600000,         15000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"RAIL",          15000000,         15550000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"LPD433",        43307500,         43377500,       S_STEP_6_25kHz,   MODULATION_FM},
	{"PMR 446",       44600625,         44619375,       S_STEP_12_5kHz,   MODULATION_FM},
	{"HAM 430",      43000000,         44000000,       S_STEP_12_5kHz,   MODULATION_FM},
	{"VHF-H",         16200000,         17000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"VHF-H1",        17000000,         17400000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"PMR 446d",      44600312,         44619687,       S_STEP_6_25kHz,   MODULATION_FM},
    {"UHF400",        40000000,         42000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"UHF420",        42000000,         43300000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"UHF440",        44000000,         45500000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"UHF455",        45500000,         47000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"Meteo_sondy",   40300000,         40400000,       S_STEP_12_5kHz,   MODULATION_FM},
	{"REMOTE433",     43200000,         43400000,       S_STEP_5_0kHz,    MODULATION_FM}, //Remote control search
    {"AIR MIL1",      22500000,         24107500,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR MIL2",      33540000,         33970000,       S_STEP_25_0kHz,   MODULATION_AM},
	{"SATWX_137",     13700000,         13800000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"MARINE",        15550000,         16202500,       S_STEP_25_0kHz,   MODULATION_FM},
	{"FULL",           1700000,        130000000,        S_STEP_500kHz,   MODULATION_FM},
	{"24MHz",          2489000,          2499000,       S_STEP_5_0kHz,    MODULATION_AM},
	{"21MHz",          2100000,          2145000,       S_STEP_5_0kHz,    MODULATION_AM},
	{"18MHz",          1806800,          1816800,       S_STEP_5_0kHz,    MODULATION_AM},
	{"17MHz",          1740000,          1780000,       S_STEP_5_0kHz,    MODULATION_AM},
	{"28MHz",        2800000,           2970000,       S_STEP_5_0kHz,    MODULATION_SSB},
	{"CB_27",          2651500,          2800000,       S_STEP_5_0kHz,    MODULATION_SSB},
	{"CB_135",         2700000,          2714000,       S_STEP_5_0kHz,    MODULATION_AM},
    }; 
#endif

#ifdef ENABLE_CZ_BAND
static const bandparameters BParams[32] = {
    // BandName         Startfrequency    Stopfrequency    scanStep          modulationType
    {"AIR 8.33k",        11800000,         13700000,       S_STEP_8_33kHz,   MODULATION_AM},
    {"MIL AIR",          22500000,         40000000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"SATCOM",           24000000,         27500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"HAM 80m USB",       3500000,          3800000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 40m USB",       7000000,          7200000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 30m USB",      10100000,         10150000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 20m USB",      14000000,         14350000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 17m USB",      18068000,         18168000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 15m USB",      21000000,         21450000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 12m USB",      24890000,         24990000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"HAM 10m FM",       29000000,         29700000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"HAM 6m FM",        5000000,          5200000,        S_STEP_10_0kHz,   MODULATION_FM},
    {"CB FM",            2696500,          2740500,        S_STEP_10_0kHz,   MODULATION_FM},
    {"PMR 446",          44600625,         44619375,       S_STEP_12_5kHz,   MODULATION_FM},
    {"LPD 433",          43307500,         43477500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"HAM 2m",          14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"HAM 70cm",        43000000,         44000000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"HAM APRS",        14480000,         14480000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"SAT WX 137",      13700000,         13800000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Meteo sondy",     40300000,         40400000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"IZS analog",      16500000,         17400000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Vlaky",           15000000,         15300000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"MHD dispecin",    16000000,         17000000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Taxi VHF",        15400000,         16000000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Taxi UHF",        46000000,         46500000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Ostraha UHF",     44640000,         44660000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Stavby UHF",      44800000,         44900000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"Stavby VHF",      16940000,         16980000,       S_STEP_12_5kHz,   MODULATION_FM},

    {"VOLMET USB",       5505000,         11233000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"Digital stn",      9250000,          9350000,       S_STEP_2_5kHz,    MODULATION_SSB},
    {"Marine USB",       8414000,          8815000,       S_STEP_2_5kHz,    MODULATION_SSB}
};
#endif

#ifdef ENABLE_TU_BAND
static const bandparameters BParams[32] = {
    // BandName         Startfrequency    Stopfrequency    scanStep          modulationType
    {"PMR",              44600000,         44670000,       S_STEP_2_5kHz,   MODULATION_FM},
    {"CB",               43900000,         44000000,       S_STEP_2_5kHz,   MODULATION_AM},
    {"AIR",              11800000,         13800000,       S_STEP_2_5kHz,   MODULATION_AM},
   
};
#endif

#ifdef ENABLE_RU_BAND
static const bandparameters BParams[32] = {
    // BandName         Startfrequency    Stopfrequency    scanStep          modulationType
    {"20M (14MHz)",    1400000,          1435000,       S_STEP_5_0kHz,    MODULATION_SSB},
    {"17M (18MHz)",    1806800,          1816800,       S_STEP_5_0kHz,    MODULATION_SSB},
    {"15M (21MHz)",    2100000,          2145000,       S_STEP_1_0kHz,    MODULATION_SSB},
    {"12M (24MHz)",    2489000,          2499000,       S_STEP_1_0kHz,    MODULATION_SSB},
    {"CB (27MHz)",     2651500,          2830500,       S_STEP_5_0kHz,    MODULATION_FM},
    {"10M (28MHz)",    2800000,          2970000,       S_STEP_1_0kHz,    MODULATION_AM},
    {"LB (43MHz)",     4330000,          4358750,       S_STEP_10_0kHz,   MODULATION_FM},
    {"5M(50MHz)",      5000000,          5400000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"5M+(57MHz)",     5700000,          5750000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"AIR",           11800000,         13790000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"136-144MHz",    13600000,         14400000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"2M (145MHz)",   14400000,         14650000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"2M (146MHz)",   14660000,         14790000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"SECURITY",      14800000,         14900000,       S_STEP_5_0kHz,    MODULATION_FM},
    {"RAIL",          15172500,         15600000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"MARINE",        15600000,         16327500,       S_STEP_25_0kHz,   MODULATION_FM},
    {"VHF(162MHz)",   16200000,         17000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"VHF(170MHz)",   17000000,         17400000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"SATCOM-L",      24000000,         25000000,       S_STEP_5_0kHz,    MODULATION_FM},
    {"SATCOM-H",      25050000,         27000000,       S_STEP_5_0kHz,    MODULATION_FM},
    {"RIVER",         30002500,         30051250,       S_STEP_5_0kHz,    MODULATION_FM},
    {"ARMY",          30051300,         33600000,       S_STEP_5_0kHz,    MODULATION_FM},
    {"RIVER",         33601250,         34000050,       S_STEP_5_0kHz,    MODULATION_FM},
    {"LTE",           36000000,         38000000,       S_STEP_5_0kHz,    MODULATION_FM},
    {"UHF400",        40000000,         43300000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"LPD 433",       43307500,         43480000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"PMR 446",       44600625,         44619375,       S_STEP_12_5kHz,   MODULATION_FM},
    {"450MHz",        44700625,         45900000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"GOV 460MHz",    46000000,         46200000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"LORA ",         86400000,         86900000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"GSM900",        89000000,         91500000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"GSM900",        93500000,         96000000,       S_STEP_12_5kHz,   MODULATION_FM},
};
#endif
