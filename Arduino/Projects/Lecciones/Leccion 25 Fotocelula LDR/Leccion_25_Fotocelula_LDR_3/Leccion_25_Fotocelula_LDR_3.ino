/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que enciende los leds apropiados de acuerdo al valor de ADC, un led, dos leds o los tres.
*/

// Pin donde se conectan los leds
int pinRojo = 2;
int pinAmarillo = 3;
int pinVerde = 4;
// Pin analogico de entrada para el LDR
int pinLDR = 0;

// Variable donde se almacena el valor del LDR
int valorLDR = 0;
int val = 0;

void setup()
{
  // Configuramos como salidas los pines donde se conectan los led
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
}

void loop()
{
  // Apagar todos los leds siempre que se inicia el ciclo
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR
  valorLDR = analogRead(pinLDR);

  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  val = map(valorLDR, 0, 1023, 255, 0);  // Mapeamos este valor

  // Encender los leds apropiados de acuerdo al valor de ADC
  if (val > 64)
  {
    digitalWrite(pinRojo, HIGH);
  }
  if (val > 128)
  {
    digitalWrite(pinAmarillo, HIGH);
  }
  if (val > 192)
  {
    digitalWrite(pinVerde, HIGH);
  }
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
