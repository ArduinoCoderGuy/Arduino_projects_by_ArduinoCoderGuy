//////////////////////////////////////////////////////////////////
// BASIC SKETCH TO SHOW HOW TO GET TWO I2C SCREENS WORKING WITH //
//                  THE U8g2lib.h LIBRARY                       //
//////////////////////////////////////////////////////////////////

#include <SPI.h>
#include "U8g2lib.h"
#include <Wire.h> //Library for I2C interface
int randx, randy, i;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED_1(U8G2_R0, U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED_2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  randomSeed(analogRead(0));
  delay(250);
  OLED_1.setI2CAddress(0x3C * 2);        //<- SOLVED it works
  OLED_2.setI2CAddress(0x3D * 2);        //<- SOLVED it works
  OLED_1.begin();
  OLED_2.begin();
  OLED_1.setFont(u8g_font_6x10);
  OLED_2.setFont(u8g_font_6x10);
// Initial Display at power on
char buffer[10];
  OLED_1.clearBuffer(); // clear the internal memory
  OLED_1.setFont(u8g_font_6x10);
  OLED_1.drawStr(0, 10, "Hello User");
  // dtostrf(10, 5, 0, buffer); //print value 10
  //OLED_1.drawStr(80, 10, buffer);
  OLED_1.sendBuffer(); // transfer internal memory to the display

OLED_2.clearBuffer(); // clear the internal memory
  OLED_2.setFont(u8g_font_6x10);
  OLED_2.drawStr(0, 10, "Hello User");
  // dtostrf(10, 5, 0, buffer); //print value 10
  //OLED_2.drawStr(80, 10, buffer);
  OLED_2.sendBuffer(); // transfer internal memory to the display
  delay(2000);
}

void loop() {
  static unsigned long oledTimer = millis(); //every 1000ms update the oled display
  if (millis() - oledTimer >= 1000) {
    oledTimer = millis();
    OLED_1.clearDisplay();
    OLED_2.clearDisplay();
    drawOLED_1();
    drawOLED_2();
    delay(500);
    drawPixels();
  }
}

void drawOLED_1(void) {
  char buffer[10];
  OLED_1.clearBuffer(); // clear the internal memory
  OLED_1.setFont(u8g_font_6x10);
  OLED_1.drawStr(0, 10, "Screen(0x3C)1-> ");
  dtostrf(10, 5, 0, buffer); //print value 10
  OLED_1.drawStr(80, 10, buffer);
  OLED_1.sendBuffer(); // transfer internal memory to the display
}

void drawOLED_2(void) {
  char buffer[10];
  OLED_2.clearBuffer(); // clear the internal memory
  OLED_2.setFont(u8g_font_6x10);
  OLED_2.drawStr(0, 10, "Screen(0x3D)2-> ");
  //OLED_1.drawPixel(30, 30);
  dtostrf(20, 5, 0, buffer); //print value 20
  OLED_2.drawStr(80, 10, buffer);
  OLED_2.sendBuffer(); // transfer internal memory to the display
}

void drawPixels(){
   char buffer[10]; 
   for (i = 0; i <= 50; i++){
     //OLED_1.clearBuffer(); // clear the internal memory
     randx = random(127);
     randy = random(53);
     OLED_1.drawPixel(randx, randy + 10);
     //OLED_1.drawBox(randx, i, randy, i+10);
     OLED_1.sendBuffer(); // transfer internal memory to the display
     //OLED_2.clearBuffer(); // clear the internal memory
     randx = random(127);
     randy = random(53);
     OLED_2.drawPixel(randx, randy + 10);
     OLED_2.sendBuffer(); // transfer internal memory to the display
     delay(50);
  }
}

/* displays examples
u8g2.setFont(u8g2_font_7x14B_tf);
u8g2.drawStr(0,10,"Hello!");
u8g2.drawLine(0,0,63,63);
u8g2.drawLine(63,63,63+63,63-63);
u8g2.drawPixel(126,20);
u8g2.drawPixel(127,21);
 */
