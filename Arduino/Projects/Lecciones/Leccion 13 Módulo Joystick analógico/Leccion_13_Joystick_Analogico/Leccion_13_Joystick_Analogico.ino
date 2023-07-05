/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que envía al Monitor Serie los valores X e Y de un Joystick Analógico. 
   Los ejes van desde 0 a 1023.
*/

// Inicializamos variables
int pinPulsador = 2;  // El pulsador está conectado al pin 2
int xPin = A0;        // Entrada analógica A0 para lectura del eje X
int yPin = A1;        // Entrada analógica A1 para lectura del eje Y

int valPulsador = 0;  // Variable de lectura del pulsador
int valEjeX = 0;     // Variable de lectura del eje X
int valEjeY = 0;     // Variable de lectura del eje Y
int angX = 0;
int angY = 0;

void setup() {
  Serial.begin (9600);                  // Inicializacion de la comunicacion serie a 9600 bps
  pinMode(pinPulsador, INPUT_PULLUP);   // El pulsador como entrada
  //digitalWrite(pinPulsador, HIGH);
}

void loop() {
  valEjeX = analogRead(xPin);           // Lectura del puerto analógico A0 del eje X
  valEjeY = analogRead(yPin);           // Lectura del puerto analógico A1 del eje Y
  valPulsador = digitalRead(pinPulsador); // Lectura del pulsador

  Serial.print("Eje X: ");
  Serial.print(valEjeX);  // Muestra  los valores del Eje X de 0 a 1023
  Serial.print("\t");     //Sirve para generar un espacio entre dos palabras, sangría
  Serial.print("Eje Y: ");
  Serial.print(valEjeY);  // Muestra  los valores del Eje Y de 0 a 1023
  Serial.print("\t");

  Serial.print("Pulsador:  ");
  Serial.print(!valPulsador);
  Serial.print("\n");
  delay(500);               // Se añade un retraso entre lecturas

}
