#include <arduino.h>
class Led{
  private:
    byte _pinNum;
    
  public:
    Led(byte pin){
      _pinNum = pin;
      pinMode(_pinNum,OUTPUT);
     }

     byte getPinNum(){
        return _pinNum;
     }

     void on(){
      digitalWrite(_pinNum,HIGH);
     }

     void off(){
      digitalWrite(_pinNum,LOW);
     }
};
