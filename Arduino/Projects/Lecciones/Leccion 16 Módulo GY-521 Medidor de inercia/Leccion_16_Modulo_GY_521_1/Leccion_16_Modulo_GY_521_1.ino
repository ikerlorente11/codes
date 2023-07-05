

#include <Wire.h>

//Direccion I2C de la IMU
#define MPU 0x68

//Ratios de conversion
#define A_R 16384.0   // 32768/2 para medir la aceleración medida en g.
#define G_R 131.0     // 32768/250 para conocer el giro en grados/s-1

//Conversion de radianes a grados 180/PI
#define RAD_A_DEG = 57.295779 // 180/pi

//MPU-6050 da los valores en enteros de 16 bits
//Valores sin refinar
int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;

int pinLed = 3;
int pinLed1 = 4;

//Angulos de inclinación
float Acc[2];
float Gy[3];
float Angle[3];

float ROLL_ALABEO;
float PITCH_CABECEO;
float YAW_GUINADA;



long tiempo_prev;
float dt;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop()
{
  //Leer los valores del Acelerometro de la IMU
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); //Pedir el registro 0x3B - corresponde al AcX
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); //A partir del 0x3B, se piden 6 registros
  AcX = Wire.read() << 8 | Wire.read(); //Cada valor ocupa 2 registros. Valores enteros de 16 bits
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  //A partir de los valores del acelerometro, se calculan los angulos Y, X
  //respectivamente, con la formula de la tangente.
  Acc[1] = atan(-1 * (AcX / A_R) / sqrt(pow((AcY / A_R), 2) + pow((AcZ / A_R), 2))) * RAD_TO_DEG;
  Acc[0] = atan((AcY / A_R) / sqrt(pow((AcX / A_R), 2) + pow((AcZ / A_R), 2))) * RAD_TO_DEG;

  //Leer los valores del Giroscopio
  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);       // A partir del 0x43, se piden 6 registros
  GyX = Wire.read() << 8 | Wire.read(); // Cada valor ocupa 2 registros
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();

  //Calculo del angulo del Giroscopio, para obtener los valores en grado sobre segundos
  Gy[0] = GyX / G_R;
  Gy[1] = GyY / G_R;
  Gy[2] = GyZ / G_R;

  dt = (millis() - tiempo_prev) / 1000.0;
  tiempo_prev = millis();

  //Aplicar el Filtro Complementario
  Angle[0] = 0.98 * (Angle[0] + Gy[0] * 0.010) + 0.02 * Acc[0];
  Angle[1] = 0.98 * (Angle[1] + Gy[1] * 0.010) + 0.02 * Acc[1];

  // Integración respecto del tiempo para calcular el YAW
  Angle[2] = Angle[2] + Gy[2] * dt;

  float ROLL_ALABEO = Angle[0];
  float PITCH_CABECEO = Angle[1];
  float YAW_GUINADA = Angle[2];

  //Mostrar los valores por consola
  // Serial.print("Angle X: "); Serial.print(Angle[0]); Serial.print("\n");
  // Serial.print("Angle Y: "); Serial.print(Angle[1]); Serial.print("\n------------\n");

  Serial.print("90");               // Eje de +90 grados color Azul
  Serial.print(",");
  Serial.print(ROLL_ALABEO);         // Eje ROLL-ALABEO color ROJO
  Serial.print(",");
  Serial.print(PITCH_CABECEO);         // Eje PITCH-CABECEO color VERDE
  Serial.print(",");
  Serial.print(YAW_GUINADA);         // Eje YAW-GUIÑADA color AMARILLO
  Serial.print(",");
  Serial.println("-90");            // Eje de -90 grados color MORADO

  if ( PITCH_CABECEO > 30.0 ) {    // si el pitch es mayor a 10 grados
    digitalWrite(pinLed, HIGH);   // muestra texto
  }
  else {
    if ( PITCH_CABECEO < -30.0) {   // si el pitch es menor a -30 grados
      digitalWrite(pinLed1, HIGH);   // muestra texto
    }
    //  if ( PITCH_CABECEO < 30.0 || PITCH_CABECEO < -30.0) {   // si el pitch es menor a -30 grados
    else {
      digitalWrite(pinLed, LOW);   // muestra texto
      digitalWrite(pinLed1, LOW);   // muestra texto
    }
  }
  delay(10); //Nuestra dt sera, pues, 0.010, que es el intervalo de tiempo en cada medida
}
