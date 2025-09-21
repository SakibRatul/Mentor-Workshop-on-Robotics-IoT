#include "DHT.h"

#define DHTPIN 2        // Pin where the DHT11 is connected
#define DHTTYPE DHT11   // Using DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read humidity and temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if reading failed
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print readings
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");

  // Simple condition check
  if (t > 30) {
    Serial.println("Condition: Temperature is HIGH!");
  } else {
    Serial.println("Condition: Temperature is NORMAL.");
  }

  delay(2000); // wait 2 seconds before next reading
}
