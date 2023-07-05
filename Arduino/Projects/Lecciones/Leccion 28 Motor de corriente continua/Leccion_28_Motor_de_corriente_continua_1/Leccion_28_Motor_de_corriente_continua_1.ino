/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que el mueve el motor de CC a favor de las agujas del reloj desde parado hasta velocidad máxima y luego en contra.
  Muestra en el monitor serie el sentido de giro y el valor de la variable PWM.
*/

int habilitarM1 = 5;    // A HIGH (1) habilita el funcionamiento del motor 1 (Pin1 del L293D)
int pinAfavor  = 4;     // A HIGH (1) el motor 1 gira a favor de las agujas del reloj (Pin7 del L293D)
int pinEnContra = 3;    // A HIGH (1) el motor 1 gira en contra de las agujas del reloj (Pin2 del L293D)

int i;

void setup() {
  pinMode(habilitarM1, OUTPUT);
  pinMode(pinAfavor, OUTPUT);
  pinMode(pinEnContra, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Mueve el motor a favor de las agujas del reloj y luego en contra, 5 veces");

  for (i = 0; i < 256; i = i + 10) {
    digitalWrite(pinAfavor, HIGH);    // Marcha atras
    digitalWrite(pinEnContra, LOW);
    Serial.print("A favor de las agujas del reloj");
    Serial.print('\t');
    Serial.println(i);
    analogWrite(habilitarM1, i);      // Enable a ON, habilita el motor a velocidad variable
    delay(250);
  }
  delay(2000);

  for (i = 0; i < 256; i = i + 10) {
    digitalWrite(pinAfavor, LOW);
    digitalWrite(pinEnContra, HIGH);  // Marcha adelante
    Serial.print("En contra de las agujas del reloj");
    Serial.print('\t');
    Serial.println(i);
    analogWrite(habilitarM1, i); // Enable a ON, habilita motor a velocidad variable
    delay(250);
  }
  delay(2000);

}
