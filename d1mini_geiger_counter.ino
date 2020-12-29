
/*
   Geiger.ino

   This code interacts with the Alibaba RadiationD-v1.1 (CAJOE) Geiger counter board
   and reports readings in CPM (Counts Per Minute).

   Author: Alex

   Based on initial work of Andreas Spiess and Mark A. Heckler (@MkHeck, mark.heckler@gmail.com)

   License: MIT License

   Please use freely with attribution. Thank you!
*/
#include <cy_serdebug.h>
#include <cy_serial.h>

#include <Ticker.h>

const char *gc_hostname = "d1mgeiger";
#include "cy_wifi.h"
#include "cy_ota.h"

#include "geiger_tool.h"
#include "oled_tool.h"
#include "mqtt_tool.h"
#include "ota_tool.h"

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
      mqtt_data();
    }

    gv_meas_ok = false;
  }

  //check_mqtt();
  check_mqtt_reset();

  delay(50);
}





