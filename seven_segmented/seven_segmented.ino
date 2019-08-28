//***********************************************************
//參考的網址
//http://programmermagazine.github.io/201307/htm/article1.html
//***********************************************************
// 七段顯示器製作倒數功能 (v1)

#include "SwitchButton.h"

SwitchButton btn(10);

byte digits[10][7] = { 
  { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 0, 0, 1, 1 } // = 9
};


byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  Serial.begin(115200);
  for (byte i = 0; i < 7; i++) {
    pinMode(mapArdiuinoPin[i], OUTPUT);
  }
}

void loop() {
  unsigned long BtnCount=btn.getStateChangeCount()%20;
  unsigned long PinCount=BtnCount%2;
  Serial.println(BtnCount);
  Serial.println(PinCount);
  switch(PinCount){
    case 0:
    displayDigit(BtnCount);
    delay(100);
    break;
  }
}


void displayDigit(unsigned long BtnCount){
    unsigned long PinIndex = BtnCount/2;
    for(int i=0; i<7 ; i++){
      bool onePinState = digits[PinIndex][i];
      byte pinNum = mapArdiuinoPin[i];
      digitalWrite(pinNum,onePinState);
    }
}
