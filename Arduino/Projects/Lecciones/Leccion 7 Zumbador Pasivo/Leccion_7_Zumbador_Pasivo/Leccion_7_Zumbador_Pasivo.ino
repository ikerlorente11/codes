/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que al girar un potenciometro genera las frecuencias que puede escuchar el oido humano y activa un zumbador pasivo.
   Y mostramos los valores por el Monitor serie.
*/

//Declaracion de variables constantes
int pinBuzzer = 8 ; // Pin digital al que esta conectado el buzzer
int pinPot = A0;    // Pin anañógico al que esta conectado el potenciometro
int val = 0;        // Variable donde almacenamos el valor del mapeado
int lectura = 0;    // Variable donde almacenamos la lectura obtenida del potenciometro por el ADC canal A0

void setup()
{
  pinMode (pinBuzzer, OUTPUT);  // Inidcamos que donde esta el buzzer conectado es pin de salida
  Serial.begin(9600);           // Inicializamos el puerto serie
}
void loop()
{
  lectura = analogRead(pinPot);            // Leemos el valor del pin del potenciometro con el ADC A0
  val = map(lectura, 0, 1023, 20, 20000);  // Mapeamos este valor al rango que puede detectar el oido humano 20Hz a 20.000 Hz
  Serial.print("valor leido pot ");        // Imprimimos en el puerto serie la informacion
  Serial.print(lectura);
  Serial.print(" - valor mapeado = ");
  Serial.println(val);
  tone(pinBuzzer, val);                    //Enviamos el valor del tono al buzzer
  delay(10);

}
