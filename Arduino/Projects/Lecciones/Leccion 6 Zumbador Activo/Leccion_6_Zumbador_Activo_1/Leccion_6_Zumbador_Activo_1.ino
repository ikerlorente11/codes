/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que hace vibrar a un buzzer activo a dos frecuencias distintas.
*/

int pinBuzzer = 3; // El pin del zumbador activo
void setup()
{
 pinMode(pinBuzzer,OUTPUT);// Se define el pin del zumbador como salida
}
void loop()
{
 unsigned char i;
 while(1)
 {
   // Se genera una frecuencia
   for(i=0;i<80;i++)
   {
    digitalWrite(pinBuzzer,HIGH);    // Se pone el Pin a HIGH
    delay(1);                     // Se espera 1 ms
    digitalWrite(pinBuzzer,LOW);     // Se pone el Pin a LOW
    delay(1);                     // Se espera 1 ms
    }
    // Se genera otra frecuencia
     for(i=0;i<100;i++)
      {
       digitalWrite(pinBuzzer,HIGH); // Se pone el Pin a HIGH
       delay(2);                  // Se espera 2 ms
       digitalWrite(pinBuzzer,LOW);  // Se pone el Pin a LOW
       delay(2);                  // Se espera 2 ms
    }
  }
} 
