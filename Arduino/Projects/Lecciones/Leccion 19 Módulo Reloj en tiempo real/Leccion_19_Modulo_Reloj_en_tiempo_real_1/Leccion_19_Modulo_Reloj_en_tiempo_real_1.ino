/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que establece la fecha y la hora iniciales para el modulo RTC modelo DS3231 y
  muestra la fecha, día de la semana y la hora en el monitor serie.
  Requiere instalar libreria RTClib
*/

#include <Wire.h>    // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

// Podriamos usar la librería DS3231.zip, el funcionamiento es similar. DS3231 rtc;

char diaSemana[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
char nombreMes[12][12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
int diaDeLaSemana, mes;

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

void setup () {
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps

  if (! rtc.begin()) {       // si falla la inicializacion del modulo
    Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
    while (1);         // bucle infinito que detiene ejecucion del programa
  }
  // establece en el RTC en la fecha y hora
  // rtc.adjust(DateTime(Año(2021),Mes(02), Dia(17), Hora(17), Minutos(31), Segundos(0));  // funcion que permite establecer fecha y horario
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Directiva que permite establecer fecha y horario, tomando la hora del ordenador
  // rtc.adjust(DateTime(__DATE__, __TIME__));  // También sirve
  // Esto se hace una vez luego se sube el programa obviando esta orden. Al tener batería el módulo ya sabe la hora
  // Esta línea establece el RTC con una fecha y hora explícitas, por ejemplo para establecer

  // El 21 de enero de 2014 a las 3 A.M., se activaria:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void loop () {
  DateTime fecha = rtc.now();      // funcion que devuelve fecha y horario en formato. DateTime y asigna a variable fecha
  mes = fecha.month();

  Serial.println("La fecha de hoy es:");
  Serial.print(fecha.day());     // funcion que obtiene el dia de la fecha completa
  Serial.print("/");       // caracter barra como separador
  Serial.print(fecha.month());     // funcion que obtiene el mes de la fecha completa
  Serial.print("/");       // caracter barra como separador
  Serial.println(fecha.year());      // funcion que obtiene el año de la fecha completa

  Serial.print(diaSemana[fecha.dayOfTheWeek()]);
  Serial.print(" ");
  Serial.print(fecha.day());     // funcion que obtiene el dia de la fecha completa
  Serial.print(" de ");       // caracter barra como separador
  Serial.print(nombreMes[mes - 1]);
  Serial.print(" de ");       // caracter barra como separador
  Serial.println(fecha.year());
  Serial.println("  ");

  Serial.print("Y son las: ");       // caracter barra como separador
  Serial.print(fecha.hour());      // funcion que obtiene la hora de la fecha completa
  Serial.print(":");       // caracter dos puntos como separador
  Serial.print(fecha.minute());      // funcion que obtiene los minutos de la fecha completa
  Serial.print(":");       // caracter dos puntos como separador
  Serial.println(fecha.second());    // funcion que obtiene los segundos de la fecha completa
  Serial.println("  ");

  delay(1000);         // demora de 1 segundo
}
