//Proyecto R2D2 (Arturito)
//Autor: Edwin Ramirez Mondragon

const int LEDPin = 13;          // pin para el LED (Arturito)
const int PIRPin = 7;          // pin de entrada  sensor(Para el sensor de movimiento)
const int pin4 = 4;           // pin para el motor

////Serbo
#include <Servo.h>             //Si se utliza se desactiva las pwm en pin 9 y 10 en arduino
Servo miServo; 
const int pinServo = 2;       //pin para el serbo
const int pinPot = 0;
const int pulsoMin = 650;    // pulso de 1000 a 20000 microsegundos
const int pulsoMax = 2550;  // pulso maximo de servo 180
int valor; 
int angulo;
////***

int pirState = LOW;           // De inicio no hay movimiento en sensor

int val = 0; // estado del pin para el sensor de movimiento 
void setup()
{
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);    // Led 
  pinMode(PIRPin, INPUT);    //Pin de sensor
  pinMode(12, OUTPUT);      // pin 12 buzzer
  pinMode(4,OUTPUT);       //pin motor  
  
  ////**SERBO pasamos como parametro el (pin , pulso minimo, pulso maximo)
  miServo.attach(pinServo, pulsoMin, pulsoMax);
  ///

}

void loop()
{
  val = digitalRead(PIRPin); // leemos el pin del sensor
 if (val == HIGH)          //si se recibe una señal del sensor de movimiento entonces
  {        
    tone(12, 370);        // como parametros el pin utilizado y la frecuencia que emitira
    delay(100);          //tiempo que sonora el tono de el buzzer
    noTone(12);         // Se debe apagar el buzzer si no este seguira sonando
    
    digitalWrite(LEDPin, HIGH);  //Encerdemos el led (Arturito)
    
    miServo.write(90);  //Mandos el angulo que girara el serbomotor para simular el giro de la cabeza
    delay(1000);        //Tiempo

    tone(12, 349); //#D Mi
    delay(200);
    noTone(12);
    tone(12, 200); 
    delay(200);
    noTone(12);
   
    miServo.write(0);  // Regresamos al serbo ala posicion inicial 
    delay(2000);
    
    tone(12, 277); 
    delay(200);
    noTone(12);
    digitalWrite(LEDPin, LOW);  //Encendomos led
    delay(300);
    digitalWrite(LEDPin, HIGH);  //Apagamos Led
    tone(12, 440);
    delay(200);
    noTone(12);
       
    digitalWrite(4,HIGH);  // Mandomos corriente al motor
    delay(2500);          // Tiempo de giro 
    digitalWrite(4,LOW); //Apagamos motor

    miServo.write(90); // Giro de serbo
    delay(2000);             

    digitalWrite(LEDPin, HIGH);  //Led Encendido
    delay(200);
    digitalWrite(LEDPin, LOW);  //
    delay(100);
    digitalWrite(LEDPin, HIGH);  //Led Apagado      
    
    tone(12, 330);
    delay(200);
    noTone(12);
    tone(12, 149); 
    delay(200);
    noTone(12);

    miServo.write(0);
    delay(1000);
   
    tone(12, 440); 
    delay(200);
    noTone(12);
    tone(12, 140); 
    delay(200);
    noTone(12);
   
 if (pirState == LOW)  //si previamente estaba apagado el sensor
    {   
      pirState = HIGH;    //Lo encendemos
      digitalWrite(LEDPin, LOW); 
    }
  }
  
  else   //si esta desactivado
    {
    digitalWrite(LEDPin, LOW); // Led Apagado
    if (pirState == HIGH)  //Si previamente estaba encendido
    {      
      pirState = LOW;      
    }
  }
}
