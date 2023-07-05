/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que enciende el led correspondiente al número tecleado 1 rojo, 2 verde, 3 amarillo,
   4 naranja, 5 azul, 6 blanco y el 0 apaga todos.
*/

#include <IRremote.h>


// Inicializamos variables
const int pinReceptor = 2;
const int pinRojo = 3;
const int pinVerde = 4;
const int pinAmarillo = 5;
const int pinNaranja = 6;
const int pinAzul = 7;
const int pinBlanco = 8;

int v;


IRrecv irrecv(pinReceptor); //SE CREA EL OBJETO IR
decode_results results;     //SE CREA LA VARIABLE PARA GUARDAR EL VALOR

void setup() {
  irrecv.enableIRIn();        // Se Inicializa el receptor

  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinNaranja, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  pinMode(pinBlanco, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) { //SE LEE VALOR DEL RECEPTOR
    v = results.value; // SE OBTIENE VALOR NUMERICO DE LA LECTURA
    irrecv.resume(); //SE LIBERA RECEPTOR
  }

  // DE ACUERDO AL VALOR RECIBIDO SE ENCIENDE O SE APAGA LED SEGUN EL VALOR
  switch (v) {
    case 0xFF30CF: // Si pulsas el botón 1 se enciende el led rojo
      digitalWrite(pinRojo, HIGH);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinNaranja, LOW);
      digitalWrite(pinAzul, LOW);
      digitalWrite(pinBlanco, LOW);
      break;

    case 0xFF18E7: // Si pulsas el botón 2 se enciende el led verde
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, HIGH);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinNaranja, LOW);
      digitalWrite(pinAzul, LOW);
      digitalWrite(pinBlanco, LOW);
      break;

    case 0xFF7A85: // Si pulsas el botón 3 se enciende el led amarillo
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAmarillo, HIGH);
      digitalWrite(pinNaranja, LOW);
      digitalWrite(pinAzul, LOW);
      digitalWrite(pinBlanco, LOW);
      break;

    case 0xFF10EF: // Si pulsas el botón 4 se enciende el led naranja
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinNaranja, HIGH);
      digitalWrite(pinAzul, LOW);
      digitalWrite(pinBlanco, LOW);
      break;

    case 0xFF38C7: // Si pulsas el botón 5 se enciende el led azul
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinNaranja, LOW);
      digitalWrite(pinAzul, HIGH);
      digitalWrite(pinBlanco, LOW);
      break;

    case 0xFF5AA5: // Si pulsas el botón 6 se enciende el led blanco
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinNaranja, LOW);
      digitalWrite(pinAzul, LOW);
      digitalWrite(pinBlanco, HIGH);
      break;
    case 0xFF6897: // Si pulsas el botón 0 se apagan todos los led
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinVerde, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinNaranja, LOW);
      digitalWrite(pinAzul, LOW);
      digitalWrite(pinBlanco, LOW);
      break;
    
  }// End Case
}
