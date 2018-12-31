#define LOG_PERIOD 20000 //Logging period in milliseconds
#define MINUTE_PERIOD 60000

volatile unsigned long counts = 0;                       // Tube events
unsigned long cpm = 0;                                   // CPM
float usvh = 0;
unsigned long previousMillis;                            // Time measurement
const int inputPin = D5;
boolean gv_meas_ok = false;
boolean gv_meas_filled = false;

#define MAX_COUNTS 60
static int secondcounts[MAX_COUNTS];
static unsigned long int secidx = 0;


Ticker meas_tick;

void ISR_impulse() { // Captures count of events from Geiger counter board
  counts++;
}

void do_meas() {
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
      usvh = cpm / 151;
    }
    gv_meas_ok = true;
  }

}


void init_geiger() {

  pinMode(inputPin, INPUT);                                                // Set pin for capturing Tube events

  // start counting
  memset(secondcounts, 0, sizeof(secondcounts));

  interrupts();                                                            // Enable interrupts
  attachInterrupt(digitalPinToInterrupt(inputPin), ISR_impulse, FALLING); // Define interrupt on falling edge
  meas_tick.attach(1, do_meas);

}


void check_geiger() {

  //  unsigned long currentMillis = millis();
  //
  //  if (currentMillis - previousMillis > LOG_PERIOD) {
  //    previousMillis = currentMillis;
  //    cpm = counts * MINUTE_PERIOD / LOG_PERIOD;
  //    //cpm=105;
  //    counts = 0;
  //    gv_meas_ok = true;
  //  }

}

