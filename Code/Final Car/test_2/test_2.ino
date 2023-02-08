
#include <AFMotor.h>   //AFMotor.h Library

AF_DCMotor motor1(1); //Front Left Wheel
AF_DCMotor motor2(2); //Back Left Wheel
AF_DCMotor motor3(3); //Front Right Wheel
AF_DCMotor motor4(4); //Back Right Wheel

String readString;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(255);   //Set Motor Speed
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
// Forward
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
      delay(2000); // 5sec delay

// Backward
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
      delay(2000);


// Left
      motor1.run (BACKWARD);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (BACKWARD);
      delay(2000);

// Right    
      motor1.run (FORWARD);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (FORWARD);
      delay(2000);


 // Forward Left
      motor1.run (RELEASE);
      motor2.run (FORWARD);
      motor3.run (FORWARD);
      motor4.run (RELEASE);
      delay(2000);

// Forward Right    
      motor1.run (FORWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (FORWARD);
      delay(2000);

// Backward Left    
      motor1.run (BACKWARD);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (BACKWARD);
      delay(2000);

// Backward Right
      motor1.run (RELEASE);
      motor2.run (BACKWARD);
      motor3.run (BACKWARD);
      motor4.run (RELEASE);
      delay(2000);

// Rotate Left    
      motor1.run (BACKWARD);
      motor2.run (BACKWARD);
      motor3.run (FORWARD);
      motor4.run (FORWARD);
      delay(2000);

// Rotate Right    
      motor1.run (FORWARD);
      motor2.run (FORWARD);
      motor3.run (BACKWARD);
      motor4.run (BACKWARD);
      delay(2000);


// Stop
      motor1.run (RELEASE);
      motor2.run (RELEASE);
      motor3.run (RELEASE);
      motor4.run (RELEASE);
      delay(2000); 

      
}
