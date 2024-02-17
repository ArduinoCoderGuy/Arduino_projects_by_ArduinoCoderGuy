//////////////////////////////////////////////////////////////////////////
// HOW TO DRAW CIRCLES ON THE ILI9341 TOUCHSCREEN USING SINE AND COSINE //
// RATHER THAN THE <CIRCLE. COMMAND. USEFUL IF YOU WANT TO CREATE A     //
// CLOCKFACE OR SIMILAR                                                 //
// CODE CREATED FOR ARDUINO R3 BUT SHOULD BE OK FOR R4 WIFI             //
//////////////////////////////////////////////////////////////////////////

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#include <Adafruit_ILI9341.h>   // include Adafruit ILI9341 TFT library

#define MINPRESSURE 200
#define MAXPRESSURE 1000
// DEFINE COLOURS //
#define BLACK   0x0000
#define BLUE    0x001f
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
int temp = 0;
int halfSec = 500;
int fiveSecs = 5000;
int ColourSelect = 1;

float x_center = 120;               // ALL THE CIRCUMFERANCE POINTS ARE MEASURED
float y_center = 160;               // FROM THE CENTRE OF THE CIRCLE
float radius = 100;                 // A DISTANCE OF RADIUS
float a_circumferance = 0;          // THE COSINE OF A TRIANGLE IS USED TO MEASURE TO POINT <A>
float b_circumferance = 0;          // THE SINE OF A TRIANGLE IS USED TO MEASURE TO POINT <B>
int d_degrees = 0;                  // LOOK DOWN FURTHER YOU'LL WONDER WHERE 0.01745331 COMES FROM....
float angle_circle = 0;

void setup() {
tft.begin();
tft.fillScreen(BLACK);
}

void loop() {
  
  drawACircle();
  ColourSelect = 1;
  for(radius = 100; radius >= 5; radius = radius -5){
    
    drawACircle();
  }
  
  radius = 100;
  ColourSelect = 2;
  for(radius = 100;radius >= 5; radius = radius -5){
    
  drawACircle();
  }
  radius = 100;
  ColourSelect = 3;  
  for(radius = 100;radius >= 5; radius = radius -5){
    
  drawACircle();
  }
  radius = 100;
  ColourSelect = 4;  
  for(radius = 100;radius >= 5; radius = radius -5){
    
  drawACircle();
  }
  radius = 100;
  ColourSelect = 5;  
  for(radius = 100;radius >= 5; radius = radius -5){
   
  drawACircle();
  }
  radius = 100;
  ColourSelect = 6;  
  for(radius = 100;radius >= 5; radius = radius -5){
    
  drawACircle();
  }
  radius = 100;
  ColourSelect = 7;  
  for(radius = 100;radius >= 5; radius = radius -5){
   
  drawACircle();
  }
  radius = 100;
  ColourSelect = 8;  
  for(radius = 100;radius >= 5; radius = radius -5){
    
  drawACircle();
  }
  
}

void drawACircle(){
  
    for (d_degrees = 0; d_degrees < 360; d_degrees++){
    angle_circle = (d_degrees * 0.01745331);                      // CIRCLES ARE DRAWN IN RADIENS NOT DEGREES
                                                                  // ONE RADIAN = 2*PI DIVIDE THAT BY 360 AND WHAT DO YOU GET :)
    a_circumferance = (x_center + ( radius * cos(angle_circle)));
    b_circumferance = (y_center + ( radius * sin(angle_circle)));
    
    //tft.drawPixel(a_circumferance, b_circumferance, WHITE);
    if(ColourSelect == 1){
      tft.drawPixel(a_circumferance, b_circumferance, BLUE);
    }
    if(ColourSelect == 2){
      tft.drawPixel(a_circumferance, b_circumferance, RED);
    }
    if(ColourSelect == 3){
      tft.drawPixel(a_circumferance, b_circumferance, GREEN);
    }
    if(ColourSelect == 4){
      tft.drawPixel(a_circumferance, b_circumferance, MAGENTA);
    }
    if(ColourSelect == 5){
      tft.drawPixel(a_circumferance, b_circumferance, CYAN);
    }
    if(ColourSelect == 6){
      tft.drawPixel(a_circumferance, b_circumferance, YELLOW);
    }
    if(ColourSelect == 7){
      tft.drawPixel(a_circumferance, b_circumferance, WHITE);
    }
    if(ColourSelect == 8){
      tft.drawPixel(a_circumferance, b_circumferance, BLACK);
    }
  
  }

}
