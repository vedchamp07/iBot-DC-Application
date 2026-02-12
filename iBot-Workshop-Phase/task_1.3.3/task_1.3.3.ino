/*
OLED SDA -> Arduino A4 (SDA)
OLED SCL -> Arduino A5 (SCL)
OLED VCC -> 5V or 3.3V (check module)
OLED GND -> GND

Audio Sensor VCC -> 5V
Audio Sensor GND -> GND
Audio Sensor OUT -> Arduino A0
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define AUDIO_PIN A0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  pinMode(AUDIO_PIN, INPUT);
  
  // Display initial message
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20, 28);
  display.print("Audio Visualizer");
  display.display();
  delay(2000);
}

void loop() {
  // Read audio sensor value
  int audioValue = analogRead(AUDIO_PIN);
  
  // Map audio value to bar height (0-1023 mapped to 0-32 pixels each direction)
  int barHeight = map(audioValue, 0, 1023, 0, 32);
  
  // Clear display
  display.clearDisplay();
  
  // Draw center horizontal reference line
  display.drawLine(0, 32, 127, 32, SSD1306_WHITE);
  
  // Draw vertical bar in center expanding from middle
  int centerX = SCREEN_WIDTH / 2;
  
  // Draw bar expanding up and down from center
  display.fillRect(centerX - 2, 32 - barHeight, 4, barHeight * 2, SSD1306_WHITE);
  
  // Update display
  display.display();
  
  delay(50); // Small delay for readability
}