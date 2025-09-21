#include <SPI.h>
#include <MFRC522.h>

// RC522 pins (Arduino UNO)
#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);

// Change this to your card/tag UID (uppercase, no spaces)
String AUTH_UID = "39C3BB99";

// Forward declaration
bool readID(String &uidUpper);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("RC522 Ready. Tap a card...");
}

void loop() {
  String tagID;
  if (readID(tagID)) {
    Serial.print("Card UID: ");
    Serial.println(tagID);

    if (tagID == AUTH_UID) {
      // Toggle LED on authorized card
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      Serial.println("Access Granted ✅ (LED toggled)");
    } else {
      Serial.println("Access Denied ❌");
      // Optional: force LED off on unauthorized card
      // digitalWrite(LED_PIN, LOW);
    }

    // Simple de-bounce: wait until the card is removed
    // so we don't trigger multiple times for one tap
    delay(150);
    while (mfrc522.PICC_IsNewCardPresent() || mfrc522.PICC_ReadCardSerial()) {
      delay(50);
    }
  }
  // Small idle delay
  delay(20);
}

// Reads a card and returns its UID as uppercase hex in uidUpper.
// Returns true if a new card was read.
bool readID(String &uidUpper) {
  // No new card?
  if (!mfrc522.PICC_IsNewCardPresent()) return false;
  if (!mfrc522.PICC_ReadCardSerial())   return false;

  // Build UID string
  uidUpper = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uidUpper += "0";  // leading zero
    uidUpper += String(mfrc522.uid.uidByte[i], HEX);
  }
  uidUpper.toUpperCase();

  // Halt PICC & stop encryption (good practice)
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  return true;
}
