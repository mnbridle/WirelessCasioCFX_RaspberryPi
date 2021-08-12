// RF includes
#include <RadioHead.h>
#include <RHReliableDatagram.h>
#include <RH_RF24.h>

// USB Raspberry Pi interface includes
//#include "usb_interface/usb_interface.hpp"

// Define IO pins
#define DRF4463_SDN 1
#define DRF4463_nIRQ 0
#define DRF4463_SDO 2
#define DRF4463_SCLK 3
#define DRF4463_SDI 4
#define DRF4463_nSEL 13

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

struct SystemStatus
{
    float batteryVoltage;
    int32_t uptime;
    float radio_temperature;
    float lastRssi;
};

void gateway();