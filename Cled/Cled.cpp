#include "Arduino.h"
#include "Cled.h"

Cled::Cled(int pin){
    this->pin = pin;
    pinMode(pin,OUTOUT);




 void Cled::einschalten() {
    digitalWrite(this->led, HIGH);
  }

  void Cled::ausschalten() {
    digitalWrite(this->led, LOW);
  }

  void Cled::umschalten() {
    digitalWrite(this->led , !digitalRead(this->led));
  }

  bool Cled::getZustand() {
    return digitalRead(this->led);
  }

    void Cled::dimmen(int wert) {
    analogWrite(this->led, wert);
  } 
};