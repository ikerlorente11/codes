/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que utiliza una fotocelula o una fotoresistencia para para cambiar el brillo del LED de forma 
  inversamente proporcional a la luz captada.
*/

int pinLDR = 0;      // pin S de modulo a entrada analogica A0
int pinLed = 3;      // LED en pin 3
int valorLDR;      // almacena valor leido de entrada A0
int valorPWM;

void setup(){
  pinMode(pinLed, OUTPUT);   // pin 3 como salida
  // entradas analogicas no requieren inicialización
  Serial.begin(9600);
}


void loop(){
  valorLDR = analogRead(pinLDR);   // lee valor de entrada A0
  valorPWM = map(valorLDR, 0, 1023, 255, 0);  // convierte valores de entrada 0-1023 a 255-0 para brillo
  analogWrite(pinLed, valorPWM);    // escribe valor al LED
  Serial.print(valorLDR);
  Serial.print('\t');
  Serial.println(valorPWM);
  delay(100);                      //Retraso 0.1 segundos
}
