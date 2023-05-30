#include "Cled.h"

Cled led1(3);

void setup() {
  Serial.begin(9600);
  led1.dimmen(0);
}

int wert1 = 0;

int i =0;

void loop() {
if(i>255){i=0;}
  led1.dimmen(i);
  delay(200);


}

