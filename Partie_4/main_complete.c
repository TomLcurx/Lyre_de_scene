#include <Arduino.h>
#include <IBusBM.h>

IBusBM ibus; // objet pour gérer le protocole IBUS

void setup() {
    Serial.begin(115200);           // pour afficher les infos
    ibus.begin(Serial2, 16, 17);    // RX=16 (connecté au IBUS du récepteur), TX=17 (non utilisé)
}

void loop() {
    // Mettre à jour les valeurs du récepteur
    ibus.read();  // lire les données IBUS

    // Afficher tous les canaux
    Serial.print("Canal 1: "); Serial.print(ibus.readChannel(0));
    Serial.print(" | Canal 2: "); Serial.print(ibus.readChannel(1));
    Serial.print(" | Canal 3: "); Serial.print(ibus.readChannel(2));
    Serial.print(" | Canal 4: "); Serial.print(ibus.readChannel(3));
    Serial.print(" | Canal 5: "); Serial.print(ibus.readChannel(4));
    Serial.print(" | Canal 6: "); Serial.print(ibus.readChannel(5));
    Serial.print(" | Canal 7: "); Serial.print(ibus.readChannel(6));
    Serial.print(" | Canal 8: "); Serial.println(ibus.readChannel(7));

    delay(1000); // attendre 1 seconde avant de réafficher
}
