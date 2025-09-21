#define LM35_PIN A0  // LM35 output connected to A0

void setup() {
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Read analog value (0–1023)
  int analogValue = analogRead(LM35_PIN);

  // Convert to voltage (5V reference, 10-bit ADC)
  float voltage = (analogValue * 5.0) / 1023.0;

  // LM35 outputs 10mV per °C → Temp = (voltage * 100)
  float temperatureC = voltage * 100;

  // Print value
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Simple condition
  if (temperatureC > 30) {
    Serial.println("Condition: Temperature is HIGH!");
  } else {
    Serial.println("Condition: Temperature is NORMAL.");
  }

  delay(1000); // wait 1 second before next reading
}
