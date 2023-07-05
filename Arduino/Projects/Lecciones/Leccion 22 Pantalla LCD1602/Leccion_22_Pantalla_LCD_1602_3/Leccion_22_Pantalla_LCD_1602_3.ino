/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que muestra un texto en la primera línea de la pantalla y unos caracteres definidos en la segunda.
*/

#include <LiquidCrystal.h>            // Importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pines RS(pin4), E(pin6), D4(pin11), D5(pin12), D6(pin13), D7(pin14) del modulo 1602A

// Definimos los caracteres personalizados
byte sonrisa[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00010001,
  0b00001110,
  0b00000000,
};

byte triste[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00001110,
  0b00010001,
  0b00000000,
};

byte cuerpo[8] = {
  0b00001110,
  0b00001110,
  0b00000100,
  0b00011111,
  0b00000100,
  0b00001010,
  0b00010001,
  0b00000000,
};

byte flechar[8] = {
  0b00001000,
  0b00000100,
  0b00000010,
  0b00011111,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00000000,
};

byte flechau[8] = {
  0b00000100,
  0b00001110,
  0b00010101,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000000,
};

byte flechad[8] = {
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00010101,
  0b00001110,
  0b00000100,
  0b00000000,
};

byte flechal[8] = {
  0b00000010,
  0b00000100,
  0b00001000,
  0b00011111,
  0b00001000,
  0b00000100,
  0b00000010,
  0b00000000,
};

byte blanco[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};

void setup()
{
  // Inicializamos el display de 16 columnas y 2 lineas
  lcd.begin(16, 2);
}

void loop()
{
  // Enviamos los Mapas de Bits al Controlador de Pantalla
  lcd.createChar (0, sonrisa);
  lcd.createChar (1, triste);
  lcd.createChar (2, cuerpo);
  lcd.createChar (3, flechar);
  lcd.createChar (4, flechal);
  lcd.createChar (5, flechau);
  lcd.createChar (6, flechad);
  lcd.createChar (7, blanco);

  // Limpiamos la Pantalla y Movemos el Cursor a la Primera Posición
  lcd.clear();
  // Imprimimos un Texto en la Primera Línea
  lcd.print(" DIE-EIVG ");

  // Mover el Cursor a la Segunda Línea
  lcd.setCursor(0, 1);

  // Escribimos (Mostramos) los Caracteres Definidos en la Pantalla
  lcd.write((byte)0);
  lcd.write((byte)7);
  lcd.write((byte)1);
  lcd.write((byte)7);
  lcd.write((byte)2);
  lcd.write((byte)7);
  lcd.write((byte)3);
  lcd.write((byte)7);
  lcd.write((byte)4);
  lcd.write((byte)7);
  lcd.write((byte)5);
  lcd.write((byte)7);
  lcd.write((byte)6);
}
