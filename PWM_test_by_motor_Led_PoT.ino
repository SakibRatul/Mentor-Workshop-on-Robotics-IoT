int potPin = A0;   // Potentiometer connected to A0
int ledPin = 9;    // LED connected to PWM pin 9
int potValue = 0;  // Variable to store potentiometer value
int ledValue = 0;  // Variable for LED brightness (0–255)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read potentiometer value (0–1023)
  potValue = analogRead(potPin);

  // Map it to PWM range (0–255)
  ledValue = map(potValue, 0, 1023, 0, 255);

  // Write PWM signal to LED
  analogWrite(ledPin, ledValue);

  // Small delay for stability
  delay(10);
}
