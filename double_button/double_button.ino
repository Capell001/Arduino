#include "Led.h"
#include "SwitchButton.h"

LED RedLed(10);
LED GreenLed(9);
LED YellowLed(8);
SwitchButton RightBtn(2);
SwitchButton LeftBtn(4);

void Turn_off(){
  RedLed.off();
  GreenLed.off();
  YellowLed.off();
}

void RightSwitchCase(unsigned long Switch){
    switch (Switch){
        case 0:
         RedLed.on();
         GreenLed.off();
         YellowLed.off();
        break;
        case 2:
         RedLed.off();
         GreenLed.on();
         YellowLed.off();
        break;
        case 4:
         RedLed.off();
         GreenLed.off();
         YellowLed.on();
        break;
    }    
}

void LeftSwitchCase(unsigned long LeftSwitch,unsigned long RightSwitch){
    unsigned long LeftSwitchCount = LeftSwitch %4;
    unsigned long RightSwitchCount = RightSwitch %6;
    switch (LeftSwitchCount){
        case 0:
        Turn_off();
        break;
        case 2:
        RightSwitchCase(RightSwitchCount);
        break;
    }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
   unsigned long RightCounts = RightBtn.getStateChangeCount(); 
   unsigned long LeftCounts = LeftBtn.getStateChangeCount();

   LeftSwitchCase(LeftCounts,RightCounts);
}
