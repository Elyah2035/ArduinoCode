#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>
#define screen_width 128 //OLED display width in pixels #define screen height 64 //OLED display height in pixels
#define screen_hight 64
Adafruit_SSD1306 display(screen_width, screen_hight);
void setup () {
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
pinMode(2,OUTPUT);


}
int bla = 5;
void loop(){
// put your main code here, to run repeatedly:


display.clearDisplay();
display.setTextSize (1);
display.setTextColor(WHITE);
display.setCursor(0, 0);
display.println(bla);
display.setCursor(40, 40);
display.display();
delay(1000);
bla--;

if(bla<=0){
  digitalWrite(2,HIGH);

bla=0;

}
}