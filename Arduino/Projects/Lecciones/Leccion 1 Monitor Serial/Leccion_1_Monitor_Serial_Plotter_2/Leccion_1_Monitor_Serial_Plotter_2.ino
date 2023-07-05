/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que enciende y `paga el LED interno y muestra si está a 1 o a 0 en el serial plotter. Mostrando  el pulso.
  En el monitor serie indica si está a 1 o a 0, dice si está a ON o a OFF o si está encendido o apagado.
*/


void setup() {
  // Inicializa el pin digital 13 como salida.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {

  int segundos = millis() / 1000;
  if (segundos % 2 == 0) {
    digitalWrite(13, HIGH);   // Enciende el LED (nivel de voltaje ALTO)
    Serial.print("1");
    Serial.print('\t');
    Serial.print("ON");
    Serial.print('\t');
    Serial.println("Led encendido");
  }
  else {
    digitalWrite(13, LOW);    // Apagua el LED haciendo que el voltaje sea BAJO
    Serial.print("0");
    Serial.print('\t');
    Serial.print("OFF");
    Serial.print('\t');
    Serial.println("Led apagado");
  }
}
