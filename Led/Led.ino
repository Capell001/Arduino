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

Led firstLed(13);
Led secondLed(12);

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
