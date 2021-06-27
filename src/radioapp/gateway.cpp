#include "gateway.h"

RH_RF24 drf4463(DRF4463_nSEL, DRF4463_nIRQ, DRF4463_SDN);
RHReliableDatagram manager(drf4463, SERVER_ADDRESS);

void gateway()
{
    // timers
    unsigned long status_report_timer;

    // intervals
    unsigned long status_report_interval = 15000;

    uint8_t data[] = "And hello back to you";
    // Dont put this on the stack:
    uint8_t buf[RH_RF24_MAX_MESSAGE_LEN];

    if (!manager.init())
    {
        Serial.println("init failed");
    }

    drf4463.setFrequency(433.920);
    drf4463.setTxPower(0x05);

    status_report_timer = millis();

    while(1)
    {
        if ( status_report_timer + status_report_interval < millis() )
        {
            Serial.print("Uptime: ");
            Serial.println(millis());
            status_report_timer = millis();
        }
        
        if(manager.available())
        {
            // Wait for a message addressed to us from the client
            uint8_t len = sizeof(buf);
            uint8_t from;
            if (manager.recvfromAck(buf, &len, &from))
            {
            Serial.print("got request from : 0x");
            Serial.print(from, HEX);
            Serial.print(" length: ");
            Serial.print(len);
            Serial.print(": ");
            Serial.println((char*)buf);
        
            // Send a reply back to the originator client
            if (!manager.sendtoWait(data, sizeof(data), from))
                Serial.println("sendtoWait failed");
            }
        }
    }
}