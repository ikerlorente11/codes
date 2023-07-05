/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que realiza un giro completo del motor 28BYJ-48 en conjunto con el controlador basado en ULN2003,
  detiene 5 segundos y luego comienza nuevamente.
  La secuencia dependerá del paso elegido. Habrá que quitar el comentario y activar el paso elegido.
  Se puede elegir entre:
  - Paso completo simple
  - Paso completo con maximo torque
  - Medio paso
  Hay que alimentar Arduino con fuente de alimentacion externa de 6 a 12 Vcc.
*/

int IN1 = 8;      // pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 9;      // pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 10;     // pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 11;     // pin digital 11 de Arduino a IN4 de modulo controlador
int demora = 10;  // demora entre pasos, no debe ser menor a 10 ms. Velocidad motor

// Quitar este comentario si queremos usar el paso completo simple
  // paso completo simple
  int paso [4][4] =    // matriz (array bidimensional) con la secuencia de pasos
  {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
  };
  const int numPasos = 4;


/* Quitar este comentario si queremos usar el paso completo con maximo torque
   // paso completo con maximo torque
  int paso [4][4] =    // matriz (array bidimensional) con la secuencia de pasos
  {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
  };
  const int numPasos = 4;
*/
/*
// medio paso
int paso [8][4] =    // matriz (array bidimensional) con la secuencia de pasos
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
const int numPasos = 8;
*/

void setup() {
  pinMode(IN1, OUTPUT);   // todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
// 512*8 = 4096 pasos 82 segundos para dar una vuelta o 512*4 = 2048 pasos 41 segundos para dar una vuelta
  for (int i = 0; i < 512; i++)  
  {
    for (int i = 0; i < numPasos; i++)   // bucle recorre la matriz de a una fila por vez
    { // para obtener los valores logicos a aplicar
      digitalWrite(IN1, paso[i][0]);  // a IN1, IN2, IN3 e IN4
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(demora);
    }
  }

  digitalWrite(IN1, LOW); // detiene por 5 seg.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(5000);

}
