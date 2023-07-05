/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que representa la ecuacion x * x + 5 * x - 6 el serial plotter.
*/

int x = -20;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("460");
  Serial.print(",");
  Serial.print(x * x + 5 * x - 6);
  Serial.print(",");
  Serial.println("-30");
  x++;
  delay(5);
  if (x == 20) x = -20;
}
