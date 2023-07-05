/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que obtiene el UID de la tarjeta o llavero del kit RFID RC522 y lo muestra en monitor serie. Requiere instalar libreria MFRC522
  
*/

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

int pinRST = 5;       // Pin para el RESET del RC522
int pinSS = 53;       // Pin para el SS (SDA) del RC522

MFRC522 mfrc522(pinSS, pinRST); // Crea objeto mfrc522 enviando pines de slave select y reset

void setup() {
  Serial.begin(9600);     // Inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();            // Inicializa el bus SPI
  mfrc522.PCD_Init();     // Inicializa el modulo RFID lector
}

void loop() {
  // Detecta una tarjeta
  if ( ! mfrc522.PICC_IsNewCardPresent())       // Si no hay una tarjeta presente
    return;                                     // Retorna al loop esperando por una tarjeta

  if ( ! mfrc522.PICC_ReadCardSerial())         // Si no puede obtener datos de la tarjeta
    return;                                     // Vuelve al loop esperando por otra tarjeta

  Serial.print("El UID es:");                   // Muestra texto UID:
  for (byte i = 0; i < mfrc522.uid.size; i++) { // Bucle recorre de a un byte por vez el UID
    if (mfrc522.uid.uidByte[i] < 0x10) {        // Si el byte leido es menor a 0x10
      Serial.print(" 0");                       // Imprime espacio en blanco y numero cero
    }
    else {        // sino
      Serial.print(" ");                        // Si es mayor imprime un espacio en blanco
    }
   // Serial.print(mfrc522.uid.uidByte[i], HEX);  // Imprime el byte del UID leido en hexadecimal
     Serial.print(mfrc522.uid.uidByte[i]);  // Imprime el byte del UID leido en hexadecimal
  }
  Serial.println();                             // Nueva linea
  mfrc522.PICC_HaltA();                         // Detiene comunicacion con tarjeta
}
