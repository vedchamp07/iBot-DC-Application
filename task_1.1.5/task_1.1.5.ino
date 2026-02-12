#define sound A0

void setup() {
  pinMode(sound, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

int reading;

void loop() {
  reading = digitalRead(sound);
  Serial.println(reading);
  if(reading){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(10);
}
