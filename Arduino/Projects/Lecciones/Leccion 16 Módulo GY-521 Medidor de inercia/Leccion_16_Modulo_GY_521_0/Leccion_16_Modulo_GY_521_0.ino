/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz
   Programa que muestra los valores del aceleómetro y del giroscopio
*/


#include<Wire.h>

const int MPU_addr = 0x68; // Dirección I2C del MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);    // Comienza una transmisión al esclavo I2C (placa GY-521)
  Wire.write(0x6B);         // Registro PWR_MGMT_1
  Wire.write(0);            // Ajusta a cero (activa-inicializa el MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);         // comenzando con el registro 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);      // el parámetro indica que Arduino enviará un reinicio. Como resultado,
  Wire.requestFrom(MPU_addr, 14, true);   // solicita que uso los 7*2 = 14 registros que tiene

  // "Wire.read() << 8 | Wire.read();" Por cada valor x, y y z se leen y se almacenan dos registros en la misma variable
  AcX = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x3B (ACCEL_XOUT_H) y 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x3D (ACCEL_YOUT_H) y 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x3F (ACCEL_ZOUT_H) y 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x41 (TEMP_OUT_H) y 0x42 (TEMP_OUT_L)
  GyX = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x43 (GYRO_XOUT_H) y 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x45 (GYRO_YOUT_H) y 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read() << 8 | Wire.read(); // Lee los registros: 0x47 (GYRO_ZOUT_H) y 0x48 (GYRO_ZOUT_L)

  // Mostramos en el Monitor Serie los valores
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print("\t");
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print("\t");
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print("\t");
 // Serial.print(" | Tmp = "); Serial.print(Tmp / 340.00 + 36.53); //ecuación para la temperatura en grados Celsius
 // Serial.print("\t");
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print("\t");
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print("\t");
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(1500);
}
