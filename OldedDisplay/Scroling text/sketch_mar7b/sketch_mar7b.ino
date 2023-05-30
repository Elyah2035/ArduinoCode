#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Scrolling");
  display.println("Text");
  display.display();

  display.startscrollright(0, 0);
  delay(3000);
  display.stopscroll();
  display.startscrollleft(0, 0);
  delay(3000);
  display.stopscroll();
  display.startscrollright(1, 1);
  delay(3000);
  display.stopscroll();
  display.startscrollleft(1, 1);
  delay(3000);
  display.stopscroll();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Scrolling");
  display.println("Display");
  display.display();

  display.startscrolldiagright(0, 7);
  delay(5000);
  display.stopscroll();
  display.startscrolldiagleft(0, 7);
  delay(5000);
  display.stopscroll();
}
void loop() {
}