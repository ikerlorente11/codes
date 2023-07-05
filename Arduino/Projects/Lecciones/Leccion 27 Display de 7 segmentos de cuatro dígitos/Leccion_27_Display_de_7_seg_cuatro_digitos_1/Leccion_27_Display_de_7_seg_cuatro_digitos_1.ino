/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que controla el display de 7 segmentos y 4 dígitos con el integrado 74HC595.
  Escribe 0123 en el display
*/


int latchPin = 11; // (Pin 12) ST_CP [RCK-RCLK] en 74HC595. El pin latch del 74HC595 está conectado al pin digital 11
int clockPin = 9;  // (Pin 11) SH_CP [SCK-SRCLR] en 74HC595. El pin del reloj del 74HC595 está conectado al pin digital 9
int dataPin = 12;  // (Pin 14) DS DATA [SER] en 74HC595. El pin de datos del 74HC595 está conectado al pin digital 12

// Pin común (cátodo) para activar los 4 dígitos.
// (Dg1-PinArd7-PinDis12)(Dg2-PinArd6-PinDis9)(Dg3-PinArd5-PinDis8)(Dg4-PinArd4-PinDis6)
int activaDig[] = {7, 6, 5, 4};

// Define la codificación de los caracteres de 0-F de la pantalla de 7 segmentos de cátodo común
byte num[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};


void setup() {
  // Ajusta los pines como salidas
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(activaDig[i], OUTPUT);
  }
}


void loop() {
  for (int i = 0; i < 4; i++) {
    // Seleccione una solo dígito de 7 segmentos
    eligeDig(i);
    // Envia los datos al 74HC595
    escribeDato(num[i]);
    delay(5);
    // Borrar el contenido del display 
    escribeDato(0xff);
  }
}
void eligeDig(byte com) {
  // Cierra todos los displays individuales de 7 segmentos
  for (int i = 0; i < 4; i++) {
    digitalWrite(activaDig[i], HIGH);
  }
  // Activa un único display de 7 segmentos seleccionado
  digitalWrite(activaDig[com], LOW);
}
void escribeDato(int value) {
  // Pone la salida de latchPin a nivel bajo 
  digitalWrite(latchPin, LOW);
  // Enviar los datos en serie al 74HC595
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  // Pone la salida latchPin a nivel alto, luego el 74HC595 actualizará los datos a la salida en paralelo
  digitalWrite(latchPin, HIGH);
}
