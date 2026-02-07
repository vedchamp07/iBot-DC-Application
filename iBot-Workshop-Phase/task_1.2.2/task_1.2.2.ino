/*
LCD VSS - GND
LCD VDD - 5V
LCD V0  - Potentiometer middle pin (outer pins - 5V and GND)
LCD RS  - Arduino pin 12
LCD RW  - GND
LCD E   - Arduino pin 11
LCD D4  - Arduino pin 5
LCD D5  - Arduino pin 4
LCD D6  - Arduino pin 3
LCD D7  - Arduino pin 2
LCD A   - 5V
LCD K   - GND
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print("iBot Club");
}

void loop() {
}
