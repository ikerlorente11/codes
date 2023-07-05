//Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
//Programa que enciende un LED RGB conectado a los pines 3, 5 y 6.
//Para proteger al led hay que colocar una resistencia en serie con el de 330 ohmios.
//Se pasa de ROJO a VERDE, de VERDE a AZUL,de AZUL a ROJO, pasando por todas las tonalidades.

// define variables
int pinRojo = 6;    // pin 6 a anodo LED rojo
int pinVerde = 5;    // pin 5 a anodo LED verde
int pinAzul = 3;   // pin 3 a anodo LED azul

int valorRojo;
int valorVerde;
int valorAzul;

void setup()
{
  pinMode(pinRojo, OUTPUT);       // todos los pines como salida
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  digitalWrite(pinRojo, HIGH);    // Pin rojo a 1 los demás a 0
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
}


// Programación del loop
void loop()
{
  int delayTime = 10; // tiempo de desvanecimiento entre colores

  //Los led variaran entre 0 y 255. Siendo 0 apagado y 255 encendido
  valorRojo = 255; // Damos el valor 255 al led rojo y 0 a los demás leds.
  valorVerde = 0;
  valorAzul = 0;

  // Paso de Rojo a Verde
  for (int i = 0; i < 255; i += 1) // se desvanece en rojo y enciende el verde al completo cuando i = 255
  {
    valorRojo -= 1;   // Restamos de uno en uno al valor del rojo
    valorVerde += 1;  // Sumamos de uno en uno al valor del verde

    analogWrite(pinRojo, valorRojo);    // Escribimos en el pin del led rojo su valor
    analogWrite(pinVerde, valorVerde);  // Escribimos en el pin del led verde su valor
    delay(delayTime);                   // Esperamos un tiempo manteniendo el color encendido
  }

  valorRojo = 0;
  valorVerde = 255;   // Damos el valor 255 al led verde y 0 a los demás leds.
  valorAzul = 0;

  for (int i = 0; i < 255; i += 1) // se desvanece en verde y enciende el azul al completo cuando i = 255
  {
    valorVerde -= 1;  // Restamos de uno en uno al valor del verde
    valorAzul += 1;   // Sumamos de uno en uno al valor del azul

    analogWrite(pinVerde, valorVerde);  // Escribimos en el pin del led verde su valor
    analogWrite(pinAzul, valorAzul);    // Escribimos en el pin del led azul su valor
    delay(delayTime);                   // Esperamos un tiempo manteniendo el color encendido
  }

  valorRojo = 0;
  valorVerde = 0;
  valorAzul = 255;    // Damos el valor 255 al led azul y 0 a los demás leds.

  for (int i = 0; i < 255; i += 1) // se desvanece en azul y enciende el rojo al completo cuando i = 255
  {

    valorAzul -= 1;   // Restamos de uno en uno al valor del azul
    valorRojo += 1;   // Sumamos de uno en uno al valor delrojo

    analogWrite(pinAzul, valorAzul);  // Escribimos en el pin del led azul su valor
    analogWrite(pinRojo, valorRojo);  // Escribimos en el pin del led rojo su valor
    delay(delayTime);                 // Esperamos un tiempo manteniendo el color encendido
  }
}
