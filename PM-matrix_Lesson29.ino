#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String welcome="Pong!";
String miss="You Missed!   ";
String replay=" Play Again? Hold Down Play ";
int br = 115200;
int halfsec = 500;
int qtrsec = 250;
int tenthsec = 100;
int dt = 150;
int playery = 3;
int yup = 7;
int ydn = 6;
int newgame = 5;
int restart;
int lives = 3;
int i;
int j;
int playerup;
int playerdown;

int x = 5;
int y = 3;
int deltax=1;
int deltay=1;

byte frame[8][12];

void setup() {
pinMode(yup, INPUT);
pinMode(ydn, INPUT);
pinMode(newgame, INPUT);
Serial.begin(br);
matrix.begin();
matrix.beginDraw();
matrix.textScrollSpeed(50);
matrix.textFont(Font_5x7);
matrix.beginText(0,1,255,0,0);  // Column, Row, RED, Green,Blue
matrix.println(welcome);
matrix.endText(SCROLL_LEFT);
matrix.endDraw();
delay(halfsec);
}

void loop() {
  if(lives <= 0){
    gameover();
  }
  for(i=0;i<=11;i++){
    for(j=0;j<=7;j++){
      frame[j][i]=0;
      matrix.renderBitmap(frame,8,12);
    }
  }
  y=y+deltay;
  x=x+deltax;
  if(y==7 || y==0){
    deltay = deltay * -1;
  }
  
  if(x==11 || x==0){
    deltax = deltax * -1;
  }
  frame[y][x]=1;
  playerup = digitalRead(yup);
  if(playerup == HIGH){
    playery++;
  }
  
  playerdown = digitalRead(ydn);
  if(playerdown == HIGH){
    playery--;
  }
  if (playery<=0){
    playery = 0;
  }
  if (playery>=8){
    playery = 7;
  }
  frame[playery][0]=1;
  matrix.renderBitmap(frame,8,12);
  if(y != playery && x == 0){
    missed();
  }
  delay(dt);
}

void missed(){
  matrix.beginDraw();
  matrix.textScrollSpeed(50);
  matrix.textFont(Font_5x7);
  matrix.beginText(0,1,255,0,0);  // Column, Row, RED, Green,Blue
  matrix.println(miss);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
  delay(halfsec);
  lives--;
  Serial.println(lives);
  if(lives <= 0){
    gameover();
  }
  int x = 5;
  int y = 3;
  int deltax=1;
  int deltay=1;
}

void gameover(){
  Serial.println("Game Over");
  matrix.beginDraw();
  matrix.textScrollSpeed(50);
  matrix.textFont(Font_5x7);
  matrix.beginText(0,1,255,0,0);  // Column, Row, RED, Green,Blue
  matrix.println(replay);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw(); 
  if(digitalRead(newgame) == LOW){
    lives = 3;
  }
}
