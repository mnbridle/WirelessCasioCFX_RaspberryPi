#include <Arduino.h>

typedef uint8_t DeviceHardwareAddress[16];
typedef uint8_t NetworkName[16];
typedef uint8_t NetworkLocation[16];
typedef uint8_t BeaconInterval;
typedef float Frequency;
typedef unsigned long Uptime;

enum class TXPower : uint8_t
{
    OFF = 0x00,               // not measurable
    VERY_LOW_POWER = 0x01,    // -20.4dBm
    LOW_POWER = 0x0F,         // 2.4dBm
    HIGH_POWER = 0x1F,        // 9.4dBm
    MAX_POWER = 0x4F          // 11.6dBm
};

enum class ModulationMethod : uint8_t
{

};