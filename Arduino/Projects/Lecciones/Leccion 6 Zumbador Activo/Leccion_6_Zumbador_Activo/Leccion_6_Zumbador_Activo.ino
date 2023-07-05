/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que hace vibrar a un buzzer activo a una frecuencia.
*/

//Declaracion de variables constantes
const int pinBuzzer = 3;    // El pin del zumbador activo
const int tiempoAlto = 500; // Tiempo del buzzer a HIGH
const int tiempoBajo = 1000; // Tiempo del buzzer a LOW

void setup()
{
  pinMode(pinBuzzer, OUTPUT); // Se define el pin del zumbador como salida
}
void loop()
{
  // Se genera la frecuencia
  digitalWrite(pinBuzzer, HIGH);   // Se pone el Pin a HIGH. Se enciende el buzzer
  delay(tiempoAlto);               // Se espera el tiempo en alto
  digitalWrite(pinBuzzer, LOW);    // Se pone el Pin a LOW. Se apaga el buzzer
  delay(tiempoBajo);               // Se espera el tiempo en bajo

}
