#include "Led.h"

LED firstLed(13);
LED secondLed(12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println( firstLed.getPinNum());
  Serial.println( secondLed.getPinNum());
  firstLed.on();
  secondLed.on();
  }

void loop() {
  // put your main code here, to run repeatedly:

}
