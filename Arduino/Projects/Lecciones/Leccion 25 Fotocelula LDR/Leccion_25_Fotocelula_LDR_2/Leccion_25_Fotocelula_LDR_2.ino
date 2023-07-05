/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que utiliza una fotocelula o una fotoresistencia para iluminar 1, 2 o 3 leds dependiendo de la luminosidad
  Devuelve el valor leido a nuestro monitor serial en el IDE de Arduino
*/

// Pin donde se conectan los leds
int pinRojo = 4;
int pinAmarillo = 3;
int pinVerde = 2;
// Pin analogico de entrada para el LDR
int pinLDR = 0;

// Variable donde se almacena el valor del LDR
int valorLDR = 0;

void setup()
{
  // Configuramos como salidas los pines donde se conectan los led
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);

  //  Configurar el puerto serie
  Serial.begin(9600);
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
  Serial.println(valorLDR);

  // Encender los leds apropiados de acuerdo al valor de ADC
  if (valorLDR > 256)
  {
    digitalWrite(pinRojo, HIGH);
  }
  if (valorLDR > 512)
  {
    digitalWrite(pinAmarillo, HIGH);
  }
  if (valorLDR > 768)
  {
    digitalWrite(pinVerde, HIGH);
  }
  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
