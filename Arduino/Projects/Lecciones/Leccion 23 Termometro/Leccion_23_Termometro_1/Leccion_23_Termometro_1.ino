/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que muestra en el modulo LCD la temperatura tomada desde un termistor NTC. En grados celsius y farenhait.
  Requiere instalar libreria LiquidCrystal
*/

#include <LiquidCrystal.h>            // Importa libreria

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pines RS(pin4), E(pin6), D4(pin11), D5(pin12), D6(pin13), D7(pin14) del modulo 1602A

int tempPin = 0;


void setup()
{
  lcd.begin(16, 2);
}
void loop()
{
  int tempReading = analogRead(tempPin);
  // This is OK
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0) / 5.0 + 32.0; // Convert Celcius to Fahrenheit

  // Display Temperature in C
  lcd.setCursor(0, 0);
  lcd.print("Temp         C  ");
  lcd.setCursor(6, 0);
  // Display Temperature in C
  lcd.print(tempC);


  // Display Temperature in F
  lcd.setCursor(0, 1);
  // Display Temperature in F
  lcd.print("Temp         F  ");
  lcd.setCursor(6, 1);
  lcd.print(tempF);

  delay(500);
}
