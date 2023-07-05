/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Muestra la frase "Hola a Arduino" en movimiento en una matriz de 8x8 con MAX7219. El array se escribe en formato binario.
*/

int pinCs = 10;
int pinDin = 11;
int pinClk = 13;

// Incluimos biblioteca
#include <LedControl.h>

//INICIALIZO EL CHIP MAX7219
//ESTRUDTURA DE LA FUNCIÓN: LedControl(int dataPin, int clkPin, int csPin, int numDevices);
LedControl lc = LedControl(pinDin, pinClk, pinCs, 1); // crea objeto

void setup() {
  //The MAX72XX is in power-saving mode on startup, we have to do a wakeup call
  lc.shutdown(0, false);
  //Set the brightness to a medium values (0~15 possible values)
  lc.setIntensity(0, 4);
  //and clear the display
  lc.clearDisplay(0);
}


//DEFINO LOS CARACTERES DE LA MATRIZ
#define H { B01000010, B01000010, B01000010, B01000010, B01111110, B01000010, B01000010, B01000010}
#define o { B00000000, B00000000, B00000000, B00011000, B00100100, B00100100, B00100100, B00011000}
#define l { B00010000, B00010000, B00010000, B00010000, B00010000, B00010000, B00010000, B00001000}
#define a { B00000000, B00000000, B00000000, B00111000, B00000100, B00111100, B01000100, B00111010}
#define A { B00011000, B00100100, B01000010, B01000010, B01000010, B01111110, B01000010, B01000010}
#define r { B00000000, B00000000, B00000000, B01011000, B01100000, B01000000, B01000000, B01000000}
#define d { B00000100, B00000100, B00000100, B00111100, B01000100, B01000100, B01000100, B00111100}
#define u { B00000000, B00000000, B00000000, B01000100, B01000100, B01000100, B01000100, B00111010}
#define in { B00000000, B00010000, B00000000, B00010000, B00010000, B00010000, B00010000, B00010000}
#define n { B00000000, B00000000, B00000000, B01011000, B01100100, B01000100, B01000100, B01000100}
#define esp { B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}

//Escribimos la frase separando cada letra por comas
//En el primer numero lo adaptaremos la longitud de la frase (caracteres)

byte frase[15][8] = {H, o, l, a, esp, a, esp, A, r, d, u, in, n, o, esp};
int largo = sizeof(frase) / 5;
int gnd[18] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};



void loop() {
  for (int letra = 0; letra < largo; letra++) {
    for (int desplaza = 18; desplaza >= 8; desplaza--) {
      for (int i = 0; i < 8; i++) {
        lc.setRow(0, gnd[i + desplaza - 8], frase[letra][i]);
      }
      delay(100); // Velocidad de animación
      lc.clearDisplay(0);
    }
    if (letra == largo) {
      letra = 0;
    }
  }// Fin de letra
}
