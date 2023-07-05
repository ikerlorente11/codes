/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que permite encender un led mediante el sensor de movimiento PIR.
*/


int pinPir = 3;       // Señal deL PIR a pin 3
int pinLed = 4;       // Entrada del led al pin 4
int valEstado = 0;    // Almacena estado de señal

void setup() {
  pinMode(pinPir, INPUT);   // pin 2 como entrada
  pinMode(pinLed, OUTPUT);  // pin 3 como salida
  delay(5000);              // demora para estabilizar el sensor
}

void loop() {

  valEstado = digitalRead(pinPir);  // lectura de estado de señal

  if (valEstado == HIGH) {          // Si la señal esta en alto indicando movimiento
    digitalWrite(pinLed, HIGH );    // Enciende el led al detectar movimiento
    delay(2000);                    // Demora de 2 segundos
  } else {
    digitalWrite(pinLed, LOW);      // Apaga el LED si no detecta movimiento
  }
}
