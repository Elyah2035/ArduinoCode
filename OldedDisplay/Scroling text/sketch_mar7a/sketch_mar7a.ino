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
int bla = 0;

void loop(){
// put your main code here, to run repeatedly:


display.clearDisplay();
display.setTextSize (2);
display.setTextColor(WHITE);
display.setCursor(bla, 50);
display.print("banna");





bla++;
if(bla>150) bla=-50;


delay(10);
}