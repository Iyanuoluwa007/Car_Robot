int data = 0;

#define ledPin1 5
#define ledPin2 6
#define ledPin3 7

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  
  Serial.begin(9600); //default baud rate for bt 38400
  Serial.println("Ready...");
}

void loop() {
  if (Serial.available() > 0) { // Checks whether data is comming from the serial port
    data = Serial.read(); // Reads the data from the serial port

    if (data == '0') {
      digitalWrite(ledPin1, LOW); // Turn LED OFF
      Serial.println("LED1: OFF");
      }
    else if (data == '1') {
      digitalWrite(ledPin1, HIGH);
      Serial.println("LED1: ON");
      }
    else if (data == '2') {
      digitalWrite(ledPin2, LOW);
      Serial.println("LED2: OFF");
      }
    else if (data == '3') {
      digitalWrite(ledPin2, HIGH);
      Serial.println("LED2: ON");
    }
      else if (data == '4') {
        digitalWrite(ledPin3, LOW);
        Serial.println("LED3: OFF");
      }
      else if (data == '5') {
        digitalWrite(ledPin3, HIGH);
        Serial.println("LED3: ON");
      }
  }
}
