/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que permite encender un led mediante el sensor de movimiento PIR. Se tiene en cuenta los tiempos 
   de calibración, según recomienda el fabricante. Y muestra por el monitor serie si se ha detectado movimiento 
*/

//
// Tiempo para calibrarse el sensor (10-60 secs. según la hoja de características)

int calibrationTime = 30;

//El momento en que el sensor emite un impulso bajo
long unsigned int lowIn;

//Cantidad de milisegundos que el sensor tiene que ser baja antes de asumir que todo el movimiento se ha detenido
long unsigned int pause = 5000;

boolean lockLow = true;
boolean takeLowTime;

int pirPin = 3; // El pin digital conectado a la salida sensor PIR
int ledPin = 4; // El pin para el LED de aviso de movimiento.

/////////// SETUP //////////////////
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  //Dar al sensor algún tiempo para su calibrado
  Serial.print("Calibrando el sensor ");
  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" echo");
  Serial.println("SENSOR ACTIVO");
  delay(50);
}

///////// LOOP ///////////////////
void loop() {

  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(ledPin, HIGH); // El LED visualiza el estado de pin de salida del sensor
    if (lockLow) {
      // Se asegura que esperamos una transición a LOW antes de cualquier salida adicional:
      lockLow = false;
      Serial.println("---");
      Serial.print("Movimiento detectado ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pirPin) == LOW) {
    digitalWrite(ledPin, LOW); // El LED visualiza el estado de los sensores de pin de salida

    if (takeLowTime) {
      lowIn = millis(); // guarda el tiempo de la transición de HIGH a LOW
      takeLowTime = false; // asegurar que esto se hace solamente al inicio de una fase de baja
    }
    // Si el sensor es baja por más de la pausa dada, suponemos que hay más movimientos que van a suceder
    if (!lockLow && millis() - lowIn > pause) {
      // se cerciora este bloque de código sólo se ejecuta nuevamente después de que una nueva secuencia de movimiento se ha detectado
      lockLow = true;
      Serial.print("movimiento terminó en "); //output
      Serial.print((millis() - pause) / 1000);
      Serial.println(" sec");
      delay(50);
    }
  }
}
