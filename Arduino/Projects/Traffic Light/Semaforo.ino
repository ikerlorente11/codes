int pinVerdePeaton = 2;
int pinRojoPeaton = 3;
int pinVerdeSemaforo = 4;
int pinAmarilloSemaforo = 5;
int pinRojoSemaforo = 6;
int pinZumbador = 7;


void setup()
{
  Serial.begin(9600);
  pinMode(pinVerdePeaton, OUTPUT);
  pinMode(pinRojoPeaton, OUTPUT);
  pinMode(pinVerdeSemaforo, OUTPUT);
  pinMode(pinAmarilloSemaforo, OUTPUT);
  pinMode(pinRojoSemaforo, OUTPUT);
  pinMode(pinZumbador, OUTPUT);
}

void loop()
{
  digitalWrite(pinZumbador, HIGH);
  digitalWrite(pinRojoSemaforo, HIGH);
  digitalWrite(pinRojoPeaton, LOW);
  digitalWrite(pinAmarilloSemaforo, LOW);
  digitalWrite(pinVerdeSemaforo, LOW);
  digitalWrite(pinVerdePeaton, HIGH);
  delay(4500);

  for(int i = 0; i < 5; i++){
    digitalWrite(pinVerdePeaton, LOW);
    digitalWrite(pinZumbador, LOW);
    delay(150);
    digitalWrite(pinVerdePeaton, HIGH);
    digitalWrite(pinZumbador, HIGH);
    delay(150);
  }

  digitalWrite(pinZumbador, LOW);
  digitalWrite(pinVerdeSemaforo, HIGH);
  digitalWrite(pinVerdePeaton, LOW);
  digitalWrite(pinRojoSemaforo, LOW);
  digitalWrite(pinRojoPeaton, HIGH);
  delay(6000);

  digitalWrite(pinAmarilloSemaforo, HIGH);
  delay(1500);
}
