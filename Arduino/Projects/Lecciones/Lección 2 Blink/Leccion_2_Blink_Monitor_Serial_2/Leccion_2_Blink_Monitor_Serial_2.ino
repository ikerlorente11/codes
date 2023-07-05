/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que hace parpadear el LED integrado en la placa Arduino el numero de veces que le mandas por el monitor serie.  
*/

int option;
int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  //si existe información pendiente
  if (Serial.available() > 0) {
    //leeemos la opcion
    char option = Serial.read();
    //si la opcion esta entre '1' y '9'
    if (option >= '1' && option <= '9')
    {
      //restamos el valor '0' para obtener el numeroenviado
      option -= '0';
      for (int i = 0; i < option; i++) {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(300);
      }
    }
  }
}
