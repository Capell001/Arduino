#include "SwitchButton.h"


SwitchButton::SwitchButton(byte pin) {
  _pinNum = pin;
  _stateChangeCount = 0;
  pinMode(_pinNum, INPUT_PULLUP);
  _state = digitalRead(_pinNum);
}

unsigned long SwitchButton::getStateChangeCount() {
  boolean nowState = digitalRead(_pinNum);
  if (_state != nowState) {
    delay(10);
    if (nowState == digitalRead(_pinNum)) {
      _state = nowState;
      _stateChangeCount++;
    }
  }
  return _stateChangeCount;
}
