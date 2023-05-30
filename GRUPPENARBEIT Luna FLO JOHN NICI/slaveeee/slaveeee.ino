#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(10);  // join i2c bus with address #10
  Wire.onRequest(receiveEvent);
}
  int sensorValueB;
  int sensorValueG;
void loop() {

      
}

void receiveEvent() {
    Serial.println(sensorValueB);
    Serial.println(sensorValueG);
  sensorValueB = analogRead(A2)/4;
  sensorValueG = analogRead(A3)/4;


    Wire.write(sensorValueB);
    Wire.write(sensorValueG);
  
}
