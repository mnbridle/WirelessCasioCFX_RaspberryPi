// Imports for radio
#include "main.h"
#include "radioapp/gateway.h"

void setup() {
  // Set up DotStar LED
  ledInit();
  clearLED();
  setLEDState(RED);
  
  // Set up serial port
  Serial.begin(115200);
}

void loop() {  
  clearLED();
  setLEDState(GREEN);

  gateway();
}

