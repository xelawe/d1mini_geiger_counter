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

void ICACHE_RAM_ATTR ISR_impulse() { // Captures count of events from Geiger counter board
  counts++;
}

void geiger_do_meas() {
  gv_geiger_do_meas = true;
}


void init_geiger() {

  pinMode(inputPin, INPUT);                                                // Set pin for capturing Tube events

  // start counting
  memset(secondcounts, 0, sizeof(secondcounts));

  interrupts();                                                            // Enable interrupts
  attachInterrupt(digitalPinToInterrupt(inputPin), ISR_impulse, FALLING); // Define interrupt on falling edge
  meas_tick.attach(1, geiger_do_meas);

}


void check_geiger() {

  if ( gv_geiger_do_meas == true ) {
    // Werte der letzten Sekunde speichern
    unsigned long int count = counts;
    counts = 0;
    secondcounts[secidx] = count;
    secidx++;
    if ( secidx >= MAX_COUNTS ) {
      secidx = 0;
      // eine komplette Minute gemessen, erst dann cpm berechnen
      gv_meas_filled = true;
    }

    // cpm zusammenzählen
    gv_meas_ok = false;
    if (gv_meas_filled == true ) {
      cpm = 0;
      for (int i = 0; i < MAX_COUNTS; i++) {
        cpm += secondcounts[i];
        usvh = cpm;
        usvh = usvh / 151;
      }
      gv_meas_ok = true;
    }

    gv_geiger_do_meas = false;
  }



}

