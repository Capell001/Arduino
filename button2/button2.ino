#include "Led.h"
#define BtnPin 2

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
       boolean nowState = digitalRead(BtnPin);
       if (_state!=nowState){
          if (nowState == digitalRead(BtnPin)) {
           _state = nowState;
           _stateChangeCount++;
          } 
       } 
    return _stateChangeCount; 
    }
  
};
LED redLed(13);
SwitchButton btn(2);
void setup() {
  Serial.begin(115200); 
  redLed.off();
}

void loop() {
  unsigned int stateChangeCount = btn.getStateChangeCount();
   switch (stateChangeCount % 4) {
        case 0:
          redLed.off();
          break;
        case 2:
          redLed.on();
          break;
   }

   Serial.print("you click:");
  Serial.println(stateChangeCount/2);


}
