/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que controla el display de 7 segmentos de 1 dígito con el integrado 74HC595.
*/


// Se definen los patrones de los dígitos del LED, de 0 a 9
// 1 = LED encendido, 0 = LED apagado, en este orden:
//                pin 74HC595      Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7
//                Asignación a     a,b,c,d,e,f,g, P del LED de siete segmentos
// O sea conectamos pin segmento-led con pin 74HC595  a(Q0),b(Q1),c(Q2),d(Q3),e(Q4),f(Q5),g(Q6)y P(Q7)

//                            Babcdefgp
byte numero[10] =           { B11100110,  // = 9
                              B11111110,  // = 8
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B10110110,  // = 5
                              B01100110,  // = 4
                              B11110010,  // = 3
                              B11011010,  // = 2
                              B01100000,  // = 1    Estan activos b y c y a,d,e,f y g apagados
                              B11111100  // = 0    Estan activos a,b,c,d,e y f y g y P apagados
                            };

int latchPin = 11; // (Pin 12) ST_CP [RCK-RCLK] en 74HC595. El pin latch del 74HC595 está conectado al pin digital 11
int clockPin = 9;  // (Pin 11) SH_CP [SCK-SRCLR] en 74HC595. El pin del reloj del 74HC595 está conectado al pin digital 9
int dataPin = 12;  // (Pin 14) DS DATA [SER] en 74HC595. El pin de datos del 74HC595 está conectado al pin digital 12

void setup() {
  // Se activan los pines latchPin, clockPin, dataPin del 74HC595 como SALIDA
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

// Se muestra un número en la pantalla de segmento digital
void sevenSegWrite(byte digit) {
  // Se ajusta el latchPin a un potencial bajo, antes de enviar datos
  digitalWrite(latchPin, LOW);

  // Datos originales (patrón de bits)
  shiftOut(dataPin, clockPin, LSBFIRST, numero[digit]);

  // Se ajusta el latchPin a potencial alto, después de enviar datos
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // Decrementamos de 9 a 0
  for (byte digit = 10; digit > 0; --digit) {
    delay(500);
    sevenSegWrite(digit - 1);
  }

  // Esperamos 1 segundo
  delay(1000);
}
