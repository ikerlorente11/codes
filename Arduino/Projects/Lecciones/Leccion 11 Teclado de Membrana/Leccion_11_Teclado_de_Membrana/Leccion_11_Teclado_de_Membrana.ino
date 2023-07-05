/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que permite conectar un teclado matricial de membrana de 4x4 y mostrar la tecla presionada
   en el Monitor Serie
*/

#include <Keypad.h>

// Inicializamos variables
const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFilas[FILAS] = {9, 8, 7, 6}; // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2}; // pines correspondientes a las columnas
char TECLA;       // almacena la tecla presionada

//initialize an instance of class NewKeypad
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto



void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
}

void loop() {
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (TECLA) {
    Serial.println(TECLA);
  }
}
