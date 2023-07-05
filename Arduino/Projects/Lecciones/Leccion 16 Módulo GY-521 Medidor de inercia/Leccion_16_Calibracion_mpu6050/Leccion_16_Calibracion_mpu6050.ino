/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz
   Programa para calibrar el sensor MPU6050.
*/


// Sketch  de Arduino que devuelve compensaciones de calibración para MPU6050 // Versión 1.1 (31 de enero de 2014)
// Hecho por Luis Radenas <luisrodenaslorda@gmail.com>
// Basado en la biblioteca I2Cdev y trabajo previo de Jeff Rowberg <jeff@rowberg.net>
// Las actualizaciones (de la biblioteca) deberían (con suerte) estar siempre disponibles en https://github.com/jrowberg/i2cdevlib

// Estas compensaciones estan destinadas a calibrar el DMP interno del MPU6050, pero también pueden ser útiles para leer sensores.
// El efecto de la temperatura no se ha tenido en cuenta, por lo que no se puede prometer que funcionará si se calibra en interiores 
// y luego se usa en exteriores. Lo mejor es calibrar y usar a la misma temperatura ambiente.

/* ==========  LICENCIA  ==================================
 El código de la biblioteca del dispositivo I2Cdev se coloca bajo la licencia del MIT Copyright (c) 2011 Jeff Rowberg
 
 Por la presente se otorga permiso, sin cargo, a cualquier persona que obtenga una copia de este software y los archivos 
 de documentación asociados (el "Software"), para utilizar el Software sin restricciones, incluidos, entre otros, los 
 derechos de uso, copia, modificación, fusión , publicar, distribuir, sublicenciar y/o vender copias del Software, 
 y permitir que las personas a quienes se les proporcione el Software lo hagan, sujeto a las siguientes condiciones:
 
 El aviso de copyright anterior y este aviso de permiso se incluirán en todas las copias o partes sustanciales del Software.
 
 EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O IMPLÍCITA, INCLUYENDO, PERO NO LIMITADO A,
 LAS GARANTÍAS DE COMERCIABILIDAD, APTITUD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO LOS AUTORES 
 O TITULARES DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE CUALQUIER RECLAMO, DAÑOS U OTRA RESPONSABILIDAD, 
 YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O DE OTRO MODO, QUE SURJA DE, FUERA DE O EN RELACIÓN CON EL SOFTWARE 
 O EL USO U OTRAS NEGOCIACIONES EN EL SOFTWARE.
 =========================================================
 */

// I2Cdev and MPU6050 must be installed as libraries

#include <Wire.h>
#include <I2Cdev.h>
#include <helper_3dmath.h>
#include <MPU6050_1.h>
//q1#include <MPU6050_6Axis_MotionApps20.h>
//#include <MPU6050_9Axis_MotionApps41.h>

///////////////////////////////////   CONFIGURATION   /////////////////////////////
//Change this 3 variables if you want to fine tune the skecth to your needs.
int buffersize=1000;     //Amount of readings used to average, make it higher to get more precision but sketch will be slower  (default:1000)
int acel_deadzone=8;     //Acelerometer error allowed, make it lower to get more precision, but sketch may not converge  (default:8)
int giro_deadzone=1;     //Giro error allowed, make it lower to get more precision, but sketch may not converge  (default:1)

// default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
//MPU6050 accelgyro;
MPU6050 accelgyro(0x68); // <-- use for AD0 high

int16_t ax, ay, az,gx, gy, gz;

int mean_ax,mean_ay,mean_az,mean_gx,mean_gy,mean_gz,state=0;
int ax_offset,ay_offset,az_offset,gx_offset,gy_offset,gz_offset;

///////////////////////////////////   SETUP   ////////////////////////////////////
void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  // COMMENT NEXT LINE IF YOU ARE USING ARDUINO DUE
  TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz). Leonardo measured 250kHz.

  // initialize serial communication
  Serial.begin(115200);

  // initialize device
  accelgyro.initialize();

  // wait for ready
  while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available()){
    Serial.println(F("Envíe cualquier caracter para empezar el programa.\n"));
    delay(1500);
  }                
  while (Serial.available() && Serial.read()); // empty buffer again

  // start message
  Serial.println("\nPrograma de calibración del MPU6050");
  delay(2000);
  Serial.println("\nDebe colocar su MPU6050 en posición horizontal, con las letras del paquete hacia arriba. \nNo lo toques hasta que veas un mensaje de finalización.\n");
  delay(3000);
  // verify connection
  Serial.println(accelgyro.testConnection() ? "Conexión del MPU6050 exitosa" : "La conexión MPU6050 falló");
  delay(1000);
  // reset offsets
  accelgyro.setXAccelOffset(0);
  accelgyro.setYAccelOffset(0);
  accelgyro.setZAccelOffset(0);
  accelgyro.setXGyroOffset(0);
  accelgyro.setYGyroOffset(0);
  accelgyro.setZGyroOffset(0);
}

