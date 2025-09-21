// Motor A connections
int enA = 9;   // PWM pin for Motor A speed control
int in1 = 2;   // Direction pin 1
int in2 = 3;   // Direction pin 2

// Motor B connections
int enB = 10;  // PWM pin for Motor B speed control
int in3 = 4;   // Direction pin 1
int in4 = 5;   // Direction pin 2

void setup() {
  // Set all the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Ensure motors are stopped at start
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Enable pins start at 0 (no speed)
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void loop() {
  // --------- Forward motion ---------
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Ramp up speed
  for (int speed = 0; speed <= 255; speed += 25) {
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    delay(500);
  }

  delay(1000);

  // Ramp down speed
  for (int speed = 255; speed >= 0; speed -= 25) {
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    delay(500);
  }

  delay(1000);

  // --------- Reverse motion ---------
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Ramp up reverse speed
  for (int speed = 0; speed <= 255; speed += 25) {
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    delay(500);
  }

  delay(1000);

  // Ramp down reverse speed
  for (int speed = 255; speed >= 0; speed -= 25) {
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    delay(500);
  }

  delay(2000);
}
