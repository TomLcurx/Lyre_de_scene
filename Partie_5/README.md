# Partie 5 : Code orienté objet (C++)

## But
Réécriture du code complet en C++ orienté objet, pour une meilleure organisation et modularité, conformément aux recommandations de Robz.  
Chaque fonctionnalité est encapsulée dans une classe.

## Fichier principal
- `main_oop.cpp`

## Structure des classes
- `Stepper` : gestion d’un moteur pas-à-pas
- `AccelStepper` : gestion de l’accélération/décélération
- `IBus` : communication avec la télécommande
- `Controller` : gestion globale du système

## Instructions
1. Compiler :
   ```bash
   g++ main_oop.cpp -o main_oop
