#include <Adafruit_NeoPixel.h>

#define PIN 6

#define NUMPIXEL 255
int anzLEDs = 31;

Adafruit_NeoPixel Pixel(NUMPIXEL, PIN, NEO_GRB + NEO_KHZ800);


#define Taster 2
#define prellZeit 50

int muster;
int anzMuster = 6;
bool taste;
bool tasteAlt;
bool steigFlanke;
bool fallFlanke;
unsigned int letzteFlankenZeit = 0;
int laengeLauflicht = 5;
int LEDNr = 0;
unsigned long zeitSchritt=10 ;
unsigned long letzteZeit;


void setup() {
  pinMode(Taster, INPUT_PULLUP);

  Serial.begin(9600);
  Pixel.begin();
}

void loop() {

  taster();
  mustereinstellen();


}
void mustereinstellen () {

  switch (muster) {
    case 0:
      allesBlau();
      break;
    case 1:
      allesRot();

      break;
    case 2:
       laufLichtEins();
      break;

      case 3:
laufLichtMehere();
      break;
      case 4:
nightRider();
      
      break;

      case 5:
nightRiderMehere();
      
      break;
  }

  Pixel.show();

}




void taster () {
  tasteAlt = taste;
  taste = !digitalRead(Taster);
  steigFlanke = !tasteAlt && taste;
  fallFlanke = tasteAlt && !taste;

  if (steigFlanke && (millis() >= letzteFlankenZeit + prellZeit)) {
    muster = (muster + 1) % anzMuster;

    Serial.print(muster);
  }

  if (fallFlanke) {
    letzteFlankenZeit = millis();
  }

}

void allesRot(){
 for (int i = 0; i < 30; i++ ) {
        Pixel.setPixelColor(i , Pixel.Color(0, 0, 255));
      }
}

void allesBlau(){
 for (int i = 0; i < 30; i++ ) {
        Pixel.setPixelColor(i , Pixel.Color(255, 0, 0));
      }
}

void laufLichtEins(){
          
        if(millis()>letzteZeit+zeitSchritt){
          Pixel.clear();
          Pixel.setPixelColor(LEDNr, Pixel.Color(0, 255, 255));


          LEDNr = (LEDNr +1)%anzLEDs;
          letzteZeit = millis();
        }
}

void laufLichtMehere(){
      if(millis()>letzteZeit+zeitSchritt){
          Pixel.clear();
          for(int i =0;i<laengeLauflicht;i++){
          Pixel.setPixelColor((LEDNr+i)%anzLEDs, Pixel.Color(0, 255, 255));

            
          }

          LEDNr = (LEDNr +1)%anzLEDs;
          letzteZeit = millis();
        }
  
}
int lEDNrNight = 1;
  int richtung = -1;

void nightRiderMehere() {
   if(millis()>letzteZeit+zeitSchritt) {
     lEDNrNight = lEDNrNight + richtung;
     
    
     
     Pixel.clear();
     for(int i =0;i<laengeLauflicht;i++){
          Pixel.setPixelColor((lEDNrNight+i)%anzLEDs, Pixel.Color(0, 255, 0));
                              
          Pixel.setPixelColor(anzLEDs-1-(lEDNrNight-i)%anzLEDs, Pixel.Color(0, 0, 255));


            
          }
          LEDNr = (LEDNr +1)%anzLEDs;
     letzteZeit = millis();


     
     }
     
}

  
void nightRider() {
   if(millis()>letzteZeit+zeitSchritt) {
     lEDNrNight = lEDNrNight + richtung;
     
     if((lEDNrNight == 0) || (lEDNrNight == anzLEDs /2 - 1)){
      richtung = -richtung;
     }
     Pixel.clear();
     Pixel.setPixelColor(lEDNrNight, Pixel.Color(0, 255, 255));
     Pixel.setPixelColor(anzLEDs-1-lEDNrNight, Pixel.Color(0, 255, 255));
     letzteZeit = millis();
     }
     
}
