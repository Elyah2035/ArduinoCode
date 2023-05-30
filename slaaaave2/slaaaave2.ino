#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(10);  // join i2c bus with address #10
  Wire.onRequest(receiveEvent);
}
int sensorValueR;
int sensorValueG;
int sensorValueB;

void loop(){

}

void receiveEvent() {
  sensorValueR = analogRead(A2) / 4;
  sensorValueG = analogRead(A3) / 4;
  sensorValueB = analogRead(A6) / 4;
    Serial.print("R");
    Serial.println(sensorValueR);
    Serial.print("G");
    Serial.println(sensorValueG);
    Serial.print("B");
    Serial.println(sensorValueB);
delay(20);
  Wire.write(sensorValueR);
  Wire.write(sensorValueG);
  Wire.write(sensorValueB);
}
