#include <arduino.h>

class SwitchButton{
  private:
    byte _pinNum;
    unsigned long _stateChangeCount;
    boolean _state;

  public:
    SwitchButton(byte pin){
      _pinNum=pin;
      _stateChangeCount=0;
      pinMode(_pinNum,INPUT_PULLUP);
      _state=digitalRead(_pinNum);  
    }

    unsigned long getStateChangeCount(){
       boolean nowState = digitalRead(_pinNum);
       if (_state!=nowState){
          if (nowState == digitalRead(_pinNum)) {
           _state = nowState;
           _stateChangeCount++;
          } 
       } 
    return _stateChangeCount; 
    }
  
};
