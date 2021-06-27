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
  Serial.println("Setting up radio");

  // Set up radio
  if(setupRadio()) {
    setLEDState(YELLOW);
    setModeRx();
  } else {
    setLEDState(RED);
    Serial.println("Error initialising DRF4463 radio. Rebooting...");
  }
  Serial.println("Setup complete!");
  setLEDState(GREEN);
}

void loop() {  
  clearLED();
  setLEDState(GREEN);

  gateway();
}

