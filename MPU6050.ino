#include <Wire.h>

const int MPU_addr = 0x68;  // I2C address of MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int ledPin = 13;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // Wake up MPU6050
  Wire.endTransmission(true);

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // Starting register for accelerometer data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);  

  // Read accelerometer, temp, gyro
  AcX = Wire.read() << 8 | Wire.read();  
  AcY = Wire.read() << 8 | Wire.read();  
  AcZ = Wire.read() << 8 | Wire.read();  
  Tmp = Wire.read() << 8 | Wire.read();  
  GyX = Wire.read() << 8 | Wire.read();  
  GyY = Wire.read() << 8 | Wire.read();  
  GyZ = Wire.read() << 8 | Wire.read();  

  // Print values
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.println(AcZ);

  // ---------- Condition ----------
  // Example: Turn LED ON if tilt on X-axis is strong
  if (AcX > 15000 || AcX < -15000) {
    digitalWrite(ledPin, HIGH);
    Serial.println("⚠ Tilt detected on X-axis!");
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
