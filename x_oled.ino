
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library
#include <Wire.h>

#define PIN_RESET 255  //
#define DC_JUMPER 0  // I2C Addres: 0 - 0x3C, 1 - 0x3D

MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration
