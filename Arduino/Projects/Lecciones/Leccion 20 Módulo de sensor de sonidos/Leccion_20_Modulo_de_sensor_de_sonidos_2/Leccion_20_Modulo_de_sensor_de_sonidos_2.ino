/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que utiliza la salida digital D0 del modulo KY-038 (o KY-037) para mantener encendido o apagado un LED.
  A partir de dos palmadas se enciende o se apaga el led
*/

int pinLed = 3; //define LED port
int pinMic = 2; //define switch port
int val; //define digital variable val
int ant_val;
int valAnalogico;
int palmas = 0;
boolean estadoLed = LOW;
unsigned long tiempo_palmas;

void  setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);    // pin al que está conectado el Led como salida
  pinMode(pinMic, INPUT);     // pin de la salida digital del módulo como entrada
  ant_val = digitalRead(pinMic);
}

void  loop() {
  val = digitalRead(pinMic); // Obtiene valor de D0 (salida digital del módulo)
  valAnalogico = analogRead(A0);

  if (val != ant_val) {
    if (val == HIGH) {       // Flanco Ascendente
      unsigned long tiempo_rebote = millis();
      while (true) {         // Para evitar rebotes espero que no vengan nuevos pulsos, es un filtro
        if (digitalRead(pinMic) == HIGH) {
          tiempo_rebote = millis();
          Serial.println("Rebote");
        }
        if ((millis() - tiempo_rebote) > 100) {
          break;
        }
      }
      Serial.println(valAnalogico);
      palmas++;
      
      if (palmas == 1) {
        tiempo_palmas = millis();   // Primera detección palmas
        Serial.println("Primera palmada");
      }

      if (palmas == 2) {
        Serial.println("Segunda palmada");
        estadoLed = !estadoLed;                 // Pone a la variable al que está conectado el Led el valor opuesto al que tenia
        Serial.print("Tiempo entre palmadas: ");
        Serial.print(millis() - tiempo_palmas);
        Serial.println(" ms. Cambio estado led");
        digitalWrite(pinLed, estadoLed);
        palmas = 0;
      }
    }
  }
  if ((palmas == 1) && ((millis() - tiempo_palmas) > 1000 )) {  //Si han pasado 1 segundo sin que venga una segunda palma reinicio
    Serial.println("demasiado tiempo de espera");
    palmas = 0;
  }
  ant_val = val;
}
