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
#define ldr 9
#define buzzer 10

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

bool reading;
void loop() {
  reading = digitalRead(ldr);

  if(reading){
    lcd.clear();
    tone(buzzer, 1000);
    lcd.setCursor(0, 0);
    lcd.print("Interference");
    lcd.setCursor(0, 1);
    lcd.print("Detected");
  }
  else{
    lcd.clear();
    noTone(buzzer);
    lcd.setCursor(0, 0);
    lcd.print("No");
    lcd.setCursor(0, 1);
    lcd.print("Interference");
  }
}
