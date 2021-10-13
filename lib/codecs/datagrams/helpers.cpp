#include <Arduino.h>
#include <string>
#include <sstream>

#include "helpers.hpp"

using namespace std;

void Helpers::stringToBuffer(uint8_t *ptr, string input_string)
{
    for (int i=0; i < input_string.length(); i++)
    {
        *ptr = (uint8_t)input_string.at(i);
        ptr++;
    }
}

string Helpers::bufferToString(uint8_t *ptr, uint8_t length)
{
    string result;

    result.resize(length);

    for (int i=0; i < length; i++)
    {
        result.at(i) = *ptr;
        ptr++;
    }

    return result;
}

time_t Helpers::datetimeToTimeT(string date, string time)
{
    time_t msg_time;
    struct tm * ptm;

    ptm->tm_mday = stoi(string(date.begin() + 0, date.begin() + 2));
    ptm->tm_mon  = stoi(string(date.begin() + 2, date.begin() + 4)) + 1;
    ptm->tm_year = stoi(string(date.begin() + 4, date.begin() + 8));

    ptm->tm_hour = stoi(string(time.begin() + 0, time.begin() + 2));
    ptm->tm_min  = stoi(string(time.begin() + 2, time.begin() + 4));
    ptm->tm_sec  = stoi(string(time.begin() + 4, time.begin() + 6));

    msg_time = mktime(ptm);

    return msg_time;
}

string Helpers::timetToTimeString(time_t timestamp)
{
    // Get date and time from tm - format is DDmmYYYY and HHMM
    struct tm * ptm;
    ptm = gmtime(&timestamp);
    
    stringstream time_ss;
    time_ss << ptm->tm_hour << ptm->tm_min << ptm->tm_sec << endl;

    return time_ss.str();
}


string Helpers::timetToDateString(time_t timestamp)
{
    // Get date and time from tm - format is DDmmYYYY and HHMM
    struct tm * ptm;
    ptm = gmtime(&timestamp);
    
    stringstream date_ss;
    date_ss << ptm->tm_mday << (ptm->tm_mon)+1 << ptm->tm_year << endl;

    return date_ss.str();
}