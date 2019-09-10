#define tempPin A0

float tempC;


void setup()
{
  Serial.begin(115200); //opens serial port, sets data rate to 9600 bps
}

void loop()
{
  tempC = analogRead(tempPin);           //read the value from the sensor
  tempC = (5.0 * tempC * 100.0) / 1024.0; //convert the analog data to temperature
  Serial.println(tempC);
  delay(1000);
}
