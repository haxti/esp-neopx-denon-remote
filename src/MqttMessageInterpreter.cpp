
#include "MqttMessageInterpreter.h"
#include "Globals.h"


MqttMessageInterpreter::MqttMessageInterpreter()
{

}

void MqttMessageInterpreter::MqttClientCallback(char* topic, byte* payload, unsigned int length)
 {
    digitalWrite(LED_BUILTIN, LOW);
    m_Topic = topic;
    m_Payload = payload;
    m_PayloadLen = length;
    interpretTopic();
    digitalWrite(LED_BUILTIN, HIGH);
 }



 void MqttMessageInterpreter::interpretTopic()
 {
     if(m_Topic == nullptr)
        return;

    if(strcmp(m_Topic, GLOBALS_TOPIC_GET_VOL) == 0)
    {
        if(volCallback)
            volCallback(static_cast<uint8_t>(*m_Payload));
    }
    else if(strcmp(m_Topic, GLOBALS_TOPIC_GET_SOURCE) == 0)
    {
        if(srcCallback)
            srcCallback((char*)m_Payload, m_PayloadLen);
    }
    else if(strcmp(m_Topic, GLOBALS_TOPIC_GET_MUTE) == 0)
    {
        if(muteCallback)
            muteCallback(static_cast<bool>(strcmp("true", (char*)m_Payload) == 0));
    }
    else
    {
        Serial.print("Unknown Topic: ");
        Serial.println(m_Topic);
    }  
 }

MqttMessageInterpreter& SetNewVolumeCallback(MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK)
{
    return;
}


MqttMessageInterpreter& SetNewSourceCallback(MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK)
{
    return;
}


MqttMessageInterpreter& SetNewMuteCallback(MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK)
{
    return;
}