#include <SoftwareSerial.h> // librería que permite establecer pines digitales
// para comunicación serie, viene incluida en Arduino
// Asigno el nombre miBT al puerto de HC-05 no es el nombre del dispositivo
// SoftwareSerial miBT (rxPin, txPin)
// rxPin pin donde está conectado el TX del HC-05
// txPin pin donde está conectado el RX del HC-05
SoftwareSerial miBT(50, 51); //pin 10 como RX, pin 11 como TX

void setup() {
  Serial.begin(38400); // comunicación de monitor serial a 9600 bps
  Serial.println("Listo"); // escribe Listo en el monitor
  miBT.begin(38400); // comunicación serie entre Arduino y el módulo a 38400bps
}

void loop() {
  if (miBT.available()) { // Si llega un dato por el puerto BT1 o hay información desde modulo
    Serial.write(miBT.read()); // lee Bluetooth y envía a monitor serial de Arduino
  }
  if (Serial.available()) { // si hay información disponible desde el monitor serial
    miBT.write(Serial.read()); // lee monitor serial (Arduino) y envía a Bluetooth
  }
}
