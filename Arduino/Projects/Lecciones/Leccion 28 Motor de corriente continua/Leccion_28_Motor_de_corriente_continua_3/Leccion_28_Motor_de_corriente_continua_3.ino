/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que el mueve el motor de CC dependiendo de la posición de un potenciometro.
  La velocidad del eje del motor se modifica al girar el potenciómetro y el sentido de giro 
  cambia cuando cruzamos por el punto medio del rango del potenciómetro aproximadamente.
  Muestra en el monitor serie el sentido de giro y el valor de la variable PWM.
  
*/

int habilitarM1 = 5;    // A HIGH (1) habilita el funcionamiento del motor 1 (Pin1 del L293D)
int pinAfavor  = 4;     // A HIGH (1) el motor 1 gira a favor de las agujas del reloj (Pin7 del L293D)
int pinEnContra = 3;    // A HIGH (1) el motor 1 gira en contra de las agujas del reloj (Pin2 del L293D)
int pinPote = A0;       //Potenciómetro

int valPot = 0;//Variable que contendrá el valor leido en el pin Analógico ( 0 a 1023 ) al cual se conectó la señal del potenciómetro
int valPWM = 0;//Variable que contendrá el valor de PWM ( -255 a 255) que escribirá al pin PWM al cual conectamos la señal EN1 del del punte H L293D

void setup()
{
  pinMode(habilitarM1, OUTPUT);
  pinMode(pinEnContra, OUTPUT);
  pinMode(pinAfavor, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  valPot = analogRead(pinPote); //Realizamos la lectura del potenciómetro

  //Convertimos el valor leido para poder utilizarlo como segundo argumento de "analogRead()"
  //El signo lo utilizaremos para definir el sentido de giro del motor
  valPWM = map(valPot, 0, 1023, -255, 255);

  if (valPWM > 0) {
    digitalWrite(pinAfavor, HIGH); //Establecemos la dirección del giro según el signo de valPWM
    digitalWrite(pinEnContra, LOW); //Establecemos la dirección del giro según el signo de valPWM
    analogWrite(habilitarM1, abs(valPWM));//Establecemos la velocidad del giro según el valor absoluto de valPWM

    Serial.print("Velocidad del motor: ");
    Serial.print('\t');
    Serial.print(valPWM);
    Serial.print('\t');
    Serial.println("Motor girando a favor de las agujas del reloj");

  }
  else {
    digitalWrite(pinAfavor, LOW); //Establecemos la dirección del giro según el signo de valPWM
    digitalWrite(pinEnContra, HIGH); //Establecemos la dirección del giro según el signo de valPWM
    analogWrite(habilitarM1, abs(valPWM));//Establecemos la velocidad del giro según el valor absoluto de valPWM

    Serial.print("Velocidad del motor: ");
    Serial.print('\t');
    Serial.print(valPWM);
    Serial.print('\t');
    Serial.println("Motor girando en contra de las agujas del reloj");
  }



  delay(10);
}
