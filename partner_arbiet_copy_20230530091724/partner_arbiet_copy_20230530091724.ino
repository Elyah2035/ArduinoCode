#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX

void setup() {

  pinMode(4, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);

  
}

int onOff;
int transmitter;
bool onOffLED=false;

void loop() {
 if (mySerial.available() > 0) {
      onOff = mySerial.read();

      Serial.write(onOff);

      digitalWrite(4 , onOffLED);
      onOffLED = !onOffLED;

 }

   if(Serial.available() > 0){
    transmitter = Serial.read();
    mySerial.write(transmitter);
  }

}






