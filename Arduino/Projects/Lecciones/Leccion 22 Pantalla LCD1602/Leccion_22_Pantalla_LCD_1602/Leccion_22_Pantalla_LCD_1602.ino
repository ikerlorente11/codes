/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que muestra en el modulo LCD el tiempo transcurrido en segundos desde que se inicio el programa.
  Requiere instalar libreria LiquidCrystal
*/

/*
    Las conexiones del circuito:

   Pin 1 LCD VSS a pin GND de arduino
   Pin 2 LCD VDD a pin 5V de arduino
   Pin 3 LCD V0 a pin medio de potenciometro de 10k (Contrastre)
   Pin 4 LCD RS a pin 7 arduino (Registro)
   Pin 5 LCD RW a pin GND de arduino
   Pin 6 LCD E al pin 6 de arduino (Habilita)
   Pin 7 LCD D0
   Pin 8 LCD D1
   Pin 9 LCD D2
   Pin 10 LCD D3
   Pin 11 LCD D4 a pin 5 de arduino
   Pin 12 LCD D5 a pin 4 de arduino
   Pin 13 LCD D6 a pin 3 de arduino
   Pin 14 LCD D7 a pin 2 de arduino
   Pin 15 LCD A a una resisitencia de 220 oh y después a Vcc
   Pin 16 LCD K a pin GND de arduino

   Potenciometro de 10K:
   Pines externos uno a Vcc y otro a GND de arduino
   Pin del medio a pin 3 de LCD (Contrastre)
*/

#include <LiquidCrystal.h>            // Importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pines RS(pin4), E(pin6), D4(pin11), D5(pin12), D6(pin13), D7(pin14) del modulo 1602A

void setup() {
  lcd.begin(16, 2);                   // Inicializa a display de 16 columnas y 2 lineas
}

void loop() {
  lcd.setCursor(0, 0);                // Ubica cursor en columna 0, linea 0
  lcd.print("Hola, han pasado");      // Escribe el texto en pantalla
  lcd.setCursor(0, 1);                // Ubica cursor en columna 0, linea 1
  lcd.print(millis() / 1000);         // Escribe valor en segundos devuelto por funcion millis()
  lcd.print(" seg.");                 // Imprime a continuacion segundos
}
