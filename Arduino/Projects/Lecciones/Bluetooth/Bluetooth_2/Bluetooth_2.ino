#include <SoftwareSerial.h> // Librería que permite establecer pines digitales
// para comunicación serie
SoftwareSerial miBT(10, 11); // pin 10 como RX, pin 11 como TX
char DATO = '0'; // variable para almacenar carácter recibido
int LEDROJO = 13; // LED rojo a pin digital numero 2
void setup() {
  miBT.begin(9600); // comunicación serie entre Arduino y el módulo a 38400bps
  pinMode(LEDROJO, OUTPUT); // pin 2 como salida
}

void loop() {
  if (miBT.available()) { // si hay información disponible desde modulo
    DATO = miBT.read(); // almacena en DATO el carácter recibido desde modulo
    if ( DATO == '1' ) // si el carácter recibido es el numero 1
    digitalWrite(LEDROJO, HIGH); // enciende LED rojo
    if ( DATO == '0' ) // si el carácter recibido es el numero 2
    digitalWrite(LEDROJO, LOW); // apaga LED rojo
  }
}
