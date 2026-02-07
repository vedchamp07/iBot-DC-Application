#define ldr A0

void setup() {
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}
int reading;

void loop() {
  reading = analogRead(ldr);
  Serial.println(reading);
  delay(200);
}
