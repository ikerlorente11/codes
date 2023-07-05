/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que utiliza el modulo KY-002 para encender un LED cuando el sensor detecta un golpe o vibracion fuerte
   El sensor brinda un nivel logico bajo cuando detecta la vibracion.
*/

//Declaracion de variables constantes
int pinSensor = 2;      // pin S de modulo a pin 2
int pinLed = 3;      // anodo de LED a pin 3
int valEstado;     // variable almacena valor leido de pin 2

void setup(){
  pinMode(pinSensor, INPUT);  // pin 2 como entrada
  pinMode(pinLed, OUTPUT);   // pin 3 como salida
}


void loop(){
  valEstado = digitalRead(pinSensor); // lee valor de pin 2
  digitalWrite(pinLed, !valEstado); // escribe en LED el valor opuesto del leido
}
