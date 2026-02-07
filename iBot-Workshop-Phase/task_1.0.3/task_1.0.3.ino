#define led 3
#define button 2

bool reading = false;
bool prev_reading = false;
bool output = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  reading = digitalRead(button);
  if(reading && !prev_reading){
    output = !output;
  }
  digitalWrite(led, output);
  prev_reading = reading;
}
