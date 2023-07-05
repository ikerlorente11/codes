#include <IRremote.h>         // Libreria para el infrarrojo
#include <LedControl.h>       // Libreria para la matriz led
#include <SoftwareSerial.h>   // Libreria bluetooth
#include <SPI.h>              // Librerias lara la pantalla OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pines para la pantalla de 4 digitos
int a = 6;
int b = 7;
int c = 8;
int d = 9;
int e = 10;
int f = 11;
int g = 12;
int h = 13;
int timeDelay = 1; // Delay entre frames de la pantalla de 4 digitos

// Configuracion infrarrojos
int receptor = 22;            // Pin infrarojos
IRrecv irrecv(receptor);
decode_results results;

// Configuracion bluetooth
SoftwareSerial miBT(50, 51);  // Pines bluetooth  50->TXD || 51->RXD          NOTA: No todos los pines valen para esto
String value = "";            // Valor que generamos a partir de los datos que recibimos por el Bluetooth
bool cont = false;            // Contador de estado de recepcion
bool rec = false;             // Estado de la recepcion

// Seteo datos iniciales del marcador, la posesion y el tiempo del cuarto restante
int local = 0;
int visitante = 0;
unsigned long startTime;
int posesion = 24;
int tiempo = 600;

// Pines para la matriz de leds
int pinCs = 23;
int pinDin = 24;
int pinClk = 25;

// Pin zumbador
int zumbador = 26;

// Seteo encendido de pantallas y pausa
bool on = false;
bool paused = true;

// Configuracion matriz leds
LedControl lc = LedControl(pinDin, pinClk, pinCs, 1);

void setup() {
  Serial.begin (9600);

  // Marcamos los pines de la pantalla de 4 digitos como salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);

  // Marcamos el pin del zumbador como salida
  pinMode(zumbador, OUTPUT);

  // Habilitamos infrarrojo
  irrecv.enableIRIn();

  // Inicializamos bluetooth
  miBT.begin(38400);

  // Establecemos el tiempo inicial a 0
  startTime = 0;

  // Configuramos la matriz de leds para el inicio
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  setScreen();    // Actulizamos la pantalla OLED
}

// Establecemos las opciones para la matriz de leds
#define g24 {B01101001,B10011001,B00011001,B00011111,B00100001,B01000001,B10000001,B11110001}
#define g23 {B01100110,B10011001,B00010001,B00010110,B00100110,B01000001,B10001001,B11110110}
#define g22 {B01100110,B10011001,B00010001,B00010001,B00100010,B01000100,B10001000,B11111111}
#define g21 {B01100001,B10010011,B00010101,B00011001,B00100001,B01000001,B10000001,B11110001}
#define g20 {B01100110,B10011001,B00011001,B00011001,B00101001,B01001001,B10001001,B11110110}
#define g19 {B00010110,B00111001,B01011001,B10010111,B00010001,B00010001,B00010001,B00010110}
#define g18 {B00010110,B00111001,B01011001,B10010110,B00010110,B00011001,B00011001,B00010110}
#define g17 {B00011111,B00110001,B01010001,B10010001,B00010001,B00010001,B00010001,B00010001}
#define g16 {B00010110,B00111000,B01011000,B10011000,B00011110,B00011001,B00011001,B00010110}
#define g15 {B00011111,B00111000,B01011000,B10011110,B00010001,B00010001,B00011001,B00010110}
#define g14 {B00011001,B00111001,B01011001,B10011111,B00010001,B00010001,B00010001,B00010001}
#define g13 {B00010110,B00111001,B01010001,B10010110,B00010110,B00010001,B00011001,B00010110}
#define g12 {B00010110,B00111001,B01010001,B10010001,B00010010,B00010100,B00011000,B00011111}
#define g11 {B00010001,B00110011,B01010101,B10011001,B00010001,B00010001,B00010001,B00010001}
#define g10 {B00010110,B00111001,B01011001,B10011001,B00011001,B00011001,B00011001,B00010110}
#define g09 {B01100110,B10011001,B10011001,B10010111,B10010001,B10010001,B10010001,B01100110}
#define g08 {B01100110,B10011001,B10011001,B10010110,B10010110,B10011001,B10011001,B01100110}
#define g07 {B01101111,B10010001,B10010001,B10010001,B10010001,B10010001,B10010001,B01100001}
#define g06 {B01100110,B10011000,B10011000,B10011000,B10011110,B10011001,B10011001,B01100110}
#define g05 {B01101111,B10011000,B10011000,B10011110,B10010001,B10010001,B10011001,B01100110}
#define g04 {B01101001,B10011001,B10011001,B10011111,B10010001,B10010001,B10010001,B01100001}
#define g03 {B01100110,B10011001,B10010001,B10010110,B10010110,B10010001,B10011001,B01100110}
#define g02 {B01100110,B10011001,B10010001,B10010001,B10010010,B10010100,B10011000,B01101111}
#define g01 {B01100001,B10010011,B10010101,B10011001,B10010001,B10010001,B10010001,B01100001}
#define g00 {B01100110,B10011001,B10011001,B10011001,B10011001,B10011001,B10011001,B01100110}

