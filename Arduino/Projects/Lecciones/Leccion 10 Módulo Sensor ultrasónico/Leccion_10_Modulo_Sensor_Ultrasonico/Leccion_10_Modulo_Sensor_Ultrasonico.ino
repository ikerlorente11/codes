/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que muestra en el Monitor Serial el valor de distancia leído por el sensor ultrasónico
   HC-SR04 y enciende.
*/

// Inicializamos variables
int pinTrig = 12;
int pinEco =  11;
long valDuracion;
long valDistancia;

void setup() {
  Serial.begin (9600);        // Inicializacion de la comunicacion serie a 9600 bps
  pinMode(pinTrig, OUTPUT);   // trigger como salida
  pinMode(pinEco, INPUT);     // echo como entrada
}

void loop() {

  // Generamos el pulso a enviar al pin conectado al trigger del sensor
  digitalWrite(pinTrig , LOW);
  delay(1);
  digitalWrite(pinTrig , HIGH);   // Flanco ascendente
  delay(1);                       // Duracion del pulso
  digitalWrite(pinTrig , LOW);    // Flanco descendente

  // Recepcion del eco de respuesta
  valDuracion = pulseIn(pinEco, HIGH);  // con funcion pulseIn se espera un pulso alto en Echo

  // Calculo de la distancia efectiva
  valDistancia = valDuracion / 58.2;    // Distancia medida en centimetros

  // Se muestran los resultados en el Monitor Serie
  if (valDistancia >= 500 || valDistancia <= 0) {
    Serial.println("Fuera de rango");
  }
  else {
    Serial.print("Distancia al objeto ");
    Serial.print(valDistancia);
    Serial.println(" cm");
  }

  // Retardo para disminuir la frecuencia de las lecturas
  delay(500);
}
