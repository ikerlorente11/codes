/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que enciende un led al presionar el pulsador y lo apaga al presionarlo de nuevo.
*/

int pinPulsador = 2;
int pinLed = 3;
int valEstado = LOW;

void setup() {

  pinMode(pinPulsador, INPUT);  // pin del pulsador como entrada
  pinMode(pinLed, OUTPUT);      // pin del led como salida
  digitalWrite(pinLed, LOW);

}

void loop () {

  while (digitalRead(pinPulsador) == LOW) { // espera hasta que se presione el pulsador
  }

  valEstado = digitalRead(pinLed);      // leo estado del pin del Led para saber si esta encendido o apagado
  digitalWrite(pinLed, !valEstado);     // escribo en la salida el valor apuesto al leido con anterioridad

  while (digitalRead(pinPulsador) == HIGH) { // espera como funcion antirebote simple
  }

}
