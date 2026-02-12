/*
OLED SDA -> Arduino A4 (SDA)
OLED SCL -> Arduino A5 (SCL)
OLED VCC -> 5V or 3.3V (check module)
OLED GND -> GND
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Display text
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Hello World");

  // Draw shapes
  display.drawRect(10, 20, 50, 30, SSD1306_WHITE); // (x, y, width, height)
  display.drawCircle(80, 50, 10, SSD1306_WHITE); //(x, y, radius)
  display.display();
}

void loop() {
}
