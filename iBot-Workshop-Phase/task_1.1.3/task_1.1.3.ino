#define pir 3

void setup() {
  pinMode(pir, INPUT);
  Serial.begin(9600);
}

int reading = 0;
int prev_reading = 0;
unsigned long start_millis;
unsigned long end_millis;

void loop() {
  reading = digitalRead(pir);
  if(reading && !prev_reading){
    start_millis = millis();
    Serial.println("OBJECT DETECTED");
  }
  
  if(!reading && prev_reading){
    end_millis = millis();
    Serial.println("SENSOR HAS TURNED OFF");
    Serial.print("HOLD TIME: ");
    Serial.println(end_millis - start_millis);
  }
  
  prev_reading = reading;
  
}
