#define trig_pin 9
#define echo_pin 10

double timing = 0.0;
double distance = 0.0;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  timing = pulseIn(echo_pin, HIGH); // in microseconds
  distance = (343 * timing)/(2*10000);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
