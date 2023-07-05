/*
 * Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
 * Programa que hace parpadear un el LED conectado al pin 2.
 * Para proteger al led hay que colocar una resistencia en serie con el de 330 ohmios.
 * Para variar el valor del brillo cambiaremos la resistencia en serie por una de 1K y luego de 10K
 */

int pinLed = 2;		// Se inicializa la constante pinLed como int


void setup()
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);	// Se inicializa el pin digital 13 como salida	
}

void loop()
{
  digitalWrite(pinLed, HIGH);	// enciende el LED, HIGH es nivel alto de voltaje)
  Serial.println("Led encendido");
  delay(1000); 			// Espera 1000 milisegundos (1 segundo)
  digitalWrite(pinLed, LOW);	// apaga el LED, LOW es nivel bajo de voltaje)
  Serial.println("Led apagado");
  delay(1000); 			// Espera 1000 milisegundos (1 segundo)
}
