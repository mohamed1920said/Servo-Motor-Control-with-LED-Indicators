#include <Servo.h>

Servo myservo;  // Création d'un objet servomoteur
int potPin = A0;  // Pin où est connecté le potentiomètre
int val = 0;  // Variable pour lire la valeur du potentiomètre

// Définir les pins pour les LED et les boutons poussoirs
const int ledRougePin = 2;
const int ledVertePin = 3;
const int boutonRougePin = 4;
const int boutonVertePin = 5;
const int boutonEteindrePin = 6;

void setup() {
  myservo.attach(9);  // Attacher le servomoteur à la pin 9
  
  pinMode(ledRougePin, OUTPUT);  // Définir la pin de la LED rouge comme une sortie
  pinMode(ledVertePin, OUTPUT);  // Définir la pin de la LED verte comme une sortie
  pinMode(boutonRougePin, INPUT_PULLUP);  // Définir la pin du bouton rouge comme une entrée avec résistance de pull-up interne
  pinMode(boutonVertePin, INPUT_PULLUP);  // Définir la pin du bouton verte comme une entrée avec résistance de pull-up interne
  pinMode(boutonEteindrePin, INPUT_PULLUP);  // Définir la pin du bouton d'extinction comme une entrée avec résistance de pull-up interne
}

void loop() {
  // Lire la valeur du potentiomètre
  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 180);  // Convertir la valeur en une plage de 0 à 180 degrés
  myservo.write(val);  // Déplacer le servomoteur à la position correspondante

  // Lire l'état des boutons poussoirs
  bool boutonRougeEtat = digitalRead(boutonRougePin) == LOW;  // LOW signifie que le bouton est pressé
  bool boutonVerteEtat = digitalRead(boutonVertePin) == LOW;  // LOW signifie que le bouton est pressé
  bool boutonEteindreEtat = digitalRead(boutonEteindrePin) == LOW;  // LOW signifie que le bouton est pressé

  if (boutonRougeEtat) {
    digitalWrite(ledRougePin, HIGH);  // Allumer la LED rouge
    digitalWrite(ledVertePin, LOW);  // Éteindre la LED verte pour s'assurer qu'une seule LED est allumée à la fois
  }

  if (boutonVerteEtat) {
    digitalWrite(ledVertePin, HIGH);  // Allumer la LED verte
    digitalWrite(ledRougePin, LOW);  // Éteindre la LED rouge pour s'assurer qu'une seule LED est allumée à la fois
  }

  if (boutonEteindreEtat) {
    digitalWrite(ledRougePin, LOW);  // Éteindre la LED rouge
    digitalWrite(ledVertePin, LOW);  // Éteindre la LED verte
  }
}
