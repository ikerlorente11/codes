/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que permite la lectura de la entrada analogica A0 a donde se encuentra conectado un sensor de agua y
  mostrando los valores mediante monitor serie..
*/


int valSensor;        // Variable para almacenar valor leido

void setup() {
  Serial.begin(9600); // Inicializa monitor serie a 9600 bps
}

void loop() {
  valSensor = analogRead(A0); // Lee y almacena en variable valor leido de entrada A0
  Serial.print("Combustible en el depósito: ");  // Muestra en monitor serie
  Serial.print('\t');
  Serial.print(valSensor);  // Muestra en monitor serie
  Serial.print('\t');
  Serial.println("Litros");
  delay(1000);                // Retraso de 1 segundo
}
