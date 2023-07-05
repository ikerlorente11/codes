/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que muestra en el Monitor Serial el valor de distancia leído por el sensor ultrasónico
   HC-SR04. Usando la librería SR04.h
*/

#include <SR04.h>

// Inicializamos variables
int pinTrig = 12;
int pinEco =  11;
long valDistancia;

SR04 sr04 = SR04(pinEco, pinTrig);

void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
  pinMode(pinTrig, OUTPUT);   // trigger como salida
  pinMode(pinEco, INPUT);     // echo como entrada
}

void loop() {

  valDistancia = sr04.Distance();

  // Se muestran los resultados en el Monitor Serie
  
    Serial.print("Distancia al objeto ");
    Serial.print(valDistancia);
    Serial.println(" cm");
  
  // Retardo para disminuir la frecuencia de las lecturas
  delay(500);
}
