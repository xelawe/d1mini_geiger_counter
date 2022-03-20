void init_oled() {
  Wire.begin();
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
  oled.println("Radioact.:");

  oled.print(cpm);
  oled.println(" cpm");

  //oled.print(usvh);
  //oled.println(" uSv/h");
  oled.printf("%3.2f uSv/h", usvh);
  oled.println("");

  oled.display();

}
