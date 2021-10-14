#include <Arduino.h>
#include <string>
#include <ctime>

using namespace std;

namespace Helpers
{
    void stringToBuffer(uint8_t *ptr, string string_input);
    string bufferToString(uint8_t *ptr, uint8_t length);
    time_t datetimeToTimeT(string date, string time);

    string timetToDateString(time_t timestamp);
    string timetToTimeString(time_t timestamp);
};