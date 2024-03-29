#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define LED D4
bool ledState = false;

FirebaseData firebaseData;
void setup()
{
  //連線WIFI
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("My ASUS", "0918031776");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  //連線firebase
  Firebase.begin("iotcapel.firebaseio.com","v6vaSLzCienhRXC88xIrTaJgaCGF4fAKgBiwkTi7");

  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);

  //led SetUp
  pinMode(LED,OUTPUT);
}
void loop() {
  if (Firebase.getBool(firebaseData, "/iot0624/LED")) {
    if (firebaseData.dataType() == "boolean") {
      ledState = firebaseData.boolData();
      Serial.println(ledState);
      digitalWrite(LED,ledState);
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }

  delay(500);
  
}
