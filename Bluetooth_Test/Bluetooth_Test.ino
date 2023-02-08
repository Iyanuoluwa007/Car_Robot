#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

  // Bluetooth device name
  SerialBT.begin("ECOBot");
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
