/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que realiza el giro de un motor 28BYJ-48 en conjunto con el controlador basado en ULN2003,
  a partir del giro de un encoder rotativo Modulo KY-040.
  El programa usa la librería Stepper.h
  Hay que alimentar Arduino con fuente de alimentacion externa de 6 a 12 Vcc.
*/

#include "Stepper.h"
#define STEPS  32   // Número de pasos para una vuelta del eje interno
                    // 2048 pasos para una vuelta de eje externo


// Necesita variables de estilo volatile para las interrupciones
volatile boolean TurnDetected;  
volatile boolean rotationdirection;  // Para definir si la rotación es a favor de las agujas del reloj (CW) o en contra (CCW)

const int PinCLK = 2;   // Pin para las interrupciones usando la señal CLK
const int PinDT = 3;    // Lectura de la señal DT
const int PinSW = 4;    // Lectura del interruptor del pulsador

int RotaryPosition = 0; // Variable para almacenar la posición del motor paso a paso

int PrevPosition;       // Valor de la posición giratoria anterior, para comprobar la precisión
int StepsToTake;        // Cuánto hay que mover el motor paso a paso

// Configuración de la secuencia adecuada para los pines del controlador del motor
// In1, In2, In3, In4 en la secuencia 1-3-2-4
Stepper small_stepper(STEPS, 8, 10, 9, 11);

// La rutina de interrupción se ejecuta si CLK pasa de ALTO a BAJO
void isr ()  {
  delay(4);  // rretardo para antirrebote
  if (digitalRead(PinCLK))
    rotationdirection = digitalRead(PinDT);
  else
    rotationdirection = !digitalRead(PinDT);
  TurnDetected = true;
}

void setup ()  {

  pinMode(PinCLK, INPUT);
  pinMode(PinDT, INPUT);
  pinMode(PinSW, INPUT);
  digitalWrite(PinSW, HIGH); // Resistencia pull-up para el interruptor
  attachInterrupt (0, isr, FALLING); // La interrupción 0 conectada al pin 2 de Arduino
}

void loop ()  {
  small_stepper.setSpeed(700);  // Establece la velocidad máxima del motor a 700 revoluciones por minuto (RPM). 
  if (!(digitalRead(PinSW))) {  // Se comprueba si el botón está pulsado
    if (RotaryPosition == 0) {  // Comprueba si el botón ya ha sido presionado
    } else {
      small_stepper.step(-(RotaryPosition * 50));
      RotaryPosition = 0;       // Restablecer la posición a CERO
    }
  }

  // Se ejecuta si se detecta una rotación
  if (TurnDetected)  {
    PrevPosition = RotaryPosition; // Guarda la posición anterior en la variable
    if (rotationdirection) {
      RotaryPosition = RotaryPosition - 1;
    } // decrase Position by 1
    else {
      RotaryPosition = RotaryPosition + 1;
    } // increase Position by 1

    TurnDetected = false;  // NO repite el bucle IF hasta que se detecte una nueva rotación o vuelta

    //Dirección a la que va a mover el motor paso a paso
    if ((PrevPosition + 1) == RotaryPosition) { // Se mueve el motor en sentido horario
      StepsToTake = 50;
      small_stepper.step(StepsToTake);
    }

    if ((RotaryPosition + 1) == PrevPosition) { // Se mueve el motor en sentido antihorario
      StepsToTake = -50;
      small_stepper.step(StepsToTake);
    }
  }
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
