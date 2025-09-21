#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC!");
    while (1);
  }

  // Uncomment once if you want to set RTC to the compile time
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();  // Read current time & date

  // Print date
  Serial.print("Date: ");
  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.println(now.year());

  // Print time
  Serial.print("Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  // Simple condition
  if (now.hour() >= 12) {
    Serial.println("Condition: It's Afternoon/Evening!");
  } else {
    Serial.println("Condition: It's Morning!");
  }

  Serial.println("------------------------");

  delay(1000); // wait 1 sec
}
