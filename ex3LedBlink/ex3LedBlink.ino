void setup() {
  // put your setup code here, to run once:
      pinMode(13,OUTPUT);
      Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
      if(Serial.available()){
       char rx = Serial.read();
        if(rx=='0'){
          digitalWrite(13,LOW);
        }
        else if(rx=='1'){
          digitalWrite(13,HIGH);    
        }
      }
}
