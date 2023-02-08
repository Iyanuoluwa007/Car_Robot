
// Include Libraries
#include "Arduino.h"
#include "SoilMoisture.h"

// Pin Definitions
#define SOILMOISTURE_5V_PIN_SIG	A3


// object initialization
SoilMoisture soilMoisture_5v(SOILMOISTURE_5V_PIN_SIG);


// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    Serial.begin(9600);
    Serial.println("start");
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    int soilMoisture_5vVal = soilMoisture_5v.read();
    Serial.print(F("Val: ")); Serial.println(soilMoisture_5vVal);
}
