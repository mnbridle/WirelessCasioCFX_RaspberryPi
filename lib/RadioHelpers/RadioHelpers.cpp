#include "RadioHelpers.hpp"

RH_RF24 drf4463(DRF4463_nSEL, DRF4463_nIRQ, DRF4463_SDN);


bool setupRadio() 
{
    return drf4463.init();
}

void setModeRx() 
{
    drf4463.setModeRx();
}

void setModeTx()
{
  drf4463.setModeTx();
}

void setModeIdle()
{
  drf4463.setModeIdle();
}

bool setFrequency(float frequency)
{
  return drf4463.setFrequency(frequency);
}

SystemStatus getRadioStatus() {
  SystemStatus status = SystemStatus();

  status.batteryVoltage = drf4463.get_battery_voltage();
  status.radio_temperature = drf4463.get_temperature();
  status.uptime = millis();
  status.lastRssi = drf4463.lastRssi();

  return status;
}