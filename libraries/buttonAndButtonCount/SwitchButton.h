#include <arduino.h>

class SwitchButton {
  private:
    byte _pinNum;
    unsigned long _stateChangeCount;
    boolean _state;

  public:
    SwitchButton(byte);//建構式
    unsigned long getStateChangeCount();//取得按鈕被按的總次數
};
