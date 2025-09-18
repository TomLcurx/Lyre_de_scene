#include <Arduino.h>
#include <IBusBM.h>

IBusBM ibus;   // objet pour gérer le protocole IBUS

// === Classe pour un moteur pas à pas ===
class StepperMotor {
private:
    int stepPin;
    int dirPin;

public:
    StepperMotor(int sPin, int dPin) {
        stepPin = sPin;
        dirPin = dPin;
        pinMode(stepPin, OUTPUT);
        pinMode(dirPin, OUTPUT);
    }

    void moveSteps(int steps, bool dir) {
        digitalWrite(dirPin, dir);
        for (int i = 0; i < steps; i++) {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(800);  // vitesse moteur
            digitalWrite(stepPin, LOW);
            delayMicroseconds(800);
        }
    }
};

// === Classe pour la télécommande ===
class Telecommande {
public:
    int throttle;
    int roll;
    int pitch;
    int bouton;

    void lireCanaux() {
        throttle = ibus.readChannel(2); // canal 3 : throttle
        roll     = ibus.readChannel(0); // canal 1 : roll
        pitch    = ibus.readChannel(1); // canal 2 : pitch
        bouton   = ibus.readChannel(4); // canal 5 : bouton (switch)
    }

    void afficherEtat() {
        Serial.print("Throttle: "); Serial.print(throttle);
        Serial.print(" | Roll: "); Serial.print(roll);
        Serial.print(" | Pitch: "); Serial.print(pitch);
        Serial.print(" | Bouton: "); Serial.println(bouton);
    }
};

// === Création des objets ===
StepperMotor moteurPan(25, 26);   // PAN (axe horizontal) → pins ESP32 à adapter
StepperMotor moteurTilt(27, 14);  // TILT (axe vertical) → pins ESP32 à adapter
Telecommande radio;

void setup() {
    Serial.begin(115200);
    ibus.begin(Serial2, 16, 17);  // RX=16, TX=17 (TX inutilisé ici)
}

void loop() {
    radio.lireCanaux();
    radio.afficherEtat();

    // Contrôle PAN
    if (radio.roll > 1600) {
        moteurPan.moveSteps(5, true);  // droite
    } else if (radio.roll < 1400) {
        moteurPan.moveSteps(5, false); // gauche
    }

    // Contrôle TILT
    if (radio.pitch > 1600) {
        moteurTilt.moveSteps(5, true); // haut
    } else if (radio.pitch < 1400) {
        moteurTilt.moveSteps(5, false);// bas
    }

    // Bouton ON/OFF
    if (radio.bouton > 1500) {
        Serial.println("Bouton activé → Allumer la lyre !");
    }

    delay(20); // lis un peu plus fluide
}
