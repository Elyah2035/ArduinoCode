#include <SoftwareSerial.h>

SoftwareSerial mySerial = SoftwareSerial(6, 7);

char name;


void setup() {
 Serial.begin(9600);
 mySerial.begin(9600);
 pinMode(8,OUTPUT);

 pinMode(6,INPUT);
 pinMode(7,OUTPUT);
}
int onOff=0;
void loop() {

  
 if (Serial.available() > 0) {
   name = Serial.read();
   if(name == 101 || 97){



 if (Serial.available() > 0) {
   onOff = Serial.read();
   if(onOff!=10){
      
       //Serial.print("Serial:");
       Serial.print(onOff);
       Serial.println();
       //Serial.print("mySerial:");
       mySerial.write(onOff);
       //Serial.println();
        onOff=onOff-48;
       for(int i=0;i<onOff*2;i++){
      digitalWrite(8,!digitalRead(8));
      delay(500);
    }
    
   }
   }
   }

 }

}
    

