#include <DHT.h>

#define DHTPIN 23
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int temperature;
int humidity;

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  printInfo(humidity, temperature);

  delay(5000); // wait between measurements
}

void printInfo(int humidity, int temperature) {
  Serial.printf("Temperature: %dºC", temperature);
  Serial.println();
  Serial.printf("Humidity: %d%%", humidity);
  Serial.println();
}
