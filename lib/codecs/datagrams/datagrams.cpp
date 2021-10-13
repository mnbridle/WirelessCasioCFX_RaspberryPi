#include <ctime>
#include <iostream>
#include <sstream>

#include "datagrams.hpp"
#include "helpers.hpp"

using namespace std;
using namespace Helpers;

void TextMessage::decode(uint8_t* buf)
{
    /* Structure of packet

    sender:           string, 8 characters
    recipient:        string, 8 characters
    Date:             string, 8 characters
    Time:             string, 6 characters
    message_name:     string, 12 characters
    message_contents: string, 112 characters
    
    */

   m_sender = bufferToString(buf, 8);
   m_recipient = bufferToString(buf, 8);
   string date = bufferToString(buf, 8);
   string time = bufferToString(buf, 6);
   m_message_name = bufferToString(buf, 12);
   m_message_contents = bufferToString(buf, 112);

   m_msg_time = datetimeToTimeT(date, time);

}

void TextMessage::encode(uint8_t* buf, string sender, string recipient, string message_name, string message_contents, time_t msg_time)
{
    sender.resize(8);
    recipient.resize(8);
    message_name.resize(12);
    message_contents.resize(112);

    stringToBuffer(buf, sender);
    stringToBuffer(buf, recipient);

    // Get date and time from tm - format is DDmmYYYY and HHMM
    stringToBuffer(buf, timetToDateString(msg_time));
    stringToBuffer(buf, timetToTimeString(msg_time));

    stringToBuffer(buf, message_name);
    stringToBuffer(buf, message_contents);

    m_sender = sender;
    m_recipient = recipient;
    m_msg_time = msg_time;
    m_message_name = message_name;
    m_message_contents = message_contents;
}

string TextMessage::getMessageName()
{
    return m_message_name;
}


string TextMessage::getMessageContents()
{
    return m_message_contents;
}


string TextMessage::getRecipient()
{
    return m_recipient;
}


string TextMessage::getSender()
{
    return m_sender;
}


time_t TextMessage::getMsgTime()
{
    return m_msg_time;
}