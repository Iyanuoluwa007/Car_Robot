#include <AFMotor.h>   //AFMotor.h Library

  AF_DCMotor motor1(1); //Front Left Wheel
  AF_DCMotor motor2(2); //Back Left Wheel
  AF_DCMotor motor3(3); //Front Right Wheel
  AF_DCMotor motor4(4); //Back Right Wheel



// Include Other Libraries
  #include "Arduino.h"
  #include "SoilMoisture.h"
  #include "DHT.h"

  int data = 0;

// Pin Definitions
  #define SOILMOISTURE_5V_PIN_SIG	A3 //Connected to Pin A3 
  #define DHT_PIN_DATA  2 //Connected to Pin 2 

// object initialization
  SoilMoisture soilMoisture_5v(SOILMOISTURE_5V_PIN_SIG);
  DHT dht(DHT_PIN_DATA);

  #include <Servo.h>
  Servo motor5;
  
  int pin = 10;

  int pin1=7; //Echo pin or Input
  int pin2=6; //Trigger pin or Output
  int D; 
  int Dis; //Distance of obstacle

  
// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() {
    Serial.begin(9600);
    Serial.println("Ready...");
    
    dht.begin();

    motor5.attach(pin);

    pinMode(pin2,OUTPUT); 
    pinMode(pin1,INPUT);


    motor1.setSpeed(255);   //Set Motor Speed
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() {
    if (Serial.available() > 0) { // Checks whether data is comming from the serial port
    data = Serial.read(); // Reads the data from the serial port

    // Moving Wheel Code:
    
// Forward
      if (data == '2') {
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
      delay(10); 
      Serial.println("Moving Forward");
      }

// Backward
      else if (data == '8') {
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
      delay(10);
      Serial.println("Moving Backward");
      }
      

// Left
      else if (data == '4') {  
      motor1.run (BACKWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (BACKWARD);
      delay(10);
      Serial.println("Moving Left");
      }

// Right    
      else if (data == '6') {
      motor1.run (FORWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (FORWARD);
      delay(10);
      Serial.println("Moving Right");
      }

 // Forward Left 
      else if (data == '1') {
      motor1.run (RELEASE);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (RELEASE);
      delay(10);
      Serial.println("Moving Forward Left");
      }
      
// Forward Right    
      else if (data == '3') {
      motor1.run (FORWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (FORWARD);
      delay(10);
      Serial.println("Moving Forward Right");
      }

// Backward Left    
      else if (data == '7') {
      motor1.run (BACKWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (BACKWARD);
      delay(10);
      Serial.println("Moving Backward Left");
      }
      
      /*
      Double Digit number isnt working, Reason Unknown
// Backward Right (Used for Servo up) 
      else if (data == '9') {
      motor1.run (RELEASE);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (RELEASE);
      delay(10);
      Serial.println("Moving Backward Right");
      }
      

// Rotate Left    
      else if (data == '14') {
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
      delay(10);
      Serial.println("Moving Rotate Left");
      }
      
// Rotate Right    
      else if (data == '36') {
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
      delay(10);
      Serial.println("Moving Rotate Right ");
      }
      */

// Stop
      else if (data == '5') {
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (RELEASE);
      delay(10);
      Serial.println("Moving Stopped");
      }

     // Servo Code:
    //Servo up
    else if (data == '9') {
    motor5.write(0);
    delay(10);
    Serial.println("Servo is up");
    }
    //Servo down
    else if (data == '0'){
    motor5.write(90);
    delay(10);
    Serial.println("Servo is down");
    }
      
     // Ultra Sonic
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
    Serial.print("cm");
    Serial.print("|");
    
  
    // Soil Moisture
    int soilMoisture_5vVal = soilMoisture_5v.read();
    Serial.print(soilMoisture_5vVal); 
    Serial.print(F("\t"));
    Serial.print("|");
        
    // Reading humidity in %
    float dhtHumidity = dht.readHumidity();
    
    // Read temperature in Celsius, for Fahrenheit use .readTempF()
    float dhtTempC = dht.readTempC();
    Serial.print(dhtHumidity); 
    Serial.print(F(" [%]\t"));
    Serial.print("|");
    
    Serial.print(dhtTempC); 
    Serial.println(F(" [C]"));
    Serial.print("|");
    delay(50);

}

}
