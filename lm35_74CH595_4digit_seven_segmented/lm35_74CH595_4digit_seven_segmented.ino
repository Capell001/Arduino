#define tempPin A0

float tempC;


void setup()
{
  Serial.begin(115200); //opens serial port, sets data rate to 9600 bps
}

void loop()
{
  tempC = analogRead(tempPin);           //read the value from the sensor
   tempC = (tempC / 1024 * 3.3 / 0.01); //convert the analog data to temperature
  Serial.println(tempC);
  delay(1000);
}
