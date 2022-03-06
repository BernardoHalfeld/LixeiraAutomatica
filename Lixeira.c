#include <Servo.h>   //Biblioteca do Servo Motor
Servo servo;     
int trigPin = 2;    
int echoPin = 3;   
int servoPin = 4;
long duration, dist, average;   
long aver[3];  


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);//Inicia com a tampa fechada
    delay(100);
    servo.detach(); 
} 

void measure() {  
 //digitalWrite(HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;//Obtem a distância
}
void loop() { 
  for (int i=0;i<=2;i++) {//verifica a distância
    measure();               
   aver[i]=dist;            
    delay(10);//adiciona um atraso as medições
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist<50 ) {
 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}
Serial.print(dist);
}