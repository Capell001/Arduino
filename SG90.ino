#include "FirebaseESP8266.h"
#include <Servo.h>
#include <ESP8266WiFi.h>
#define SG90pin D6
Servo myservo; // 建立Servo物件，控制伺服馬達
int SGState = 0;
FirebaseData firebaseData;
void setup() 
{ 
  //連線WIFI
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
  myservo.attach(D6); // 連接數位腳位9，伺服馬達的訊號線


Firebase.begin("iot-aloni.firebaseio.com",
                 "niI76kmgD1VfckKX2VPHwQqkVmWK4G9i3d27ddaI");

  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);
}




void loop()
{
  if (firebase.getInt(firebaseData, "/iot0624/SG90")) {
    if (firebaseData.dataType() == "int") {
      SGState = firebaseData.intData();
 
      Serial.println(SGState );
      digitalWrite(SG90pin,SGState );
    } 

   
  for(int i = 0; i <= 100; i+=1){
    myservo.write(i); // 使用write，傳入角度，從0度轉到180度
    delay(20);
  }
  for(int i = 100; i >= 0; i-=1){
    myservo.write(i);// 使用write，傳入角度，從180度轉到0度
    delay(20);
  }
  }
}
