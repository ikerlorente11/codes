/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que establecer fecha y horario iniciales para el modulo RTC modelo DS3231 y
  muestra dichos datos mediante el monitor serie. Requiere instalar libreria RTClib
*/

#include <Wire.h>     // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

RTC_DS1307 rtc;       // crea objeto del tipo RTC_DS1307


void setup() {
  while (!Serial); // para Leonardo/Micro/Zero

  Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
  if (! rtc.begin()) {    // si falla la inicializacion del modulo
    Serial.println("Modulo RTC no encontrado !");
    while (1);            // bucle infinito que detiene ejecucion del programa
  } // fin de rtc.begin()

    // establece en el RTC en la fecha y hora
    // rtc.adjust(DateTime(Año(2021),Mes(02), Dia(17), Hora(17), Minutos(31), Segundos(0));  // funcion que permite establecer fecha y horario
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Directiva que permite establecer fecha y horario, tomando la hora del ordenador
    // rtc.adjust(DateTime(__DATE__, __TIME__));  // También sirve
    // Esto se hace una vez luego se sube el programa obviando esta orden. Al tener batería el módulo ya sabe la hora
    // Esta línea establece el RTC con una fecha y hora explícitas, por ejemplo para establecer
    
    // El 21 de enero de 2014 a las 3 A.M., se activaria:
     rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));  
  }    

void loop() {
    
   DateTime fecha = rtc.now();
  
  // El búfer se puede definir utilizando las siguientes combinaciones:
  // hh: las horas con un cero a la izquierda (00 a 23) 
  // mm: los minutos con un cero a la izquierda (00 a 59)
  // ss: los segundos con un cero a la izquierda (00 a 59)
  //YYYY - el año como un número de cuatro dígitos
  //YY - el año como un número de dos dígitos (00-99)
  //MM - el mes como un número, con un cero inicial (01-12)
  //MMM - el nombre del mes abreviado, en inglés, ('Jan' a 'Dec')
  //DD - el día como un número con un cero inicial (01 to 31)
  //DDD - el nombre del día abreviado, en inglés ('Mon' a 'Sun')
  
   char buf1[] = "hh:mm";
   Serial.println(fecha.toString(buf1));

   char buf2[] = "DD-MM-YY / hh:mm:ss";
   Serial.println(fecha.toString(buf2));
   
   char buf3[] = "Hoy es DDD, DD MMM YYYY";
   Serial.println(fecha.toString(buf3));
   
   char buf4[] = "DD-MM-YYYY";
   Serial.println(fecha.toString(buf4));
  
   delay(1000);
}
