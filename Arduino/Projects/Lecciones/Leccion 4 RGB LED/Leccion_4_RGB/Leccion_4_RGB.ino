/*
 * Practicas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingenieria de Vitoria-Gasteiz.
 * Programa que enciende un LED RGB conectado a los pines 3, 5 y 6.   
 * Para proteger al led hay que colocar una resistencia en serie con el de 330 ohmios.   
 * Se muestran los colores basicos ROJO, VERDE, AZUL, AMARILLO, CYAN y MAGENTA.
 */



int pinRojo = 6;    // pin 6 a anodo LED rojo
int pinVerde = 5;    // pin 5 a anodo LED verde
int pinAzul = 3;   // pin 6 a anodo LED azul

void setup() {
  pinMode(pinRojo, OUTPUT); // todos los pines como salida
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  analogWrite(pinRojo, 255);            // rojo
  analogWrite(pinVerde, 0);
  analogWrite(pinAzul, 0);
  delay(2000);      // demora de 2 seg.

  analogWrite(pinRojo, 0);
  analogWrite(pinVerde, 255);           // verde
  analogWrite(pinAzul, 0);
  delay(2000);      // demora de 2 seg.

  analogWrite(pinRojo, 0);
  analogWrite(pinVerde, 0);
  analogWrite(pinAzul, 255);            // azul
  delay(2000);      // demora de 2 seg.

  analogWrite(pinRojo, 255);            // amarillo
  analogWrite(pinVerde, 255);
  analogWrite(pinAzul, 0);
  delay(2000);      // demora de 2 seg.

  analogWrite(pinRojo, 0);              // cian
  analogWrite(pinVerde, 255);
  analogWrite(pinAzul, 255);
  delay(2000);      // demora de 2 seg.

  analogWrite(pinRojo, 255);            // magenta
  analogWrite(pinVerde, 0);
  analogWrite(pinAzul, 255);
  delay(2000);      // demora de 2 seg.
}
