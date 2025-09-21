// LED pins (use PWM pins only)
int ledPins[] = {3, 5, 6, 9};
int numLeds = 4;

int potPin = A0;   // Potentiometer pin
int potValue = 0;  // Raw potentiometer value
int speedDelay = 0; // Speed control

void setup() {
  // Set LED pins as output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read potentiometer (0–1023)
  potValue = analogRead(potPin);

  // Map potentiometer to delay speed (fast ↔ slow)
  speedDelay = map(potValue, 0, 1023, 5, 50);

  // Fade LEDs one by one (matrix-like effect)
  for (int i = 0; i < numLeds; i++) {
    // Fade in
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(ledPins[i], brightness);
      delay(speedDelay);
    }

    // Fade out
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(ledPins[i], brightness);
      delay(speedDelay);
    }
  }
}
