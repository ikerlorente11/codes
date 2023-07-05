#include <SoftwareSerial.h>
SoftwareSerial miBT(10, 11);

int LED = 2;            // Pin del led a encender
String value = "";      // Valor que generamos a partir de los datos que recibimos por el Bluetooth
int cont = 0;           // Contador de estado de recepcion
bool rec = false;       // Estado de la recepcion
const int lmax = 500;   // Limite maximo del valor que tenemos pensado recibir
const int lmin = 0;     // Limite minimo del valor que tenemos pensado recibir

void setup() {
  Serial.begin(9600);
  miBT.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (miBT.available()){
    // Leemos el dato y le restamos 48 para pasar el numero de su codigo ascii a decimal
    String temp = String(value + String(miBT.read() - 48));

    // Comprobamos que el dato no excede al maximo para evitar errores
    if(temp.toInt() <= lmax){
      value = temp;
    }

    // Activamos el estado de la recepcion
    rec = true;
    // Aumentamos el contador de recepcion para saber que aun estamos recibiendo
    cont++;
  }
  
  if(cont == 0 and rec){
    // Volvemos a comprobar que el dato no excede al maximo para evitar errores
    if(value.toInt() <= lmax){
      // Codigo si estamos usando una franja diferente a 0 y 255
      int data = map(value.toInt(), lmin, lmax, 0, 255);
      Serial.println(data); 
      analogWrite(LED, data);

      // Codigo si estamos usando una franja entre 0 y 255
      //Serial.println(value);
      //analogWrite(LED, value.toInt()); 
    }

    // Reseteamos el valor y desactivamos el estado de recepcion
    value = "";
    rec = false;
  }

  if(cont > 0){
    // Reducimos el contador de recepcion para suponer que ya no estamos recibiendo datos
    cont--;
  }
}
