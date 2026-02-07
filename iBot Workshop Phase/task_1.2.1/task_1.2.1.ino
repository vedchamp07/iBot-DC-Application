#define buzzer 9

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  tone(buzzer, 440); delay(500);
  tone(buzzer, 660); delay(500);
  tone(buzzer, 880); delay(500);
  tone(buzzer, 660); delay(500);
  tone(buzzer, 440); delay(500);
  noTone(buzzer); 
  delay(1000);

}
