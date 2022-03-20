
void setup() {
  cy_serial::start(__FILE__);

  init_oled();

  oled.println("WiFi init");
  oled.display();

  wifi_init(gc_hostname);

  oled.println("WiFi OK");
  oled.display();

  oled.println("OTA init");
  oled.display();
  init_ota_local();

  oled.println("MQTT init");
  oled.display();
  init_mqtt_local();

  init_geiger();

  oled.println("Measuring");
  oled.display();

}

void loop() {
  check_ota();

  check_geiger();

  if ( gv_meas_ok == true ) {

    disp_data();

    if (secidx == 0 ) {
      //mqtt_data();
      pub_sens();
    }

    gv_meas_ok = false;
  }

  check_mqtt_reset();

  delay(50);
}
