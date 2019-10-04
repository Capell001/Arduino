#include <ESP8266WiFi.h>
#include <Servo.h>
#include "FirebaseESP8266.h"

#define tempPin A0
#define LED D4
#define controlPin D6

FirebaseData firebaseData;
Servo myservo; // 建立Servo物件，控制伺服馬達

bool preStatus = false;
bool ledState = false;
float tempC;


void setup() {
  //led SetUp
  pinMode(LED,OUTPUT);
  
  // put your setup code here, to run once:
  pinMode(controlPin, OUTPUT);

  // Connect Wi-Fi
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("Pixel", "macu830410");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  myservo.attach(controlPin); // 連接數位腳位D6，伺服馬達的訊號線

  // Connect firebase
  Firebase.begin("iot-aloni.firebaseio.com", "niI76kmgD1VfckKX2VPHwQqkVmWK4G9i3d27ddaI");
  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 
 
  if (Firebase.getBool(firebaseData, "/iot0624/SG90")) {
    if (firebaseData.dataType() == "boolean") {
      bool direction = firebaseData.boolData();
      
      if ((direction == true) && (preStatus == false)) {
        myservo.write(0);
        for(int i = 0; i <= 70; i+=1){
          myservo.write(i); // 使用write，傳入角度，從0度轉到180度
          delay(20);
        }
        preStatus = true;
      }
      else if ((direction == false) && (preStatus == true)){
        for(int i = 70; i >= 0; i-=1){
          myservo.write(i);// 使用write，傳入角度，從180度轉到0度
          delay(20);
        }
        preStatus = false;
      }

      else { 
        delay(1000);
      }
    }
  }
  else {
    Serial.println(firebaseData.errorReason());
  }

   
  
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
