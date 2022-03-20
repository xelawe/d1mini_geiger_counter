void init_mqtt_local() {

//  mqtt_pubtopic_cpm_s += gv_clientname;
//  mqtt_pubtopic_cpm_s += '/';
//  mqtt_pubtopic_cpm_s += mqtt_pubtopic_cpm_suff;
//  mqtt_pubtopic_cpm = (char*) mqtt_pubtopic_cpm_s.c_str();
//  DebugPrintln(mqtt_pubtopic_cpm);

  init_mqtt(gv_clientname);

}

//void mqtt_data() {
//
//  char buffer[10];
//  dtostrf(cpm, 0, 1, buffer);
//  client.publish(mqtt_pubtopic_cpm, buffer, true);
//
//}

void pub_sens() {

  char buffer[256];
  //dtostrf(fire.NUMFirePIXELS, 0, 0, buffer);

  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<200> jsondoc;

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);

  // Add values in the document
  //

  // Add the "BH1750"
  JsonObject geiger = jsondoc.createNestedObject("Geiger");
  geiger["CPM"] = (int)(cpm);

  int n  = serializeJson(jsondoc, buffer);

  //client.publish(mqtt_pubtopic_sensor, buffer, true);
  client.publish(mqtt_GetTopic_P(gv_ptopic, mqtt_pre_tele, gv_clientname, (PGM_P)F("SENSOR")), buffer, true);
}
