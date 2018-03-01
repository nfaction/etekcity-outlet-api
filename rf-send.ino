/*
  Simple RF receiver based on

  https://github.com/sui77/rc-switch/
*/

#include "RCSwitch.h"

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableTransmit(13);  // Receiver on interrupt GPio 13 => that is pin D7 
  Serial.println("ESP8266 RF transmitter starting now...");
}

void loop() {

  mySwitch.setPulseLength(183);
  mySwitch.send(1332531, 24);
  delay(5000);

  mySwitch.setPulseLength(183);
  mySwitch.send(1332540, 24);
  delay(5000);

}
