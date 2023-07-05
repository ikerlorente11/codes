/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que el mueve el motor de CC a favor de las agujas del reloj y luego en contra a velocidad máxima, 5 veces.
  Muestra en el monitor serie el sentido de giro.
*/

int habilitarM1 = 5;    // A HIGH (1) habilita el funcionamiento del motor 1 (Pin1 del L293D)
int pinAfavor  = 4;     // A HIGH (1) el motor 1 gira a favor de las agujas del reloj (Pin7 del L293D)
int pinEnContra = 3;    // A HIGH (1) el motor 1 gira en contra de las agujas del reloj (Pin2 del L293D)

int i;

void setup() {
  //---set pin direction
  pinMode(habilitarM1, OUTPUT);
  pinMode(pinAfavor, OUTPUT);
  pinMode(pinEnContra, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //--- Ejemplo de ida y vuelta
  Serial.println("Mueve el motor a favor de las agujas del reloj y luego en contra, 5 veces");
  digitalWrite(habilitarM1, HIGH); // Enable a ON, habilita motor 1
  for (i = 0; i < 5; i++) {
    digitalWrite(pinAfavor, HIGH);   // Marcha atras
    digitalWrite(pinEnContra, LOW);
    Serial.println("A favor de las agujas del reloj");
    delay(1000);
    digitalWrite(pinAfavor, LOW);    // Marcha adelante
    digitalWrite(pinEnContra, HIGH);
    Serial.println("En contra de las agujas del reloj");
    delay(1000);
  }
  digitalWrite(habilitarM1, LOW);    // Enable a OFF,  desactiva el motor 1
  delay(2000);

}
