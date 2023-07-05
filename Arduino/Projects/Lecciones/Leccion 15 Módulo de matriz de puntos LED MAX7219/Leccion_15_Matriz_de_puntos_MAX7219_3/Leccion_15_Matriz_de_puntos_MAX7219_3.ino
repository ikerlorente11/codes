/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Muestra la frase "Hola a Arduino" en dos matrices de 8x8 con MAX7219. El array se escribe en formato binario.
*/

// Incluimos la biblioteca
#include <LedControl.h>

int pinCs = 10;
int pinDin = 11;
int pinClk = 13;

int Tiempo = 1000; //Tiempo de espera entre letras

// LedControl lc=LedControl(DIN,CLK,CS,Nro disp);
LedControl lc = LedControl(pinDin, pinClk, pinCs, 2); // crea objeto con dos módulos

byte H[8] = {   // array con la letra H
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B01000010,
  B01000010,
  B01000010
};

byte o[8] = {   // array con la letra o
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B00100100,
  B00100100,
  B00011000
};

byte l[8] = {   // array con la letra l
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00001000
};

byte a[8] = {   // array con la letra a
  B00000000,
  B00000000,
  B00111000,
  B00000100,
  B00111100,
  B01000100,
  B00111010

};

byte A[8] = {    // array con la letra A
  B00011000,
  B00100100,
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B01000010,
  B01000010
};

byte r[8] = {   // array con la letra r
  B00000000,
  B00000000,
  B00000000,
  B01011000,
  B01100000,
  B01000000,
  B01000000,
  B01000000

};

byte d[8] = {   // array con la letra d
  B00000100,
  B00000100,
  B00000100,
  B00111100,
  B01000100,
  B01000100,
  B01000100,
  B00111100

};

byte u[8] = {   // array con la letra u
  B00000000,
  B00000000,
  B00000000,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B00111010
};

byte i[8] = {   // array con la letra i
  B00000000,
  B00010000,
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000
};

byte n[8] = {   // array con la letra n
  B00000000,
  B00000000,
  B00000000,
  B01011000,
  B01100100,
  B01000100,
  B01000100,
  B01000100
};

byte esp[8] = {   // array con la letra blanco
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};


void printCaracter(byte character [])//Funcion para mandar el array
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}

void printCaracter1(byte character [])//Funcion para mandar el array
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1, i, character[i]);
  }
}


void setup() {
  lc.shutdown(0, false);    // enciende la matriz
  lc.setIntensity(0, 4);    // establece brillo
  lc.clearDisplay(0);     // blanquea matriz

  lc.shutdown(1, false);    // enciende la matriz
  lc.setIntensity(1, 4);    // establece brillo
  lc.clearDisplay(1);     // blanquea matriz
}

void loop() {
  printCaracter(H);//Imprime el carácter H
  printCaracter1(esp);//Imprime el carácter blanco
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(o);//Imprime el carácter o
  printCaracter1(H);//Imprime el carácter H
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(l);//Imprime el carácter l
  printCaracter1(o);//Imprime el carácter o
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(a);//Imprime el carácter a
  printCaracter1(l);//Imprime el carácter l
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(esp);//Imprime el carácter blanco
  printCaracter1(a);//Imprime el carácter a
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(a);//Imprime el carácter a
  printCaracter1(esp);//Imprime el carácter blanco
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(esp);//Imprime el carácter blanco
  printCaracter1(a);//Imprime el carácter a
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(A);//Imprime el carácter A
  printCaracter1(esp);//Imprime el carácter blanco
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(r);//Imprime el carácter r
  printCaracter1(A);//Imprime el carácter A
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(d);//Imprime el carácter d
  printCaracter1(r);//Imprime el carácter r
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(u);//Imprime el carácter u
  printCaracter1(d);//Imprime el carácter d
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(i);//Imprime el carácter i
  printCaracter1(u);//Imprime el carácter u
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(n);//Imprime el carácter n
  printCaracter1(i);//Imprime el carácter i
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(o);//Imprime el carácter o
  printCaracter1(n);//Imprime el carácter n
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(esp);//Imprime el carácter blanco
  printCaracter1(o);//Imprime el carácter o
  delay(Tiempo);//Esperar Tiempo segundos
}