///////////////////////////////////   LOOP   ////////////////////////////////////
void loop() {
  if (state==0){
    Serial.println("\nLectura de sensores por primera vez...");
    meansensors();
    state++;
    delay(1000);
  }

  if (state==1) {
    Serial.println("\nCalculando compensaciones (offsets)...");
    calibration();
    state++;
    delay(1000);
  }

  if (state==2) {
    meansensors();
    Serial.println("\nFINALIZADO!");
    Serial.print("\nLecturas del sensor con compensaciones:\t");
    Serial.print(mean_ax); 
    Serial.print("\t");
    Serial.print(mean_ay); 
    Serial.print("\t");
    Serial.print(mean_az); 
    Serial.print("\t");
    Serial.print(mean_gx); 
    Serial.print("\t");
    Serial.print(mean_gy); 
    Serial.print("\t");
    Serial.println(mean_gz);
    Serial.print("Your offsets:\t");
    Serial.print(ax_offset); 
    Serial.print("\t");
    Serial.print(ay_offset); 
    Serial.print("\t");
    Serial.print(az_offset); 
    Serial.print("\t");
    Serial.print(gx_offset); 
    Serial.print("\t");
    Serial.print(gy_offset); 
    Serial.print("\t");
    Serial.println(gz_offset); 
    Serial.println("\nLos datos se imprimen como: acelX acelY acelZ giroX giroY giroZ");
    Serial.println("Compruebe que las lecturas de su sensor estén cerca de 0 0 16384 0 0 0");
    Serial.println("Si la calibración fue exitosa, anote sus compensaciones para que pueda establecerlas en sus proyectos usando algo similar a mpu.setXAccelOffset(youroffset)");
    while (1);
  }
}

///////////////////////////////////   FUNCTIONS   ////////////////////////////////////
void meansensors(){
  long i=0,buff_ax=0,buff_ay=0,buff_az=0,buff_gx=0,buff_gy=0,buff_gz=0;

  while (i<(buffersize+101)){
    // read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    if (i>100 && i<=(buffersize+100)){ //First 100 measures are discarded
      buff_ax=buff_ax+ax;
      buff_ay=buff_ay+ay;
      buff_az=buff_az+az;
      buff_gx=buff_gx+gx;
      buff_gy=buff_gy+gy;
      buff_gz=buff_gz+gz;
    }
    if (i==(buffersize+100)){
      mean_ax=buff_ax/buffersize;
      mean_ay=buff_ay/buffersize;
      mean_az=buff_az/buffersize;
      mean_gx=buff_gx/buffersize;
      mean_gy=buff_gy/buffersize;
      mean_gz=buff_gz/buffersize;
    }
    i++;
    delay(2); //Needed so we don't get repeated measures
  }
}

void calibration(){
  ax_offset=-mean_ax/8;
  ay_offset=-mean_ay/8;
  az_offset=(16384-mean_az)/8;

  gx_offset=-mean_gx/4;
  gy_offset=-mean_gy/4;
  gz_offset=-mean_gz/4;
  while (1){
    int ready=0;
    accelgyro.setXAccelOffset(ax_offset);
    accelgyro.setYAccelOffset(ay_offset);
    accelgyro.setZAccelOffset(az_offset);

    accelgyro.setXGyroOffset(gx_offset);
    accelgyro.setYGyroOffset(gy_offset);
    accelgyro.setZGyroOffset(gz_offset);

    meansensors();
    Serial.println("...");

    if (abs(mean_ax)<=acel_deadzone) ready++;
    else ax_offset=ax_offset-mean_ax/acel_deadzone;

    if (abs(mean_ay)<=acel_deadzone) ready++;
    else ay_offset=ay_offset-mean_ay/acel_deadzone;

    if (abs(16384-mean_az)<=acel_deadzone) ready++;
    else az_offset=az_offset+(16384-mean_az)/acel_deadzone;

    if (abs(mean_gx)<=giro_deadzone) ready++;
    else gx_offset=gx_offset-mean_gx/(giro_deadzone+1);

    if (abs(mean_gy)<=giro_deadzone) ready++;
    else gy_offset=gy_offset-mean_gy/(giro_deadzone+1);

    if (abs(mean_gz)<=giro_deadzone) ready++;
    else gz_offset=gz_offset-mean_gz/(giro_deadzone+1);

    if (ready==6) break;
  }
}
