/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que permite verificar el funcionamiento de un modulo de rele, simple o
   doble activandolo a intervalos de 5 segundos, encendiendo y apagando un led.
   Y mostrando el estado del rele en el monitor serie
*/

int pinRele = 2;      // pin IN de modulo a pin digital 2 de Arduino


void setup() {
  pinMode(pinRele, OUTPUT);  // pin 2 como salida
  Serial.begin(9600);      // inicializacion de comunicacion serial a 9600 bps
}

void loop() {
  digitalWrite(pinRele, LOW);  // activacion del modulo de rele con un nivel bajo
  Serial.print("Pin de la señal del rele en estado LOW-BAJO");
  Serial.print('\t'); 
  Serial.println("Señal de la parte de alta ACTIVA");
  delay(5000);      // demora de 5 seg.

  digitalWrite(pinRele, HIGH); // apagado del modulo de rele con un nivel alto
  Serial.println("Pin de la señal del rele en estado HIGH-ALTO");
  delay(5000);      // demora de 5 seg.
}
