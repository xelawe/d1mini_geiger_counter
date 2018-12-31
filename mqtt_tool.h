#include "cy_mqtt.h"

const char* mqtt_pubtopic_cpm_suff = "cpm/value";

String mqtt_pubtopic_cpm_s;
const char* mqtt_pubtopic_cpm;


void init_mqtt_local() {

  mqtt_pubtopic_cpm_s += gv_clientname;
  mqtt_pubtopic_cpm_s += '/';
  mqtt_pubtopic_cpm_s += mqtt_pubtopic_cpm_suff;
  mqtt_pubtopic_cpm = (char*) mqtt_pubtopic_cpm_s.c_str();
  DebugPrintln(mqtt_pubtopic_cpm);

  init_mqtt(gv_clientname);

}

void mqtt_data() {

  char buffer[10];
  dtostrf(cpm, 0, 1, buffer);
  client.publish(mqtt_pubtopic_cpm, buffer, true);

}
