#include <SoftwareSerial.h>
#include <EEPROM.h>

SoftwareSerial BT(10, 11);  //rx=10 tx=11

char BT_Char = ' ';char BT_ID = ' ';char BT_ID_temp = ' ';bool BT_ID_expected = true;bool BT_newReading = false;
String BT_ValueStr = "";float BT_Value;

int gr;
int gl;

void setup() {
  BT.begin(9600);
  pinMode(2,OUTPUT);//nichtpwm
  pinMode(3,OUTPUT);//pwm
  pinMode(4,OUTPUT);//nichtpwm
  pinMode(5,OUTPUT);//pwm
Serial.begin(9600);
}

void loop() {

  BT_check();
  if(BT_newReading) {
    BT_setValue();
  }
  motorDrehen(3,2,true,gr);
  motorDrehen(5,4,true,gl);
  delay(10);

}

void motorDrehen(int pwmPin,int nichtPwmPin,bool richtung, int geschwin){

//true = vor 
//false = rück

 /* if(richtung == true){
    digitalWrite(nichtPwmPin,LOW);
    analogWrite(pwmPin,geschwin);
  }
  if(richtung == false){
    digitalWrite(nichtPwmPin,HIGH);
    analogWrite(pwmPin,(255-geschwin));
  }
*/

  if(geschwin > 0){
    digitalWrite(nichtPwmPin,LOW);
    analogWrite(pwmPin,geschwin);
  }
  if(geschwin < 0){
    geschwin = (geschwin * (-1));
    digitalWrite(nichtPwmPin,HIGH);
    analogWrite(pwmPin,(255-geschwin));
  }
  
}

void BT_check(){
  BT_newReading = false;
  if(BT.available())
  {
    BT_Char=BT.read();
    Serial.write(BT_Char);
    
    if(BT_ID_expected) { 
      BT_ID_temp = BT_Char;
      BT_ID_expected = false;
      BT_ValueStr = ""; 
    }
    else 
    {
      if( (BT_Char != ' ') && (BT_Char != '\n') ) { 
        BT_ValueStr += BT_Char;
      }
      
      if(BT_Char == '\n') {
        BT_ID = BT_ID_temp;
        BT_Value = BT_ValueStr.toFloat();
        BT_ValueStr = "";
        BT_ID_expected = true;
        BT_newReading = true;
      }
    }
  }
}

void BT_setValue(){
  switch(BT_ID){
    case 'R': {
      gr=BT_Value;
      break;
    }
    case 'L': {
      gl=BT_Value;
      break;
    }
  }
}