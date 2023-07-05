/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que controla el servo desde el Monitor Serie. Donde introducimos el valor del ángulo
   al que queremos que vaya. Desde el Monitor Serie se pregunta la posición y se manda un valor entre 0 y 180.
   y lo convierte a valor de angulo para mover al servo hacia el mismo.
*/

#include <Servo.h>      // Incluye libreria de Servo

int valPosicion = 0;

Servo myServo;          // Crea objeto servo

int pinServo = 9;       // Pin donde esta conectada la señal del servo

void setup() {
  Serial.begin(9600);
  myServo.attach(pinServo);  // Conecta el servo al pin de Arduino
  Serial.println("Escribe la posicion a donde quieres mover el servo (0 - 180)");
}

void loop() {

  if (Serial.available() > 0) {
    String grados = "";
    do {
      grados = grados + (char)Serial.read();
      delay(5);
    }
    while (Serial.available() > 0);
    Serial.println("Movido a la posicion: " + (String)grados);
    valPosicion = grados.toInt();
    myServo.write(valPosicion);
    Serial.println("Escribe la posicion a donde quieres mover el servo (0 - 180)");
  }
}
