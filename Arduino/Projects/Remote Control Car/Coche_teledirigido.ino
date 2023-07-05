int pinAlante = 2;
int pinAtras = 3;
int pinIzquierda = 4;
int pinDerecha = 5;
int pinClaxon = 6;
int pinPulsador = 7;  // El pulsador está conectado al pin 2
int xPin = A0;        // Entrada analógica A0 para lectura del eje X
int yPin = A1;        // Entrada analógica A1 para lectura del eje Y

int valPulsador = 0;  // Variable de lectura del pulsador
int valEjeX = 0;     // Variable de lectura del eje X
int valEjeY = 0;     // Variable de lectura del eje Y
int angX = 0;
int angY = 0;

void setup() {
  Serial.begin (9600);                  // Inicializacion de la comunicacion serie a 9600 bps
  pinMode(pinPulsador, INPUT_PULLUP);   // El pulsador como entrada
  pinMode(pinAlante, OUTPUT);
  pinMode(pinAtras, OUTPUT);
  pinMode(pinIzquierda, OUTPUT);
  pinMode(pinDerecha, OUTPUT);
  pinMode(pinClaxon, OUTPUT);
}

void loop() {
  valEjeX = analogRead(xPin);           // Lectura del puerto analógico A0 del eje X
  valEjeY = analogRead(yPin);           // Lectura del puerto analógico A1 del eje Y
  valPulsador = digitalRead(pinPulsador); // Lectura del pulsador

  if(valEjeX > 1023/2 + 10){
    int val = map(valEjeX, 511, 1023, 0, 255);
    analogWrite(pinDerecha, val);
    Serial.println(val);
  }else{
    analogWrite(pinDerecha, 0);
  }

  if(valEjeX < 1023/2 - 10){
    int val = map(valEjeX, 511, 0, 0, 255);
    analogWrite(pinIzquierda, val);
    Serial.println(val);
  }else{
    analogWrite(pinIzquierda, 0);
  }

  if(valEjeY < 1023/2 - 10){
    int val = map(valEjeY, 511, 0, 0, 255);
    analogWrite(pinAlante, val);
    Serial.println(val);
  }else{
    analogWrite(pinAlante, 0);
  }

  if(valEjeY > 1023/2 + 15){
    int val = map(valEjeY, 511, 1023, 0, 255);
    analogWrite(pinAtras, val);
    Serial.println(val);
  }else{
    analogWrite(pinAtras, 0);
  }

  if(digitalRead(pinPulsador) == 0){
    digitalWrite(pinClaxon,HIGH);
  }else{
    digitalWrite(pinClaxon,LOW);
  }
}
