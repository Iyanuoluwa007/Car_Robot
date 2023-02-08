//Ultra Sonic Sensor
//It’s has 4 terminal, VCC, Ground, Trigger and Echo

int pin1=7; //Echo pin or Input
int pin2=6; //Trigger pin or Output
int D; 
int Dis; //Distance of obstacle
#include <Servo.h>
Servo motor;
void setup() {
  // put your setup code here, to run once:
pinMode(pin2,OUTPUT);
pinMode(pin1,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pin2,LOW);
delayMicroseconds(2);
digitalWrite(pin2,HIGH);
delayMicroseconds(10);
digitalWrite(pin2,LOW);

//D = 1/2 x T x C
D = pulseIn(pin1,HIGH);
// Serial.println(D);
Dis = D * 0.034 / 2 ;
Serial.print(Dis); // While Final Coding Dis will Stop all Movement at 5cm
Serial.println("cm");
}
