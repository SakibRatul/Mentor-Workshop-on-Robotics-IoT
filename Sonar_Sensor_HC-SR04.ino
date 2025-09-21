#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Clear TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10µs pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure ECHO response
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  // Print value
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Simple condition check
  if (distance < 10) {
    Serial.println("Condition: Object is TOO CLOSE!");
  } else {
    Serial.println("Condition: Safe distance.");
  }

  delay(1000); // 1 second delay
}
