class Cled {
private:
  int led;

public:
  Cled(int led) {
    this->led = led;
    pinMode(this->led, OUTPUT);
  }

  void einschalten() {
    digitalWrite(this->led, HIGH);
  }

  void ausschalten() {
    digitalWrite(this->led, LOW);
  }

  void dimmen(int wert) {
    analogWrite(this->led, wert);
  } 

  void umschalten() {
    digitalWrite(this->led , !digitalRead(this->led));
  }

  bool getZustand() {
    return digitalRead(this->led);
  }
};
class Potentiometer {
private:
  int pin;

public:
  Potentiometer(int pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
  }

  int readValue() {
    return analogRead(this->pin);
  }
};

Potentiometer pot1(A0);


Cled led1(3);

void setup() {
  Serial.begin(9600);
  led1.dimmen(0);
}

int wert1 = 0;



void loop() {
Serial.println(pot1.readValue()/4);
int potValue = pot1.readValue();
  led1.dimmen(pot1.readValue()/4);


}
