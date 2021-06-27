#include "gateway.h"

void gateway()
{
    SystemStatus system_status;

    while(1)
    {
        Serial.println("Getting radio status...");
        system_status = getRadioStatus();
        Serial.print("Uptime: ");
        Serial.println(system_status.uptime);
        Serial.print("Battery voltage: ");
        Serial.println(system_status.batteryVoltage);
        Serial.print("Radio temperature: ");
        Serial.println(system_status.radio_temperature);
        Serial.print("Last RSSI: ");
        Serial.println(system_status.lastRssi);

        delay(5000);
    }
}