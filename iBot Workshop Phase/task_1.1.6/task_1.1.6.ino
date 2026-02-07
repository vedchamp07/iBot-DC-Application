#define flame 9
void setup() {
  pinMode(flame, INPUT);
  Serial.begin(9600);

}
bool reading;
void loop() {
  reading = digitalRead(flame);
  Serial.println(reading);
  delay(500);
}
