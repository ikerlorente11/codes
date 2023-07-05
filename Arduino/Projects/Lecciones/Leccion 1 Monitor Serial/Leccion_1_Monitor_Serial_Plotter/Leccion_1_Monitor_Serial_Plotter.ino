/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que representa las ecuaciones 5x+1 y x*x el serial plotter.
*/


int x = -20;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(5 * x + 1); // Gráfico azul
  Serial.print(",");
  Serial.println(x * x); // Gráfico rojo

  x++;
  delay(5);
  if (x == 20) x = -20;
}
