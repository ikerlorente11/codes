/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que muestra el valor de un contador enviado desde la placa Arduino en el monitor serie.
  Este valor se incrementa cada segundo.
*/

int cont = 0;

void setup() {
  //iniciamos el puerto serie
  Serial.begin(9600);
}

void loop() {
  //Imprimimos el valor del contador
  Serial.print("Contador: ");
  Serial.println(cont);

  //incrementamos el contador y esperamos un segundo
  cont++;
  delay(1000);
}
