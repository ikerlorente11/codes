/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que hace parpadear un texto y usa las funciones scroll para desplazar un texto horizontalmente en la pantalla.
*/

#include <LiquidCrystal.h>            // Importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pines RS(pin4), E(pin6), D4(pin11), D5(pin12), D6(pin13), D7(pin14) del modulo 1602A

void setup() {
  lcd.begin(16, 2);
  lcd.print("Pantalla activa !");    // Escribe texto
  lcd.display();                     // Muestra el texto
  delay(500);                        // Retraso de medio segundo
  lcd.noDisplay();                   // Oculta el texto
  delay(500);                        // Retraso de medio segundo
  lcd.display();                     // Muestra el texto
  delay(500);                        // Retraso de medio segundo
}

void loop() {
  lcd.setCursor(0, 0);                       // Coloca el cursor en columna 0 y linea 0
 
  lcd.print("Hola mundo!               ");   // Escribe texto
  lcd.display();                             // Muestra el texto
  delay(1000);                               // Retraso de medio segundo
 
  // Mueve 13 posiciones (longitud del texto) a la izquierda
  //para sacar el texto de la pantalla por la izquierda
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }

  // Mueve 29 posiciones (longitud del texto + ancho del display) a la derecha
  //para sacar el texto de la pantalla por la derecha
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(300);
  }

  // Mueve 16 posiciones (29-13) a la izquierda
  //para devolver el texto a la posición inicial
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }

  delay(1000);
}