byte matrixs[25][8] = {g00, g01, g02, g03, g04, g05, g06, g07, g08, g09, g10, g11, g12, g13, g14, g15, g16, g17, g18, g19, g20, g21, g22, g23, g24};

void loop() {
  receiveData();

  if(on){                             // Si la pantalla esta encendida
    setNumber((int) local/10,0);      // Establecemos el primer digito
    setNumber((int) local%10,1);      // Establecemos el segundo digito
    setNumber((int) visitante/10,2);  // Establecemos el tercer digito
    setNumber((int) visitante%10,3);  // Establecemos el cuarto digito
  }
  
  int pasedTime = (int) ((millis() - startTime) / 1000);  // Calculamos el tiempo que ha pasado desde la ultima parada
  if(!paused){                                            // Si no esta parado
    if(pasedTime <= posesion && pasedTime <= tiempo && on){                      // Si no ha terminado la posesion ni el tiempo y la pantalla esta encendida
      setMatrix(posesion - pasedTime);                    // Actualizamos la matriz de leds
    }else{
      paused = true;                                      // Reseteamos la matriz de leds, el tiempo y hacemos sonar el zumbador
      posesion = 24;
      if(tiempo - pasedTime <= 0){
        tiempo = 600;
      }else{
        tiempo -= pasedTime;
      }
      digitalWrite(zumbador, HIGH);
      delay(1000);
      digitalWrite(zumbador, LOW);
    }
  }else if(on){                                           // Si esta parado y la pantalla encendida, se muestra la posesion fija en la matriz de leds
    setMatrix(posesion);
  }

  //Serial.println(String("Marcador: ") + local + String(":") + visitante + String(" || Posesion: ") + posesion + String(" || Encendido: ") + on);
}

/*
 * Funcion para recivir datos tanto de bluetooth como de infrarrojos y actualizar los marcadores y estados
 */
void receiveData(){
  if (irrecv.decode(&results))  //Si recibe un dato el sensor infrarrojo
  {
    int val = results.value;
    Serial.println(val);
    updateScoreboard(abs(val)); // Actualizamos el marcador
  }

  if (miBT.available()){
    // Leemos el dato y le restamos 48 para pasar el numero de su codigo ascii a decimal
    String temp = String(value + String(miBT.read() - 48));
    //Serial.println(temp);

    // Comprobamos que el dato no excede al maximo para evitar errores
    if(temp.toInt() <= 32000){
      value = temp;
    }

    // Activamos el estado de la recepcion
    rec = true;
    // Aumentamos el contador de recepcion para saber que aun estamos recibiendo
    cont = true;
  }
  
  if(!cont and rec){
    // Volvemos a comprobar que el dato no excede al maximo para evitar errores
    if(value.toInt() <= 32000){
      updateScoreboard(value.toInt()); // Actualizamos el marcador
      //Serial.println(value.toInt());
    }

    // Reseteamos el valor y desactivamos el estado de recepcion
    value = "";
    rec = false;
  }

  if(cont){
    // Reducimos el contador de recepcion para suponer que ya no estamos recibiendo datos
    cont = false;
  }
}

