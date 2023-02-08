// SERVO
/*
 Its has the 3 terminals:
+ve(Red), - ve(Brown), (Orange) is the pulse
Operating voltage is 5v
 */
 
#include <Servo.h>
int pin = 10;

Servo motor1;

void setup() {
  // put your setup code here, to run once:
motor1.attach(pin);

}

void loop() {
  // put your main code here, to run repeatedly:
 // Servo Code
    motor1.write(0);
    delay(2000);
  //  motor1.write(90);
    // delay(2000);
    }
