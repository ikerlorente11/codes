/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Muestra los números de 0-9 en la matriz de 8x8 con MAX7219. El array se escribe en formato binario.
*/

//We always have to include the library
#include <LedControl.h>
int pinCs = 10;
int pinDin = 11;
int pinClk = 13;

int Tiempo = 500; //Tiempo de espera entre letra y letra

// LedControl lc=LedControl(DIN,CLK,CS,Nro disp);
LedControl lc = LedControl(pinDin, pinClk, pinCs, 1); // crea objeto

byte cero[8] = {      // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito cero
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte uno[8] = {       // array que contiene todos los elementos de las
  B00010000,        // filas necesarias por mostrar el digito uno
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

byte dos[8] = {       // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito dos
  B01000100,
  B00000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111100
};

byte tres[8] = {      // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito tres
  B01000100,
  B00000100,
  B00011000,
  B00000100,
  B00000100,
  B01000100,
  B00111000
};

byte cuatro[8] = {    // array que contiene todos los elementos de las
  B00001000,        // filas necesarias por mostrar el digito cuatro
  B00011000,
  B00101000,
  B01001000,
  B01001000,
  B01111100,
  B00001000,
  B00001000
};

byte cinco[8] = {     // array que contiene todos los elementos de las
  B01111100,        // filas necesarias por mostrar el digito cinco
  B01000000,
  B01000000,
  B01111000,
  B00000100,
  B00000100,
  B01000100,
  B00111000
};

byte seis[8] = {      // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito seis
  B01000100,
  B01000000,
  B01111000,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte siete[8] = {     // array que contiene todos los elementos de las
  B01111100,        // filas necesarias por mostrar el digito siete
  B00000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B00100000,
  B00100000
};

byte ocho[8] = {      // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito ocho
  B01000100,
  B01000100,
  B00111000,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte nueve[8] = {     // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito nueve
  B01000100,
  B01000100,
  B01000100,
  B00111100,
  B00000100,
  B01000100,
  B00111000
};

void printCaracter(byte character [])//Funcion para mandar el array
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}


void setup() {
  lc.shutdown(0, false);    // enciende la matriz
  lc.setIntensity(0, 4);    // establece brillo
  lc.clearDisplay(0);     // blanquea matriz
}

void loop() {
 printCaracter(cero);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(uno);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(dos);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(tres);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(cuatro);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(cinco);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(seis);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(siete);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(ocho);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(nueve);//Imprimir la letra T
  delay(Tiempo);//Esperar Tiempo segundos
}
