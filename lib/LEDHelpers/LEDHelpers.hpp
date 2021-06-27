#pragma once

// Imports for onboard LED
#include <Adafruit_DotStar.h>

// DotStar defines
#define NUMPIXELS 1
#define DATAPIN 7
#define CLOCKPIN 8

// Define some colours
#define RED   0x010000
#define GREEN 0x000100
#define YELLOW 0x010100
#define BLUE  0x000001

void setLEDState(unsigned long);
void clearLED();
void ledInit();
