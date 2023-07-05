/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que utiliza la salida analogica A0 de KY-038 (o KY-037) para enviar el valor leido por monitor serial.
  El valor es cercano a 550
*/

int pinMic = 0;           // Salida A0 del sensor a la entrada analogica A0 de la placa
int valorA0;              // Variable para almacenar valor leido de la salida A0 del sensor
float valorAnalog;

void setup() {
  // entradas analogicas no requieren inicializacion
  Serial.begin(9600);     // Inicializa la de comunicacion serie
}


void loop() {
  valorA0 = analogRead(pinMic);   // Lee valor de la entrada analogica
  //valorAnalog = analogRead (valorA0) * (5.0 / 1023.0);
  valorAnalog = analogRead (valorA0);
  Serial.print(valorA0);        // Escribe valor en el monitor serial
  Serial.print('\t');
  Serial.print ("Valor en voltios: ");
  Serial.print(valorAnalog);
  Serial.println ("  V");
  delay(500);                     // Retraso de medio segundo entre lecturas
}
