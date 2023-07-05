/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que utiliza una fotocelula o una fotoresistencia para aumentar la luminosidad de un LED cuando hay baja intensidad de luz ambiente.
*/

int pinLDR = 0;   // Inicializa la interfaz analógica A0 conectada la resistencia fotosensible
int pinLed = 3;   // Inicializa la el pin digital 3 como salida PWM para ajustar el brillo del LED
int valorLDR = 0; // Inicializa variable val
int val = 0;

void setup() {
  pinMode(pinLed, OUTPUT); // Definir el pin digital 3 como salida
  Serial.begin(9600);
}
void loop() {
  valorLDR = analogRead(pinLDR);  // Leer los valores analógicos del sensor y los asigna a la variable valorLDR
 
  Serial.println(valorLDR);       // Muestra el valor de valorLDR en el monitor serie
  analogWrite(pinLed, valorLDR);  // Enciende el LED y configura el brillo 
  delay(100);                      //Retraso 0.1 segundos
}
