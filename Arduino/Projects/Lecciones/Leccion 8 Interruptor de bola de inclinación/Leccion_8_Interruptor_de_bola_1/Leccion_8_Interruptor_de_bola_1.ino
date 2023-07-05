/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que utiliza el modulo KY-002 para encender un LED cuando el sensor detecta un golpe o vibracion fuerte
   El sensor brinda un nivel logico bajo cuando detecta la vibracion. 
   Y muestra por el Monitor serie si hay alerta por inclinación o está todo correcto.
*/

//Declaracion de variables constantes
int pinSensor = 2;      // pin S de modulo a pin 2
int pinLed = 3;      // anodo de LED a pin 3

void setup(){
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);  // pin 2 como entrada
  pinMode(pinLed, OUTPUT);   // pin 3 como salida
}


void loop(){
  if(digitalRead(pinSensor)){
    Serial.println("Alerta por inclinación");
    digitalWrite(pinLed, HIGH);  // Led encendido
    delay(200);
  }else{
    Serial.println("Todo correcto");
    digitalWrite(pinLed, LOW);     // Led apagado
  }
}
