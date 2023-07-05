/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que envía al Monitor Serie la lectura del valor recibido por el mando, y lo muestra por pantalla.
   El código que se muestra es el nombre o número de la tecla presionada.
*/

#include <IRremote.h>


// Inicializamos variables
const int pinReceptor = 2;

IRrecv irrecv(pinReceptor);
decode_results results;

/*-----( Comienzo Función )-----*/
void translateIR() // traduce según el código IR recibido

// descripción de códigos de infrarrojos remotos 

{

  switch(results.value)

  {
  case 0xFFA25D: Serial.println("ENCENDIDO"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("RETROCESO RÁPIDO");    break;
  case 0xFF02FD: Serial.println("PAUSA");    break;
  case 0xFFC23D: Serial.println("AVANCE RÁPIDO");   break;
  case 0xFFE01F: Serial.println("ABAJO");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("ARRIBA");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" otro botón   ");

  }// End Case

  delay(500); // No SE obtiene una repetición inmediata


} //FIN de translateIR


void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
  Serial.println("Decodificación del botón del receptor de infrarrojos"); 
  irrecv.enableIRIn();        // Inicializa el receptor
}

void loop() {
  if (irrecv.decode(&results))  //Si recibe un dato
  {
    translateIR(); 
    irrecv.resume();            // Se prepara para recibir el siguiente valor
  }
}
