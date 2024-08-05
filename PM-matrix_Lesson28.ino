#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String welcome="   Phils Arduino Project v.1    ";
int br = 115200;
int halfsec = 500;
int qtrsec = 250;
int tenthsec = 100;
int x;
int y;
int deltax=1;
int deltay=1;

byte frame[8][12]={
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
};

void setup() {
  // put your setup code here, to run once:
Serial.begin(br);
matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
welcomeText();
fourCorners();
ledDown();
ledAcross();
x=0;
y=0;
bouncingBall();
}

void fourCorners(){
  frame[0][0]=1;
  frame[0][11]=1;
  frame[7][0]=1;
  frame[7][11]=1;

  matrix.renderBitmap(frame,8,12);
  delay(halfsec);
  frame[0][0]=0;
  frame[0][11]=0;
  frame[7][0]=0;
  frame[7][11]=0;
  matrix.renderBitmap(frame,8,12);
}

void ledDown(){
  for (y=0;y<=7;y++){
    frame[y][0]=1;
    matrix.renderBitmap(frame,8,12);
    delay(qtrsec);
  }
  for (y=0;y<=7;y++){
    frame[y][0]=0;
    matrix.renderBitmap(frame,8,12);
  }
}

void ledAcross(){
  for (x=0;x<=11;x++){
    frame[0][x]=1;
    matrix.renderBitmap(frame,8,12);
    delay(qtrsec);
  }
  for (x=0;x<=11;x++){
    frame[0][x]=0;
    matrix.renderBitmap(frame,8,12);
  }
}

void welcomeText(){
  matrix.beginDraw();
  matrix.textScrollSpeed(50);
  matrix.textFont(Font_5x7);
  matrix.beginText(0,1,255,0,0);  // Column, Row, RED, Green,Blue
  matrix.println(welcome);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}

void bouncingBall(){
  for(;;){
    if (deltax==1){
      x=x+1;
      if (x>=12){
        deltax=-1;
        x=11;
      }
    }
    
    if (deltax==-1){
      x=x-1;
      if (x<=0){
        deltax=1;
      }
    }
    
    if (deltay==1){
      y++;
      if (y>=8){
        deltay=-1;
        y=7;
      }
    }
    
    if (deltay==-1){
      y--;
      if (y<=0){
        deltay=1;
      }
    }
    moveBall(); 
  }
}

void moveBall(){
//Serial.println(x);
frame[y][x]=1;
matrix.renderBitmap(frame,8,12);
delay(qtrsec);
frame[y][x]=0;
matrix.renderBitmap(frame,8,12);
}
