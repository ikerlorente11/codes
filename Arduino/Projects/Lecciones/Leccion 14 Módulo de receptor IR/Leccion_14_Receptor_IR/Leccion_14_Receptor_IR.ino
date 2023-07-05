/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que envía al Monitor Serie la lectura del valor recibido por el mando, y lo muestra por pantalla.
   El código se muestra en formato hexadecimal.
*/

#include <IRremote.h>


// Inicializamos variables
const int pinReceptor = 2;

IRrecv irrecv(pinReceptor);
decode_results results;

void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
  irrecv.enableIRIn();        // Inicializa el receptor
}

void loop() {
  if (irrecv.decode(&results))  //Si recibe un dato
  {
    Serial.println(results.value, HEX); // Muestra el dato en el monitor serie
    irrecv.resume();                    // Se prepara para recibir el siguiente valor
  }
}