/*
 * Funcion para actualizar el marcador
 * Parametros: int val -> valor del dato recibido por el sendor infrarrojo
 */
void updateScoreboard(int val){
  Serial.println(val);
  int pasedTime = (int) ((millis() - startTime) / 1000);
  if(on){                           // Si la pantalla esta encendida
    switch(val){
      case 12495:                   // 1
        if(local + 1 < 100){        // Si la puntuacion de los locales no es mayor o igual a 99
          local += 1;               // Sumamos 1 a la puntuacion de los locales
        }
      break;
      case 4335:                    // 4
        if(local + 2 < 100){        // Si la puntuacion de los locales no es mayor o igual a 99
          local += 2;               // Sumamos 2 a la puntuacion de los locales
        }
      break;
      case 17085:                   // 7
        if(local + 3 < 100){        // Si la puntuacion de los locales no es mayor o igual a 99
          local += 3;               // Sumamos 3 a la puntuacion de los locales
        }
      break;
      case 31365:                   // 3
        if(visitante + 1 < 100){    // Si la puntuacion de los visitantes no es mayor o igual a 99
          visitante += 1;           // Sumamos 1 a la puntuacion de los visitantes
        }
      break;
      case 23205:                   // 6
        if(visitante + 2 < 100){    // Si la puntuacion de los visitantes no es mayor o igual a 99
          visitante += 2;           // Sumamos 2 a la puntuacion de los visitantes
        }
      break;
      case 21165:                   // 9
        if(visitante + 3 < 100){    // Si la puntuacion de los visitantes no es mayor o igual a 99
          visitante += 3;           // Sumamos 3 a la puntuacion de los visitantes
        }
      break;
      case 7651:                    // FUNC/STOP -> Reset
        local = 0;                  // Reseteamos las pantallas
        visitante = 0;
        startTime = millis();
        posesion = 24;
        tiempo = 600;
      break;
      case 6375:                    // 2 -> Reset marcador
        local = 0;                  // Reseteamos las pantallas
        visitante = 0;
      break;
      case 14535:                    // 5 -> Reset posesion
        if(!paused){
          tiempo -= pasedTime;
        }
        startTime = millis();
        posesion = 24;
      break;
      case 19125:                    // 8 -> Reset tiempo
        if(!paused){
          posesion -= pasedTime;
        }
        startTime = millis();
        tiempo = 600;
        setScreen();                // Actulizamos la pantalla OLED
      break;
      case 23971:                   // ON/OFF
        on = false;                 // Apagamos las pantallas
        setScreen();                // Actulizamos la pantalla OLED
      break;
      case 765:                     // PLAY/PAUSE
        if(paused){                 // Si pausado
          paused = false;           // Continuamos y reseteamos el temporizador de pausa
          startTime = millis();
        }else{
          paused = true;            // Pausamos y actualizamos la posesion y el tiempo restante
          int pasedTime = (int) ((millis() - startTime) / 1000);
          posesion -= pasedTime;
          tiempo -= pasedTime;
        }
        setScreen();                // Actulizamos la pantalla OLED
      break;
    }
    
    if(val == 8925){                // Retroceso
      if(local + 1 < 100){          // Si la puntuacion de los locales no es mayor o igual a 99
        local += 1;                 // Sumamos 1 a la puntuacion de los locales
      }
    }
    if(val == 8161){                // Abajo
      if(local - 1 > -1){           // Si la puntuacion de los locales no es menor o igual a 0
        local -= 1;                 // Restamos 1 a la puntuacion de los locales
      }
    }
    if(val == 15811){               // Avance
      if(visitante + 1 < 100){      // Si la puntuacion de los visitantes no es mayor o igual a 99
        visitante += 1;             // Sumamos 1 a la puntuacion de los visitantes
      }
    }
    if(val == 28561){               // Arriba
      if(visitante - 1 > -1){       // Si la puntuacion de los visitantes no es menor o igual a 0
        visitante -= 1;             // Restamos 1 a la puntuacion de los visitantes
      }
    }
  }else if(val == 23971){           // Si las pantallas estan apagadas y ON/OFF
    on = true;                      // Encendemos las pantallas
    setScreen();                    // Actulizamos la pantalla OLED
  }

  //Serial.println(val); // Muestra el dato en el monitor serie
  irrecv.resume();   
}

