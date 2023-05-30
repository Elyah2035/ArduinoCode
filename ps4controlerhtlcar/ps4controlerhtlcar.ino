
#include <PS4Controller.h>

#define RXp2 12
#define TXp2 13



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  PS4.begin("3c:a6:f6:38:82:58");
  Serial.println("Ready.");
}
void loop() {

  if (PS4.isConnected()) {
    if (PS4.UpRight()) Serial2.println("G");
    if (PS4.DownRight()) Serial2.println("R");


 if (PS4.R2Value()){
      Serial2.write("V ");
      Serial2.print(PS4.R2Value());
      Serial2.write("\n");
      delay(10);
 }
  else{
      Serial2.write("V ");
      Serial2.print("0");
      Serial2.write("\n");
      delay(10);
  }


   if (PS4.RStickX()) {

      float normalizedValue = ((float)PS4.RStickX() + 128) / 255.0;
      float mappedValue = normalizedValue * 19.62 - 9.81;

      Serial2.write("Y ");
      Serial2.print(mappedValue);
      Serial2.write("\n");
            delay(10);
   


    if(mappedValue<=0.5){
      Serial2.write("Y ");
      Serial2.print(bla);
      Serial2.write("\n");
            delay(10);
    }}

 


      // if (PS4.LStickX()) {
      //   Serial2.printf("V %d\n", PS4.LStickX());
      // }
      // if (PS4.LStickY()) {
      //   Serial2.printf("Left Stick y at %d\n", PS4.LStickY());
      // }
    }
  }