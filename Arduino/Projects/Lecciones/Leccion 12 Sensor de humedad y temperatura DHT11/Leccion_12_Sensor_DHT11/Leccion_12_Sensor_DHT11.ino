/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que envía al Monitor Serie el valor de la Temperatura y Humedad leído
   por el sensor DHT11. También calcula el índice de calor temperatura aparente, sensación térmica.
*/

#include <DHT.h>    // importa la Librerias DHT
#include <DHT_U.h>

// Inicializamos variables
int pinSensor = 2;  // El sensor está conectado al pin 2
long valTemperatura;
long valHumedad;


// Creamos el objeto
DHT dht(pinSensor, DHT11);

void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
  dht.begin();                // inicializacion de sensor
  pinMode(pinSensor, INPUT);  // Sensor como entrada
}

void loop() {
  valTemperatura = dht.readTemperature();   // Obtencion de valor de temperatura
  valHumedad = dht.readHumidity();          // Obtencion de valor de humedad
    
  // Calcular el índice de calor (temperatura aparente, sensación térmica) en grados centígrados
  float hic = dht.computeHeatIndex(valTemperatura, valHumedad, false);

  Serial.print("Temperatura: ");            // Escritura en el Monitor Serie Temperatura:
  Serial.print(valTemperatura);             // Imprime el valor de la temperatura
  Serial.print(" *C");
  Serial.print('\t');                       // Escribe una tabulacion horizontal para hacer una columna
  Serial.print(" Humedad Relativa: ");
  Serial.print(valHumedad);                 // Imprime el valor de la humedad
  Serial.print(" % ");
  Serial.print('\t');
  Serial.print("Índice de calor - Sensación Térmica: ");
  Serial.println(hic);                      // Imprime el valor del indice de calor
  delay(500);

}
