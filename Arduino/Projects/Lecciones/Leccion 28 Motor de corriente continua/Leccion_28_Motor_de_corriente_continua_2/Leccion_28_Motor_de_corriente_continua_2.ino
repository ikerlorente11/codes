/*
  Prácticas de Arduino. Departamento de Ingeniería Eléctrica. Escuela de Ingeniería de Vitoria-Gasteiz.
  Programa que el mueve el motor de CC según el sentido que se le mande por el monitor serie y también introduciremos la velocidad desde 0 a 9.
  Si introducimos un valor mayor que 9 el motor girará a la velocidad del último digito.
*/

int habilitarM1 = 5;    // A HIGH (1) habilita el funcionamiento del motor 1 (Pin1 del L293D)
int pinAfavor  = 4;     // A HIGH (1) el motor 1 gira a favor de las agujas del reloj (Pin7 del L293D)
int pinEnContra = 3;    // A HIGH (1) el motor 1 gira en contra de las agujas del reloj (Pin2 del L293D)

int i;

void setup()
{
  Serial.begin(9600);
  pinMode(pinEnContra, OUTPUT);
  pinMode(pinAfavor, OUTPUT);
  Serial.println("Pulse primero la Direccion o Sentido de giro (- o +) y después Enter: ");   // Para camiar el sentido volver a enviar + o -
  Serial.println("Pulse despues el valor de la Velocidad de giro (0-9) y después Enter: ");   // El motor se moverá a partir del valor 3 (85)
}
void loop()
{
  if ( Serial.available()) {
    // detectado un dato por el Serial
    // leerlo
    char ch = Serial.read();
    // es un digito entre 0 y 9?
    if (isDigit(ch))
    {
      // mapear segun el digito ingresado
      // investigar la funcion MAP
      int velocidad = map(ch, '0', '9', 0, 255);
      analogWrite(habilitarM1, velocidad);
      Serial.println("");
      Serial.print("Grirando a velocidad: ");
      Serial.println(velocidad);
    }
    // si el dato ingresado no es 0 a 9
    else if (ch == '+')
    {
      Serial.println("");
      Serial.print("Girando en sentido Horario: ");
      digitalWrite(pinEnContra, LOW);
      digitalWrite(pinAfavor, HIGH);
    }
    else if (ch == '-')
    {
      Serial.println("");
      Serial.print("Girando en sentido Anti-horario: ");
      digitalWrite(pinEnContra, HIGH);
      digitalWrite(pinAfavor, LOW);
    }
    else
    {
      //Serial.println("Caracter ", ch, " no valido");
      Serial.print(ch);
      Serial.println("  Caracter no valido");
      Serial.println("Por favor envie (+ o -) o (0-9)");

    }
  }
}
