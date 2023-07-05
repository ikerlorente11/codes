/*
 * Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.  
 * Programa que hace parpadear el LED integrado de la placa Arduino MEGA2560R3.
 * La mayoría de las placas Arduino tienen un pin conectado a un LED integrado en serie con una resistencia.
 * La constante pinLed es el número de pin al cual esta conectado el LED integrado en la placa. 
 * La mayoría de las placas tiene este LED conectado al pin digital 13.
 */

int pinLed = 13;		// Se inicializa la constante pinLed como int


void setup()
{
  pinMode(pinLed, OUTPUT);	// Se inicializa el pin digital 13 como salida	
}

void loop()
{
  digitalWrite(pinLed, HIGH);	// enciende el LED, HIGH es nivel alto de voltaje)
  delay(1000); 			// Espera 1000 milisegundos (1 segundo)
  digitalWrite(pinLed, LOW);	// apaga el LED, LOW es nivel bajo de voltaje)
  delay(1000); 			// Espera 1000 milisegundos (1 segundo)
}
