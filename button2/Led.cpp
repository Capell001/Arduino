#include "Led.h"

LED::LED(byte pin){
      _pinNum = pin;
      pinMode(_pinNum,OUTPUT);
}

byte LED::getPinNum(){
   return _pinNum;
 }

 void LED::on(){
    digitalWrite(_pinNum,HIGH);
}

void LED::off(){
    digitalWrite(_pinNum,LOW);
 }
