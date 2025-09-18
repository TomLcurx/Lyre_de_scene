#include <Arduino.h>
#include <IBusBM.h>

IBusBM ibus; // objet iBus

#define CH_ROLL     0     // Roll
#define CH_PITCH    1     // Pitch
#define CH_THROTTLE 2     // Throttle
#define maxpas      3600  // Max de pas du stepper
#define PIN_RX      17    // Pin de RX de la carte

void setup() {
  Serial.begin(115200);
  delay(500);

  ibus.begin(Serial2, 115200, PIN_RX); 

  Serial.println("Lecture iBus (FS-iA6B) démarrée...");
}

void loop() {
  ibus.read();

  int roll     = ibus.readChannel(CH_ROLL);
  int pitch    = ibus.readChannel(CH_PITCH);
  int throttle = ibus.readChannel(CH_THROTTLE);

  int rollMapped     = map(roll, 1000, 2000, 0, maxpas);
  int pitchMapped    = map(pitch, 1000, 2000, 0, maxpas);
  int throttleMapped = map(throttle, 1000, 2000, 0, maxpas);

  Serial.print("Roll: "); Serial.print(rollMapped);
  Serial.print("\tPitch: "); Serial.print(pitchMapped);
  Serial.print("\tThrottle: "); Serial.print(throttleMapped);
  Serial.println("%");

  delay(100);
}
