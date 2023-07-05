/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que usa las funciones scroll para desplazar un texto en las dos líneas, horizontalmente en la pantalla.
*/

#include <LiquidCrystal.h>            // Importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pines RS(pin4), E(pin6), D4(pin11), D5(pin12), D6(pin13), D7(pin14) del modulo 1602A

void setup()
{
  // INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2
  lcd.begin(16, 2);
  // MOVER EL CURSOR A LA PRIMERA POSICION DE LA PANTALLA (0, 0)
  lcd.home();
  // IMPRIMIR "Hola Mundo" EN LA PRIMERA LINEA
  lcd.print("Hola Mundo");
  // MOVER EL CURSOR A LA SEGUNDA LINEA (1) PRIMERA COLUMNA (0)
  lcd.setCursor ( 0, 1 );
  // IMPRIMIR OTRA CADENA EN ESTA POSICION
  lcd.print("DIE-EIVG");
  // ESPERAR UN SEGUNDO
  delay(1000);
}

void loop()
{
  // EN EL CICLO PRINCIPAL SOLAMENTE RECORREMOS EL MENSAJE DE UN LADO A OTRO
  // VARIABLE PARA CONTROL DE CICLOS
  int i;

  // DESPLAZAR LA PANTALLA A LA DERECHA 2 VECES
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayRight();
    delay (500);
  }

  // DESPLAZAR LA PANTALLA A LA IZQUIERDA 2 VECES
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayLeft();
    delay (500);
  }
}
