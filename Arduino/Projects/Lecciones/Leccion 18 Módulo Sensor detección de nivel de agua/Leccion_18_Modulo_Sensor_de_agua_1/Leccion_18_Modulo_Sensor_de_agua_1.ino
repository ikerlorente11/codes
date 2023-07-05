/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que permite Lectura de la entrada analogica A0 a donde se encuentra conectado un sensor de agua y
  va apagando los leds según se va vaciando el depósito de combustible y enciende de un LED conectado a pin digital
  2 si detecta que el combustible entra en reserva.
  Simula el deposito de combustible de un vehiculo
*/


int valSensor;        // Variable para almacenar valor leido
int pinLed = 2;       // Led conectado en el pin digital 2
int pinLed1 = 3;       // 1/4 del depósito
int pinLed2 = 4;       // 1/2 del depósito
int pinLed3 = 5;       // 3/4 del depósito
int pinLed4 = 6;       // 4/4 del depósito

void setup() {
  pinMode(pinLed, OUTPUT);    // pin digital 2 como salida
  Serial.begin(9600);
}

void loop() {
  valSensor = analogRead(A0);   // lee y almacena valor leido de entrada A0
  Serial.println(valSensor);

  if (valSensor <= 50) {        // si hay presencia de agua
    digitalWrite(pinLed, HIGH); // enciende LED
    digitalWrite(pinLed4, LOW);  // Apaga LED
    digitalWrite(pinLed3, LOW); // enciende LED
    digitalWrite(pinLed2, LOW); // enciende LED
    digitalWrite(pinLed1, LOW); // enciende LED
  }
  else {
    digitalWrite(pinLed, LOW);  // si no hay presencia de agua apaga LED
  }

  if (valSensor >= 630)  { // Enciende todos los led. Depósito lleno
    digitalWrite(pinLed4, HIGH); // enciende LED
    digitalWrite(pinLed3, HIGH); // enciende LED
    digitalWrite(pinLed2, HIGH); // enciende LED
    digitalWrite(pinLed1, HIGH); // enciende LED
  }
  if (valSensor >= 451 && valSensor < 629) { // Enciende 3 led. Depósito 3/4
    digitalWrite(pinLed4, LOW);  // Apaga LED
    digitalWrite(pinLed3, HIGH); // enciende LED
    digitalWrite(pinLed2, HIGH); // enciende LED
    digitalWrite(pinLed1, HIGH); // enciende LED
  }
  if (valSensor >= 351 && valSensor < 450) { // Enciende dos led. Depósito medio
    digitalWrite(pinLed4, LOW); // enciende LED
    digitalWrite(pinLed3, LOW); // enciende LED
    digitalWrite(pinLed2, HIGH); // enciende LED
    digitalWrite(pinLed1, HIGH); // enciende LED
  }
  if (valSensor > 51 && valSensor < 350) { // Enciende un led. Depósito 1/4
    digitalWrite(pinLed4, LOW);  // Apaga LED
    digitalWrite(pinLed3, LOW); // enciende LED
    digitalWrite(pinLed2, LOW); // enciende LED
    digitalWrite(pinLed1, HIGH); // enciende LED
  }

  delay(100);      // demora de 1 segundo
}
