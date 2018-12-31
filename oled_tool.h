
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

#define PIN_RESET 255  //
#define DC_JUMPER 0  // I2C Addres: 0 - 0x3C, 1 - 0x3D

MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C declaration

void init_oled() {
  oled.begin();     // Initialize the OLED
  oled.flipVertical(true);
  oled.flipHorizontal(true);
  oled.clear(PAGE); // Clear the display's internal memory
  oled.clear(ALL);  // Clear the library's display buffer
  oled.setFontType(0); // set font type 0, please see declaration in SFE_MicroOLED.cpp
  oled.setCursor(0, 0); // points cursor to x=0 y=0
}



void disp_data() {

  oled.clear(PAGE);  // Clear the buffer
  oled.setFontType(0); // set font type 0, please see declaration in SFE_MicroOLED.cpp
  oled.setCursor(0, 0); // points cursor to x=0 y=0
  oled.println("Radioactivity");
  
  oled.print(cpm);
  oled.println(" cpm");

  oled.print(usvh);
  oled.println(" µSv/h");
  
  oled.display();

}

//void displayInt(int dispInt, int x, int y) {
//  display.setColor(WHITE);
//  display.setTextAlignment(TEXT_ALIGN_CENTER);
//  display.drawString(x, y, String(dispInt));
//  display.setFont(ArialMT_Plain_24);
//  display.display();
//}

//void displayString(String dispString, int x, int y) {
//  display.setColor(WHITE);
//  display.setTextAlignment(TEXT_ALIGN_CENTER);
//  display.drawString(x, y, dispString);
//  display.setFont(ArialMT_Plain_24);
//  display.display();
//}

