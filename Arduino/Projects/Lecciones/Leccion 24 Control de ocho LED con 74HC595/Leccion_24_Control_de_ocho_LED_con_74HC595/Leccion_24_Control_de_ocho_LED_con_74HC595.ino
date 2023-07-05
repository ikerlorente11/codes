/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que controla ocho leds con el integrado 74HC595.
*/

int tDelay = 200;
int latchPin = 11; // (Pin 12) ST_CP [RCK-RCLK] en 74HC595. El pin latch del 74HC595 está conectado al pin digital 11
int clockPin = 9;  // (Pin 11) SH_CP [SCK-SRCLR] en 74HC595. El pin del reloj del 74HC595 está conectado al pin digital 9
int dataPin = 12;  // (Pin 14) DS DATA [SER] en 74HC595. El pin de datos del 74HC595 está conectado al pin digital 12
byte leds = 0;     // Variable para mantener el patrón de los LEDs que están actualmente encendidos o apagados

/*
   Esta función establece el latchPin en bajo, luego llama a la función Arduino 'shiftOut' para desplazar el
   contenido de las variables 'leds' en el registro de desplazamiento antes de volver a poner el 'latchPin' en alto.
*/
void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);     // Se ajusta el latchPin a un potencial bajo, antes de enviar datos
  shiftOut(dataPin, clockPin, LSBFIRST, leds);  // Datos originales (patrón de bits)
  digitalWrite(latchPin, HIGH);     // Se ajusta el latchPin a potencial alto, después de enviar datos
}

void setup()
{
  // Se establece todos los pines del 74HC595 como SALIDA
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  leds = 0;                   // Inicialmente se apagan todos los LED, dando a la variable 'leds' el valor 0
  updateShiftRegister();
  delay(tDelay);
  for (int i = 0; i < 8; i++) // Se encienden todos los LED de uno en uno.
  {
    bitSet(leds, i);          // Se establecer el bit que controla al LED en la variable 'leds'
    updateShiftRegister();
    delay(tDelay);
  }
}
