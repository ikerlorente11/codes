/*
 * Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
 * Programa que enciende o apaga el LED integrado en la placa Arduino.
 * Si se envía ‘a’ a la placa Arduino apaga el LED, y en caso de enviar ‘b’ lo enciende
 */


int option;
int led = LED_BUILTIN;
const int buttonPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  Serial.println(digitalRead(buttonPin));
}
