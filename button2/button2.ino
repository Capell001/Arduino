#define BtnPin 2

boolean btnState;
unsigned int switchCount = 0;
unsigned int stateChangeCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BtnPin, INPUT_PULLUP);
  btnState = digitalRead(BtnPin);
}

void loop() {
  boolean nowState = digitalRead(BtnPin);
  if (btnState != nowState) {
    delay(10);
    if (nowState == digitalRead(BtnPin)) {
      btnState = nowState;
      stateChangeCount++;
      switch (stateChangeCount % 2) {
        case 0:
          switchCount++;
          break;
      }
    }
  }

  Serial.print("you click:");
  Serial.println(switchCount);

}
