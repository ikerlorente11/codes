/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que muestra el valor de un texto en la primera línea de la pantalla y el valor de un potenciómetro en la segunda.
*/

#include <LiquidCrystal.h>            // Importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pines RS(pin4), E(pin6), D4(pin11), D5(pin12), D6(pin13), D7(pin14) del modulo 1602A

void setup()
{
  // Inicializamos el display de 16 columnas y 2 lineas
  lcd.begin(16, 2);
}

void loop()
{
  // Borramos Toda la Pantalla 
  lcd.clear();
  // Imprimimos un Encabezado
  lcd.print(" POTENCIOMETRO  ");

  // Realizamos la Lectura Analógica del Potenciómetro por el Pin A0 de Arduino
  unsigned int val = analogRead(A0);
  // Convertimos el Valor Leído a Voltaje (Asumiendo que Nuestro Arduino se Alimenta a 5 Voltios)
  float volts = (val * 5.0) / 1024.0;

  // Imprimimos los Valores en la Segunda Línea, Comenzando por el Valor Directo del ADC (0-1023)
  lcd.setCursor(0, 1);
  lcd.print("ADC: ");  
  lcd.setCursor(5, 1);
  lcd.print(val);

  // IMPRIMIMOS EL VALOR DEL VOLTAJE, DESPUES DE LA LECTURA DEL ADC
  lcd.setCursor(10, 1);
  lcd.print(volts, 1);
  lcd.setCursor(14, 1);
  lcd.print("V");  

  // ESPERAR UN SEGUNDO ANTES DE CONTUNUAR
  delay (1000);
}
