#pragma once

#include <Arduino.h>

enum class Layer2 : uint8_t
{
    CONFIG_WRITE = 0x00,
    CONFIG_READ = 0x01,
    DATA_WRITE = 0x02,
    DATA_READ = 0x03,
    STATUS_RESPONSE_OK = 0xF0,
    STATUS_RESPONSE_ERROR = 0xF1
};

enum class ConfigurationItems : uint8_t
{
    DEVICE_ADDRESS = 0x00,
    NETWORK_NAME = 0x01,
    NETWORK_LOCATION = 0x02,
    BEACON_FREQUENCY = 0x03,
    
    FREQUENCY_TX = 0x10,
    FREQUENCY_RX = 0x11,
    TX_POWER = 0x12,
    MODULATION_METHOD = 0x13,
    BIT_RATE = 0x14,

    UPTIME = 0xF0,
    STATUS_LED = 0xF1
};

enum class DataSendMode : bool
{
    SEND_IMMEDIATE = false,
    SEND_AT_TIME = true
};
