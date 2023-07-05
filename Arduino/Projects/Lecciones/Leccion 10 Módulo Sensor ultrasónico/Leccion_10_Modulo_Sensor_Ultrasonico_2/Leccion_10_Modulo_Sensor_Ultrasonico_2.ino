/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que envía mediante el Monitor Serial el valor de distancia leído por el sensor ultrasónico
   HC-SR04 y nos permite visualizar si estamos cerca o lejos de un obstáculo. Con 3 LEDs (verde, amarillo
   y rojo) conseguimos determinar si estamos lejos, cerca o en zona de peligro.
*/

// Inicializamos variables
int pinTrig = 12;
int pinEco =  11;
int pinVerde =  2;
int pinAmarillo =  3;
int pinRojo =  4;
int pinBuzzer =  9;

// Definimos constantes
const float sonido = 34300.0; // Velocidad del sonido en cm/s
const float umbral1 = 50.0;
const float umbral2 = 30.0;
const float umbral3 = 10.0;


void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
  pinMode(pinTrig, OUTPUT);   // trigger como salida

  pinMode(pinEco, INPUT);     // echo como entrada
  pinMode(pinVerde, OUTPUT);   // trigger como salida
  pinMode(pinAmarillo, OUTPUT);   // trigger como salida
  pinMode(pinRojo, OUTPUT);   // trigger como salida
  pinMode(pinBuzzer, OUTPUT);   // trigger como salida

// Apagamos todos los LEDs
apagarLEDs();
}

void loop() {
  // Preparamos el sensor de ultrasonidos
  iniciarTrigger();
 
  // Obtenemos la distancia
  float valDistancia = calcularDistancia();
 
  // Apagamos todos los LEDs
  apagarLEDs();
 
  // Lanzamos alerta si estamos dentro del rango de peligro
  if (valDistancia < umbral1)
  {
    // Lanzamos alertas
    alertas(valDistancia);
  }
 
}
 
// Apaga todos los LEDs
void apagarLEDs()
{
  // Apagamos todos los LEDs
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinRojo, LOW);
}
 
// Función que comprueba si hay que lanzar alguna alerta visual o sonora
void alertas(float valDistancia)
{
  if (valDistancia < umbral1 && valDistancia >= umbral2)
  {
    // Encendemos el LED verde
    digitalWrite(pinVerde, HIGH);
    tone(pinBuzzer, 2000, 200);
  }
  else if (valDistancia < umbral2 && valDistancia > umbral3)
  {
    // Encendemos el LED amarillo
    digitalWrite(pinAmarillo, HIGH);
    tone(pinBuzzer, 2500, 200);
  }
  else if (valDistancia <= umbral3)
  {
    // Encendemos el LED rojo
    digitalWrite(pinRojo, HIGH);
    tone(pinBuzzer, 3000, 200);
  }
}
 
// Método que calcula la distancia a la que se encuentra un objeto.
// Devuelve una variable tipo float que contiene la distancia
float calcularDistancia()
{
  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(pinEco, HIGH);
 
  // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  float valDistancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print(valDistancia);
  Serial.print("cm");
  Serial.println();
  delay(500);
 
  return valDistancia;
}
 
// Método que inicia la secuencia del Trigger para comenzar a medir
void iniciarTrigger()
{
  // Ponemos el Triiger en estado bajo y esperamos 2 ms
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
 
  // Ponemos el pin Trigger a estado alto y esperamos 10 ms
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
 
  // Comenzamos poniendo el pin Trigger en estado bajo
  digitalWrite(pinTrig, LOW);
}
