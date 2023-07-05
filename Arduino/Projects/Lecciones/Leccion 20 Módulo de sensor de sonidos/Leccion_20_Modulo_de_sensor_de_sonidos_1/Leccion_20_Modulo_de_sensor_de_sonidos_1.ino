/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que utiliza la salida digital D0 del modulo KY-038 (o KY-037) para mantener encendido o apagado un LED.
  A partir de un toque en el MIC o una palmada se enciende o se apaga el led
  De fábrica viene regulado de tal manera que siempre está activo, hay que mover el preset multivuelta
  y girar en sentido contrarreloj hasta que se apague el led.
  De esa manera la salida digital tiene un nivel bajo y solo se activará con un sonido fuerte.
  Hay que verificar que el led de la izquierda del sensor esté apagado.
  Se activará el led exterior con un sonido fuerte, con un soplido cerca o con un pequeño golpe en el micrófono.
*/

int pinMic = 2;      // Pin al que está conectado la salida digital del módulo
int pinLed = 3;      // Pin al que está conectado el Led
int valorMic;        // Variable para almacenar valor de la salida digital del módulo
int estadoLed;       // Variable para almacenar estado del Led

void setup() {
  pinMode(pinMic, INPUT);      // pin de la salida digital del módulo como entrada
  pinMode(pinLed, OUTPUT);     // pin al que está conectado el Led como salida
}

void loop() {
  valorMic = digitalRead(pinMic);       // Obtiene valor de D0 (salida digital del módulo)
  if (valorMic == HIGH) {               // Si D0 tiene un valor alto
    estadoLed = digitalRead(pinLed);    // Almacena estado del led (encendido o apagado)
    digitalWrite(pinLed, !estadoLed);   // Pone el pin al que está conectado el Led el valor opuesto al que tenia
    delay(500);                         // Retraso de medio seg. para evitar pulsos falsos
  }
}

// El void loop también podría ser:
/*
  void loop(){
  while(digitalRead(pinMic)==LOW);
  digitalWrite(pinLed, !digitalRead(pinLed));
  while(digitalRead(pinMic)==HIGH);
  } 
 */
