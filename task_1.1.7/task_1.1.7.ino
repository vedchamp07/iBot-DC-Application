#include <Adafruit_GFX.h>
#include <DHT.h>

#define dhtpin A0
DHT dht(dhtpin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

double humi, temp;

void loop() {
  humi = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Temperature (C): ");
  Serial.println(temp, 2);

  Serial.print("Humidity (%): ");
  Serial.println(humi, 2);

  delay(1000);
}
