/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que realiza un giro completo del motor 28BYJ-48 en conjunto con el controlador basado en ULN2003,
  detiene 5 segundos y luego comienza nuevamente.
  El programa usa la librería Stepper.h
  Hay que alimentar Arduino con fuente de alimentacion externa de 6 a 12 Vcc.
*/

#include <Stepper.h>      // Incluímos la librería Stepper.h

const int pasosPorVuelta = 2048;      // Valor de ajuste al número de pasos por vuelta
const int vueltasPorMinuto = 15;      // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// Se inicializa la biblioteca Stepper en los pines 8 a 11:
Stepper myStepper(pasosPorVuelta, 8, 10, 9, 11);

void setup() {
  // Asignamos la velocidad en RPM (Revoluciones por Minuto)
  myStepper.setSpeed(vueltasPorMinuto);
  // Se inicializa el Monitor Serie:
  Serial.begin(9600);
}

void loop() {
  // Giramos el motor a favor de las agujas del reloj:
  Serial.println("El motor está girando en sentido horario");
  // Movemos el motor un número determinado de pasos (pasosPorVuelta)
  myStepper.step(pasosPorVuelta);
  delay(500);

  // Giramos el motor en contra de las agujas del reloj:
  Serial.println("El motor está girando en sentido anti-horario");
  // Movemos el motor un número determinado de pasos (pasosPorVuelta)
  myStepper.step(-pasosPorVuelta);
  delay(500);
}
