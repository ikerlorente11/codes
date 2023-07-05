/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que identifica el usuario (tarjeta o llavero del kit) y hace parpadear un led RGB con diferente color según que usuario sea
  y parpadeo rojo si no tiene acceso. También muestra en el monitor serie un saludo de bienvenida. 

*/

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

int pinRST = 5;
int pinSS = 53;

int pinRojo = 8;    // pin que aciva el anodo del LED rojo
int pinAzul = 9;   // pin que aciva el anodo del LED azul
int pinVerde = 10;    // pin que aciva el anodo del LED verde

MFRC522 mfrc522(pinSS, pinRST); // crea objeto mfrc522 enviando pines de slave select y reset

byte LecturaUID[4];         // crea array para almacenar el UID leido
byte Usuario1[4] = {03, 00, 195, 20} ;   // UID de tarjeta leido en programa 1
byte Usuario2[4] = {140, 146, 74, 73} ;   // UID de llavero leido en programa 1

void setup() {
  Serial.begin(9600);     // inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init();     // inicializa modulo lector
  Serial.println("El sistema está listo");    // Muestra texto Listo
  Serial.println("  "); 
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())   // si no hay una tarjeta presente
    return;           // retorna al loop esperando por una tarjeta

  if ( ! mfrc522.PICC_ReadCardSerial())     // si no puede obtener datos de la tarjeta
    return;           // retorna al loop esperando por otra tarjeta

  for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
    if (mfrc522.uid.uidByte[i] < 0x10) {  // si el byte leido es menor a 0x10
    }
    LecturaUID[i] = mfrc522.uid.uidByte[i];   // almacena en array el byte del UID leido
  }

  if (comparaUID(LecturaUID, Usuario1)) {  // llama a funcion comparaUID con Usuario1
    Serial.println("Bienvenido Usuario Tarjeta"); // si retorna verdadero muestra texto bienvenida
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 255); // enciende verde
    analogWrite(pinAzul, 0);
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0); // apaga verde
    analogWrite(pinAzul, 0);
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 255); // enciende verde
    analogWrite(pinAzul, 0);
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0); // apaga verde
    analogWrite(pinAzul, 0);
  }

  else if (comparaUID(LecturaUID, Usuario2)) { // llama a funcion comparaUID con Usuario2
    Serial.println("Bienvenido Usuario Llavero"); // si retorna verdadero muestra texto bienvenida
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 255);  // enciende azul
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 0);  // apaga azul
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 255); // enciende azul
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 0);// apaga azul
  }
  else           // si retorna falso
  {
    Serial.println("Acceso denegado");    // muestra texto equivalente a acceso denegado
    analogWrite(pinRojo, 255); // enciende rojo
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 0);
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);  // apaga rojo
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 0);
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 255);  // enciende rojo
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 0);
    delay(500);      // demora de 0.5 seg.
    analogWrite(pinRojo, 0);  // apaga rojo
    analogWrite(pinVerde, 0);
    analogWrite(pinAzul, 0);
  }
  mfrc522.PICC_HaltA();     // detiene comunicacion con tarjeta
}

boolean comparaUID(byte lectura[], byte usuario[]) // funcion comparaUID
{
  for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
    if (lectura[i] != usuario[i])       // si byte de UID leido es distinto a usuario
      return (false);         // retorna falso
  }
  return (true);          // si los 4 bytes coinciden retorna verdadero
}
