#ifndef Cled_h
#define Cled_h
#include "Arduino.h"
class Cled{
    private:
    int pin;
    public:
        Cled(int pin);
        void einschalten() {
    digitalWrite(this->led, HIGH);
  }

  void ausschalten() {
    digitalWrite(this->led, LOW);
  }

  void umschalten() {
    digitalWrite(this->led , !digitalRead(this->led));
  }

  bool getZustand() {
    return digitalRead(this->led);
  }
    void dimmen(int wert) {
    analogWrite(this->led, wert);
  } 
};

