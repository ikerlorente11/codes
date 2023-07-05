/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que envía al Monitor Serie los valores X e Y de un Joystick Analógico.
   Los ejes van desde -512 a 0 y desde 0 a 512
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

  if (valEjeX >= 0 && valEjeX < 512) {        // si X esta en la zona izquierda
    angX =  map(valEjeX, 0, 512, -512, 0);   //

    Serial.print("Eje X en grados: ");
    Serial.print(angX);  // Muestra  los valores del Eje X de 0 a 180 en grados
    Serial.print("\t");
  }

  if (valEjeX > 513 && valEjeX <= 1023) {         // si X esta en la zona derecha
    angX = map(valEjeX, 513, 1023, 0, 512); //

    Serial.print("Eje X en grados: ");
    Serial.print(angX);  // Muestra  los valores del Eje X de 0 a 180 en grados
    Serial.print("\t");

  }

  if (valEjeY >= 0 && valEjeY < 512) {        // si Y esta en la zona de abajo
    angY = map(valEjeY, 0, 512, -512, 0);   // brillo LED proporcional

    Serial.print("Eje Y en grados: ");
    Serial.print(angY);  // Muestra  los valores del Eje Y de 0 a 180 en grados
    Serial.print("\t");
  }


  if (valEjeY > 513 && valEjeY <= 1023) {         // si Y esta en la zona de arriba
    angY = map(valEjeY, 513, 1023, 0, 512);   // brillo LED proporcional
    Serial.print("Eje Y en grados: ");
    Serial.print(angY);  // Muestra  los valores del Eje Y de 0 a 180 en grados
    Serial.print("\t");

  }

  Serial.print("Pulsador:  ");
  valPulsador = digitalRead(pinPulsador);
  Serial.print(!valPulsador);
  Serial.print("\n");
  delay(500);               // Se añade un retraso entre lecturas

}
