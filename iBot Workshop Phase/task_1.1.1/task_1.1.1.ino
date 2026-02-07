#define ir A0

void setup() {
  pinMode(ir, INPUT);
  Serial.begin(9600);
}
int reading;

void loop() {
  reading = analogRead(ir);
  Serial.println(reading);
  delay(200);
}
