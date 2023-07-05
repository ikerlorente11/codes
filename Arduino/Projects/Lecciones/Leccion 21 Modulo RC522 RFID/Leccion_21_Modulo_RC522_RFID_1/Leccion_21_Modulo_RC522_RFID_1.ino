/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que muestra en monitor serie un mensaje de bienvenida o de acceso denegado a la tarjeta o llavero del kit RFID RC522 activo. 
  Se activa el UID de la tarjeta o del llavero con el valor leido en programa anterior
  Requiere instalar libreria MFRC522
  
*/

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

int pinRST = 5;
int pinSS = 53;

MFRC522 mfrc522(pinSS, pinRST); // crea objeto mfrc522 enviando pines de slave select y reset

byte LecturaUID[4];         // crea array para almacenar el UID leido
byte Usuario1[4] = {03, 00, 195, 20} ;   // UID de tarjeta leido en programa 1
byte Usuario2[4] = {140, 146, 74, 73} ;   // UID de llavero leido en programa 1
//byte Usuario2[4]= {0x07, 0x29, 0xB7, 0x60} ;    // UID del llavero leido en programa anterior 

void setup() {
  Serial.begin(9600);     // inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init();     // inicializa modulo lector
  Serial.println("El sistema está listo");    // Muestra texto Listo
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())   // si no hay una tarjeta presente
    return;           // retorna al loop esperando por una tarjeta
  
  if ( ! mfrc522.PICC_ReadCardSerial())     // si no puede obtener datos de la tarjeta
    return;           // retorna al loop esperando por otra tarjeta
    
    Serial.print("El UID es:");       // muestra texto UID:
    for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
      if (mfrc522.uid.uidByte[i] < 0x10){   // si el byte leido es menor a 0x10
        Serial.print(" 0");       // imprime espacio en blanco y numero cero
        }
        else{           // sino
          Serial.print(" ");        // imprime un espacio en blanco
          }
          Serial.print(mfrc522.uid.uidByte[i], HEX);    // imprime el byte del UID leido en hexadecimal
          LecturaUID[i]=mfrc522.uid.uidByte[i];     // almacena en array el byte del UID leido      
          }
          
          Serial.print("\t");         // imprime un espacio de tabulacion             
                    
          if(comparaUID(LecturaUID, Usuario1))    // llama a funcion comparaUID con Usuario1
            Serial.println("Bienvenido Usuario Tarjeta"); // si retorna verdadero muestra texto bienvenida
          else if(comparaUID(LecturaUID, Usuario2)) // llama a funcion comparaUID con Usuario2
            Serial.println("Bienvenido Usuario Llavero"); // si retorna verdadero muestra texto bienvenida
           else           // si retorna falso
            Serial.println("Acceso denegado");    // muestra texto equivalente a acceso denegado          
                  
                  mfrc522.PICC_HaltA();     // detiene comunicacion con tarjeta                
}

boolean comparaUID(byte lectura[],byte usuario[]) // funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){    // bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])        // si byte de UID leido es distinto a usuario
    return(false);          // retorna falso
  }
  return(true);           // si los 4 bytes coinciden retorna verdadero
}
