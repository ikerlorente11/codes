/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que lee el valor del potenciometro conectado a entrada A0
   y lo convierte a valor de angulo para mover al servo hacia el mismo.
*/

#include <Servo.h>      // incluye libreria de Servo

Servo myServo;          // crea objeto

//Declaracion de variables constantes
int pinServo = 9;     // La señal del servo está conectada al pin 9  
int pulsoMin = 500;   // Pulso minimo en microsegundos
int pulsoMax = 2550;  // Pulso maximo en microsegundos
int valorPot;         // La variable para almacenar valor leido en entrada A0
int valorAng;         // Lee el valor del Angulo a cargar en el servo

int pinPot = 0;       // Pin analogico A0 al que está conectado el potenciometro. 

void setup()
{
  myServo.attach(pinServo, pulsoMin, pulsoMax); // Se inicializa de servo

  // las entradas analogicas no requieren inicializacion
}

void loop()
{
  valorPot = analogRead(pinPot);              // lee valor de entrada A0
  
  // con funcion map se convierte el rango de valorAng de 0 a 1023 a rango proporcional de 0 a 179
  valorAng = map(valorPot, 0, 1023, 0, 179);
  
  myServo.write(valorAng);                    // envia al servo el valor del ángulo
  delay(20);                                  // retraso para que el servo llegue a su posicion
}