/*
 * Funcion para actualizar la pantalla de 4 digitos
 * Parametros: int val -> numero a imprimir en la pantalla de 4 digitos
 *             int digit -> digito a modificar
 */
void setNumber(int number, int digit){
  digit = digit + 2;              // Seleccionamos el digito a modificar

  digitalWrite(2, HIGH);          // Reseteamos todos los digitos
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  switch(number){                 // Seteamos los pines necesarios para cada numero
    case 0:
      digitalWrite(digit, LOW);
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 1:
      digitalWrite(digit, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 2:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 3:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 4:
      digitalWrite(digit, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 5:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 6:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 7:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 8:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    case 9:
      digitalWrite(digit, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      delay(timeDelay);
      digitalWrite(digit, HIGH);
    break;
    default:
    break;
  }
}

/*
 * Funcion para actualizar la matriz de leds
 * Parametros: int number -> numero a imprimir en la matriz de leds
 */
int matrixLastData = 0;
void setMatrix(int number){
  if(number != matrixLastData){     // Actualizamos la pantalla OLED cada segundo
    matrixLastData = number;
    setScreen();                    // Actulizamos la pantalla OLED
  }
	for (int i = 0; i < 8; i++) {               // Por cada fila
        lc.setRow(0, i, matrixs[number][i]);  // Encendemos los leds necesarios
    }
  delay(timeDelay);
  lc.clearDisplay(0);

  //Serial.println(number);
}

/*
 * Funcion para actualizar la pantalla OLEDs
 */
void setScreen(){
  if(!on){                                    // Si la pantalla esta apagada mostramos el mensaje Zzz
    display.clearDisplay();

    display.setTextSize(6);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,20);
    display.println(F("Zzz"));

    display.display();
  }else if(paused){                           // Si esta encendida pero pausada mostramos el tiempo en pausa
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,00);
    display.println(F("   Pausa"));

    display.setTextSize(4);
    display.println(secToTime(tiempo));
    
    display.display();
  }else{                                      // Mostramos el tiempo restante
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,00);
    display.println(F("  Jugando"));

    display.setTextSize(4);
    int pasedTime = (int) ((millis() - startTime) / 1000);  // Calculamos el tiempo que ha pasado desde la ultima parada
    display.println(secToTime(tiempo - pasedTime));
    
    display.display();
  }
}

/*
 * Funcion para pasar segundos a minutos y segundos (m:s)
 * Parametros: int sec -> segundos
 * Retorno: String -> minutos y segundos en formato m:s
 */
String secToTime(int sec){
  int m = sec / 60;         // Calculamos los minutos
  int s = sec - (m * 60);   // Calculamos los segundos

  String mc = String(m);    // Transformamos minutos y segundos en Strings
  String sc = String(s);

  if(m < 10){               // Rellenamos los espacios vacios con 0
    mc = "0" + String(m);
  }
  if(s < 10){
    sc = "0" + String(s);
  }
  
  return mc + ":" + sc;
}
