#pragma once

#include <Arduino.h>
#include <string>
#include <ctime>

enum class DatagramType : uint8_t
{
    UNKNOWN = 0x00,
    TEXT_MESSAGE_TX = 0x01,
    TEXT_MESSAGE_RX = 0x02,
    LIST_AVAILABLE_MESSAGES = 0x03,
    MESSAGE_LIST = 0x04,
    MARK_MESSAGE_READ = 0x05,
    IS_MESSAGE_READ = 0x06,
    SET_IDENTITY = 0xF0,
    GET_IDENTITY = 0xF1,
    SET_DATETIME = 0xF2,
    GET_DATETIME = 0xF3,
};

using namespace std;

namespace data
{

class TextMessage
{
    public:
        void encode(uint8_t* buf, string sender, string recipient, string message_name, string message_contents, time_t msg_time);
        void decode(uint8_t* buf);

        std::string getMessageName();
        std::string getMessageContents();
        std::string getRecipient();
        std::string getSender();
        time_t getMsgTime();

    private:
        std::string m_message_name;
        std::string m_message_contents;
        std::string m_recipient;
        std::string m_sender;
        time_t m_msg_time;

};

}