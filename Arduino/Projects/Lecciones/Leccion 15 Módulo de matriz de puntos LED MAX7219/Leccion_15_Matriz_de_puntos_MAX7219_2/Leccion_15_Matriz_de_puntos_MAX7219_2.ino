/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Muestra el movimiento de una flecha hacia arriba en dos matrices de 8x8 con MAX7219. El array se escribe en formato binario.
*/


// Incluimos la biblioteca
#include <LedControl.h>

int pinCs = 10;
int pinDin = 11;
int pinClk = 13;

int Tiempo = 250; //Tiempo de espera entre flecha y flecha

// LedControl lc=LedControl(DIN,CLK,CS,Nro disp);
LedControl lc = LedControl(pinDin, pinClk, pinCs, 2); // crea objeto con dos módulos

byte flecha_arriba_1[8] = {    // array con primer cuadro de animacion de flecha
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000
};

byte flecha_arriba_2[8] = {   // array con segundo cuadro de animacion de flecha
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000,
  B00000000
};

byte flecha_arriba_3[8] = {   // array con tercer cuadro de animacion de flecha
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00000000
};

byte flecha_arriba_4[8] = {   // array con cuarto cuadro de animacion de flecha
  B01111110,
  B11011011,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000
};

byte flecha_arriba_5[8] = {   // array con quinto cuadro de animacion de flecha
  B11011011,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00111100
};

byte flecha_arriba_6[8] = {   // array con sexto cuadro de animacion de flecha
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01111110
};

byte flecha_arriba_7[8] = {   // array con septimo cuadro de animacion de flecha
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B11011011
};

byte flecha_arriba_8[8] = {   // array con octavo cuadro de animacion de flecha
  B00011000,
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B00011000
};

byte flecha_arriba_9[8] = {   // array con noveno cuadro de animacion de flecha
  B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B00011000,
  B00011000
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
  printCaracter(flecha_arriba_1);//Imprime el carácter flecha_arriba_1
  printCaracter1(flecha_arriba_9);//Imprime el carácter flecha_arriba_1
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_2);//Imprime el carácter flecha_arriba_2
  printCaracter1(flecha_arriba_1);//Imprime el carácter flecha_arriba_2
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_3);//Imprime el carácter flecha_arriba_3
  printCaracter1(flecha_arriba_2);//Imprime el carácter flecha_arriba_3
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_4);//Imprime el carácter flecha_arriba_4
  printCaracter1(flecha_arriba_3);//Imprime el carácter flecha_arriba_4
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_5);//Imprime el carácter flecha_arriba_5
  printCaracter1(flecha_arriba_4);//Imprime el carácter flecha_arriba_5
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_6);//Imprime el carácter flecha_arriba_6
  printCaracter1(flecha_arriba_5);//Imprime el carácter flecha_arriba_6
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_7);//Imprime el carácter flecha_arriba_7
  printCaracter1(flecha_arriba_6);//Imprime el carácter flecha_arriba_7
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_8);//Imprime el carácter flecha_arriba_8
  printCaracter1(flecha_arriba_7);//Imprime el carácter flecha_arriba_8
  delay(Tiempo);//Esperar Tiempo segundos
  printCaracter(flecha_arriba_9);//Imprime el carácter flecha_arriba_9
  printCaracter1(flecha_arriba_8);//Imprime el carácter flecha_arriba_9
  delay(Tiempo);//Esperar Tiempo segundos
}
