#include <arduino.h>
class LED{
  private:
    byte _pinNum;
    
  public:
    LED(byte pin);

     byte getPinNum();
     
     void on();//燈亮
     void off();//燈暗
};
