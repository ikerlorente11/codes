/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que enciende un LED conectado al pin 2 al presionar un pulsador y al soltar el mismo
   se apaga.
*/

int pinPulsador = 3;


void setup() {

  pinMode(pinPulsador, INPUT);  // pin del pulsador como entrada
  pinMode(LED_BUILTIN, OUTPUT);      // pin del led como salida

}

void loop() {

  if (digitalRead(pinPulsador) == HIGH) // evaluo si la entrada esta en nivel alto
  {
    digitalWrite(LED_BUILTIN, HIGH);    // pulsador presionado, enciendo el LED
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);     // pulsador no presionado, apago el LED
  }

}
