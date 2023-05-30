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
int bla;
void loop() {
display.clearDisplay();

display.drawLine(64, 0, 64+16,32, WHITE);
display.drawLine(64-16,32, 64, 0, WHITE);


display.drawRect((128/2)-(32/2), 32, 32, 32, WHITE);
display.drawRect((128/2)-(32/2), 32, 32, 32, WHITE);

display.drawLine(32+16, 32, (128/2)+16, 64, WHITE);
display.drawLine(32+16, 64,64+16, 32, WHITE);
display.display();

}
