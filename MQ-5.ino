int sensorPin = A0;     // MQ-05 analog output pin
int ledPin = 13;        // LED pin
int sensorValue = 0;    // Variable to store sensor reading
int threshold = 100;    // Gas detection threshold (adjust as needed)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("MQ-05 Gas Sensor Test Starting...");
}

void loop() {
  // Read sensor value (0–1023)
  sensorValue = analogRead(sensorPin);

  // Print value
  Serial.print("MQ-05 Sensor Value: ");
  Serial.println(sensorValue);

  // Condition check
  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    Serial.println("⚠ Gas Detected!");
  } else {
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    Serial.println("Air is Clean");
  }

  delay(500); // Small delay for stability
}
