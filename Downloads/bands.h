#ifdef ENABLE_FR_BAND
static const bandparameters BParams[32] = {
    // BandName       Startfrequency    Stopfrequency   scanStep          modulationType
    {"AIR 8.33k",     11800000,         13700000,       S_STEP_8_33kHz,   MODULATION_AM},
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
    {"HAM 144M",      14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"220Mhz",        22000000,         22500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"HAM 430M",      43000000,         44000000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"1240MHz",      124000000,        130000000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"SATCOM",        24000000,         27500000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"AIR 25k",       11800000,         13700000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"NOT USED",       1400000,        130000000,        S_STEP_500kHz,   MODULATION_FM},
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
    {"AIR MIL1",      22500000,         24107500,       S_STEP_25_0kHz,   MODULATION_AM},
    {"AIR MIL2",      33540000,         33970000,       S_STEP_25_0kHz,   MODULATION_AM},
    {"LPD433",        43307500,         43377500,       S_STEP_6_25kHz,   MODULATION_FM},
	{"PMR 446",       44600625,         44619375,       S_STEP_12_5kHz,   MODULATION_FM},
    {"PMR 446b",      44600000,         44620000,       S_STEP_6_25kHz,   MODULATION_FM},
    {"136-144",      13600000,         14400000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"HAM 144",      14400000,         14600000,       S_STEP_12_5kHz,   MODULATION_FM},
	{"146-150",      14400000,         14600000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"HAM 430",      43000000,         44000000,       S_STEP_10_0kHz,   MODULATION_FM},
	{"REMOTE433",     43200000,         43400000,       S_STEP_5_0kHz,    MODULATION_FM}, //Remote control search
	{"RAIL",          15000000,         15550000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"MARINE",        15550000,         16202500,       S_STEP_25_0kHz,   MODULATION_FM},
	{"VHF-H",         16200000,         17000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"VHF-H1",        17000000,         17400000,       S_STEP_25_0kHz,   MODULATION_FM},
    {"17MHz",          1740000,          1780000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"18MHz",          1806800,          1816800,       S_STEP_5_0kHz,    MODULATION_AM},
    {"21MHz",          2100000,          2145000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"24MHz",          2489000,          2499000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"CB",             2651500,          2800000,       S_STEP_5_0kHz,    MODULATION_AM},
    {"HAM 28",        2800000,          2870000,       S_STEP_5_0kHz,    MODULATION_SSB},
    {"HAM 50",        5000000,          5200000,       S_STEP_10_0kHz,   MODULATION_FM},
    {"70 Mhz",         7000000,          7050000,       S_STEP_12_5kHz,   MODULATION_FM},
    {"UHF400",        40000000,         42000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"UHF420",        42000000,         43300000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"UHF440",        44000000,         45500000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"UHF455",        45500000,         47000000,       S_STEP_25_0kHz,   MODULATION_FM},
	{"FM-BROAD",      7000000,          10800000,       S_STEP_100kHz,   MODULATION_FM},
    {"SATCOM",        24000000,         27000000,       S_STEP_10_0kHz,   MODULATION_FM}
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
    {"Military1",		15000000,            2696499,	 S_STEP_5_0kHz,		MODULATION_AM},
	{"Military2",		2799130,	         6399999,	 S_STEP_12_5kHz,	MODULATION_AM},
	{"Military3",		6400000,	         8799999,	 S_STEP_12_5kHz,	MODULATION_AM},
	{"108-118",			10800000,	        11799999,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"Air",			    11800000,	        13499999,	 S_STEP_12_5kHz,	MODULATION_AM},
	{"Business1",		13500000,	        14399999,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"2m HAM",			14400000,	        14599999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"146-148",  		14600000,	        14799999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"Business2",		14800000,	        15549999,	 S_STEP_12_5kHz,	MODULATION_FM},				
	{"Marine",			15550000,	        16199999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"Business3",		16200000,	        17399999,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"MSatcom1",		17400000,	        24499999,	 S_STEP_25_0kHz,	MODULATION_AM},
	{"Military4",		27000000,	        42999999,	 S_STEP_12_5kHz,	MODULATION_AM},
	{"70cmHAM1",	 	43000000,	        43307499,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"LPD",			    43307500,	        43477500,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"70cmHAM2",	 	43480000,	        43999999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"Business4",		44000000,	        44600624,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"PMR",	     	 	44600625,	        44619375,	 S_STEP_6_25kHz,	MODULATION_FM},
	{"Business5",		44620000,	        46256249,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"FRS/G462",		46256250,	        46273749,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"Business6",		46273750,	        46756249,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"FRS/G467",	 	46756250,	        46774999,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"Business7",		46775000,	        46999999,	 S_STEP_12_5kHz,	MODULATION_FM},
	{"470-620",			47000000,	        61999999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"840-863",			84000000,	        86299999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"23cm HAM",	 	126000000,	       129999999,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"1.3-1.34",	 	130000000,	       134000000,	 S_STEP_25_0kHz,	MODULATION_FM},
	{"160m HAM",	 	181000,	              200000,	 S_STEP_1_0kHz,		MODULATION_SSB},
	{"80m HAM",		  	350000,	              380000,	     S_STEP_1_0kHz,		MODULATION_SSB},
	{"40m HAM",		  	700000,	              719999,	     S_STEP_1_0kHz,		MODULATION_SSB},
	{"20m HAM",		  	1400000,	         1435000,	 S_STEP_1_0kHz,		MODULATION_SSB},
	{"10m HAM",		  	2800000,	         2969999,	 S_STEP_1_0kHz,		MODULATION_SSB},

};
#endif
