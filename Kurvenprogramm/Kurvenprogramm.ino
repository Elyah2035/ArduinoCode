#include <SoftwareSerial.h>
#include <FahrzeugLib.h>
SoftwareSerial BT(10, 11);

char BT_Char = ' '; char BT_ID = ' '; char BT_ID_temp = ' '; bool BT_ID_expected = true; bool BT_newReading = false;
String BT_ValueStr = ""; float BT_Value;
float geschwindigkeit;
float neigung;
boolean direktion = true;
boolean runing = true;
unsigned long aktuelleZeit;

/*
   geschw ist ein Wert von 0 bis 255
   form gibt den Kurvenradius an: form = 0 -> geradeaus
                                  form = -1 -> Linkskurve, linkes Rad ist halb so schnell wie rechtes
                                  form = 1 -> Rechtskurve, rechtes Rad ist halb so schnell wie linkes

   Methoden für Klasse CMotor:
    CMotor(int pinPWM, int pinNichtPWM);
    void Bewegen(bool vorwaerts, int geschw);
    void Stop();

   Methoden für Klasse CAntrieb:
    CAntrieb(CMotor *motor1, CMotor *motor2);
    void Gerade(bool vorwaerts, int geschw);
    void Kurve(double form, int geschw, bool vorwaerts);
    void Stop();
    void Wende(bool links, int geschw);
*/

//Erstellen von zwei Objekten vom Typ "C-Motor"
CMotor MotorLinks(3, 2); // Der Pin, der im ersten Parameter angegeben ist, muss PWM-fähig sein, der zweite nicht unbedingt
CMotor MotorRechts(5, 4);

//Erstellen eines Objektes vom Type "CAntrieb"
CAntrieb Antrieb(&MotorLinks, &MotorRechts);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  BT_check();
  if (BT_newReading) {
    BT_setValue();
  }
  if (millis() > aktuelleZeit + 5000 || runing == false) {
    aktuelleZeit = millis();
    Antrieb.Stop();
  } else {
    Antrieb.Kurve(neigung, geschwindigkeit, direktion);
  }
}

void BT_check() {
  BT_newReading = false;
  if (BT.available())
  {
    BT_Char = BT.read();
    Serial.print(BT_Char);

    if (BT_ID_expected) {
      BT_ID_temp = BT_Char;
      BT_ID_expected = false;
      BT_ValueStr = "";
    }
    else
    {
      if ( (BT_Char != ' ') && (BT_Char != '\n')) {
        BT_ValueStr += BT_Char;
      }

      if (BT_Char == '\n') {
        BT_ID = BT_ID_temp;
        BT_Value = BT_ValueStr.toFloat();
        BT_ValueStr = "";
        BT_ID_expected = true;
        BT_newReading = true;
      }
    }
  }
}
void BT_setValue() {
  switch (BT_ID) {
    case 'G': {
        direktion = true;
        runing = true;
        aktuelleZeit = millis();
        break;
      }
    case 'S': {
        runing = false;
        break;
      }
    case 'R': {
        direktion = false;
        runing = true;
        aktuelleZeit = millis();
        break;
      }
    case 'Y': {
      Serial.println(BT_Value);
        neigung = BT_Value *0.4;
        Serial.println(neigung);
        break;
      }
    case 'V': {
        geschwindigkeit = BT_Value;
        runing = true;
        aktuelleZeit = millis();
        break;
      }
  }
}
