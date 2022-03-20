#define LOG_PERIOD 20000 //Logging period in milliseconds
#define MINUTE_PERIOD 60000

volatile unsigned long counts = 0;                       // Tube events
unsigned long cpm = 0;                                   // CPM
float usvh = 0;
unsigned long previousMillis;                            // Time measurement
const int inputPin = D5;
boolean gv_meas_ok = false;
boolean gv_meas_filled = false;
boolean gv_geiger_do_meas = false;

#define MAX_COUNTS 60
static int secondcounts[MAX_COUNTS];
static unsigned long int secidx = 0;


Ticker meas_tick;
