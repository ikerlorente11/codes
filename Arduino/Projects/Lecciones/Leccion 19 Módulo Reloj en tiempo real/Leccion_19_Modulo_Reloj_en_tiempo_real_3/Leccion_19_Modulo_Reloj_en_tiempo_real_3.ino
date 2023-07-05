/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que activa un Led a las 14:30 hs y lo desactiva mas tarde a las 14:31 hs todos los dias
  Para engañar al reloj y poder probar el programa cambiamos la hora a 30 s. antes de que salte la alarma, hay que activar un trozo de código.
*/

#include <Wire.h>    // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

bool inicioEvento = true;  // variable de control para inicio de evento con valor true
bool finEvento = true;   // variable de control para finalizacion de evento con valor true

int pinLed = 3;     // constante Led con valor 3 que corresponde a pin digital 3
// donde se encuentra conectado el modulo de Led
void setup () {
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
  pinMode(pinLed, OUTPUT);   // pin 3 como salida

  if (! rtc.begin()) {       // si falla la inicializacion del modulo
    Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
    while (1);         // bucle infinito que detiene ejecucion del programa
  }
  // Para engañar al reloj y poder probar el programa bambiamos la hora a 30 sg. antes de encender el Led
  rtc.adjust(DateTime(2021, 02, 17, 14, 29, 30));

  // Después restauraremos la hora real
  // rtc.adjust(DateTime(__DATE__,__TIME__));

}

void loop () {
  DateTime fecha = rtc.now();        // funcion que devuelve fecha y horario en formato
  // DateTime y asigna a variable fecha
  if ( fecha.hour() == 14 && fecha.minute() == 30 ) { // si hora = 14 y minutos = 30
    if ( inicioEvento == true ) {    // si inicioEvento es verdadero
      digitalWrite(pinLed, HIGH);       // activa modulo de Led con nivel alto
      Serial.println( "Led encendido" );   // muestra texto en monitor serie
      inicioEvento = false;        // carga valor falso en variable de control
    }             // para evitar ingresar mas de una vez
  }

  if ( fecha.hour() == 14 && fecha.minute() == 31 ) { // si hora = 14 y minutos = 31
    if ( finEvento == true ) {       // si finEvento es verdadero
      digitalWrite(pinLed, LOW);        // desactiva modulo de Led con nivel bajo
      Serial.println( "Led apagado" );     // muestra texto en monitor serie
      finEvento = false;       // carga valor falso en variable de control
    }             // para evitar ingresar mas de una vez
  }

  Serial.print(fecha.day());       // funcion que obtiene el dia de la fecha completa
  Serial.print("/");         // caracter barra como separador
  Serial.print(fecha.month());       // funcion que obtiene el mes de la fecha completa
  Serial.print("/");         // caracter barra como separador
  Serial.print(fecha.year());        // funcion que obtiene el año de la fecha completa
  Serial.print(" ");         // caracter espacio en blanco como separador
  Serial.print(fecha.hour());        // funcion que obtiene la hora de la fecha completa
  Serial.print(":");         // caracter dos puntos como separador
  Serial.print(fecha.minute());        // funcion que obtiene los minutos de la fecha completa
  Serial.print(":");         // caracter dos puntos como separador
  Serial.println(fecha.second());      // funcion que obtiene los segundos de la fecha completa

  delay(1000);           // demora de 1 segundo

  if ( fecha.hour() == 14 && fecha.minute() == 50 ) { // si hora = 14 y minutos = 50 restablece valores de
    inicioEvento = true;       // variables de control en verdadero
    finEvento = true;
  }
}
