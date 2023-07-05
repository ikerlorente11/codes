/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que varía la velocidad de un servo según el número de la pulsación.
   p.e. la activación de un limpiaparabrisas. 
   Hay tres velocidades de barrido, cada pulsación sube de velocidad y la cuarta pulsación lo para
   Muestra en el Monitor Serie el número de la pulsación (0, 1, 2 o 3).
   que hayamos hecho el  pulsador. 
*/

#include <Servo.h>

Servo myservo;  // crear objeto myservo para controlar un servo

const int controlPin = 2;   // Pin donde está conectada la señal del pulsador

int varVelocidad = 0;
int varPulsacion = 0;
int estadoBoton;
int estadoBotonAnterior;
int pinServo = 9;           // Pin donde está conectada la señal del Servo

int valPos = 0;             // variable para almacenar la posición del servo

void setup() {
  Serial.begin(9600);       // Inicia el Monitor Serie
  myservo.attach(pinServo); // Conecta el servo al pin de Arduino
  myservo.write(0);         // Posicionamos el servomotor en el ángulo 0

  pinMode(controlPin, INPUT_PULLUP);  // Inicializamos el pin de control del pulsador como entrada
  estadoBotonAnterior = digitalRead(controlPin);
}

void loop() {
  detecta_pulsacion();

  if (varPulsacion > 0) {
    for (valPos = 20; valPos <= 160; valPos += 5) { // Va desde 0 grados a 180 grados
      // in steps of 1 degree
      myservo.write(valPos);              // Manda al servo que vaya a la posición en la variable 'valPos'
      delay(varVelocidad);
      detecta_pulsacion();
    }

    for (valPos = 160; valPos >= 20; valPos -= 5) { // goes from 180 degrees to 0 degrees
      myservo.write(valPos);              // Manda al servo que vaya a la posición en la variable 'valPos'
      delay(varVelocidad);
      detecta_pulsacion();
    }
  }
}

void detecta_pulsacion() {
  // leo estado boton
  estadoBoton = digitalRead(controlPin);

  //Detección pulsación boton
  if (estadoBoton != estadoBotonAnterior) {
    if (estadoBoton == HIGH) {
      Serial.print("Pulsacion = ");
      Serial.println(varPulsacion);
      varPulsacion++;
      switch (varPulsacion) {
        case 1:
          varVelocidad = 30;
          break;
        case 2:
          varVelocidad = 20;
          break;
        case 3:
          varVelocidad = 10;
          break;
        case 4:
          varPulsacion = 0;
          break;
      }
    }
  }
  estadoBotonAnterior = estadoBoton;
}
