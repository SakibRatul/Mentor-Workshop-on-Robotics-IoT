int pirPin = 2;       // PIR sensor OUT pin
int ledPin = 13;      // LED pin
int pirState = LOW;   // Default state = no motion
int val = 0;          // Sensor value

void setup() {
  pinMode(pirPin, INPUT);   // PIR as input
  pinMode(ledPin, OUTPUT);  // LED as output
  Serial.begin(9600);       // For debugging
}

void loop() {
  val = digitalRead(pirPin);  // Read PIR output

  if (val == HIGH) {          // Motion detected
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;        // Update state
    }
  } 
  else {                      // No motion
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;         // Update state
    }
  }
}
