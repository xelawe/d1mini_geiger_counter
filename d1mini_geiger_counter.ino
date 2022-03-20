
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
