/*
   Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
   Programa que enciende un LED conectado al pin 4 con el botón A y lo apaga con el botón B.
*/

int ledPin = 4;
int botonApin = 3;
int botonBpin = 2;

void setup()
{
  pinMode(ledPin, OUTPUT);            // pin del led como salida
  pinMode(botonApin, INPUT_PULLUP);   // pin del pulsador A como entrada
  pinMode(botonBpin, INPUT_PULLUP);   // pin del pulsador B como entrada
}

void loop()
{
  if (digitalRead(botonApin) == HIGH) // Si el botón A está presionado endiendo el Led
  {
    digitalWrite(ledPin, HIGH);       // endiendo el Led
  }
  if (digitalRead(botonBpin) == HIGH) // Si el botón B está presionado apago el Led
  {
    digitalWrite(ledPin, LOW);        // apago el Led
  }
}
