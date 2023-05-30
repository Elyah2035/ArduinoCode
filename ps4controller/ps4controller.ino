#include <PS4Controller.h>

//#include <SoftwareSerial.h>
//SoftwareSerial(12, 13)

  void setup() {
  Serial.begin(115200);
  PS4.begin("1a:2b:3c:01:01:01");
  Serial.println("Ready.");
}

void loop() {
  if (PS4.isConnected()) {

    if (PS4.L2()) {
      Serial.printf("L", PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R", PS4.R2Value());
    }


  }
}
