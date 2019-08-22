#define BtnPin2 2
#define BtnPin6 6
void setup() {
 
  Serial.begin(115200);
  pinMode(BtnPin2,INPUT_PULLUP);
  pinMode(BtnPin6,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(BtnPin2));
  delay(10);
  Light();
}

void Light(){
  int LightPin = digitalRead(BtnPin2);
  if (LightPin==0){
    digitalWrite(6,HIGH);
  }  
  else
  {
    digitalWrite(6,LOW);
    }
}
