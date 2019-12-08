
#include "MqttMessageInterpreter.h"
#include "Globals.h"


MqttMessageInterpreter::MqttMessageInterpreter()
{

}

void MqttMessageInterpreter::MqttClientCallback(char* topic, byte* payload, unsigned int length)
 {
    payload[length] = NULL;
    digitalWrite(LED_BUILTIN, LOW);
    m_Topic = topic;
    m_PayloadStr = (char*)payload;
    interpretTopic();
    digitalWrite(LED_BUILTIN, HIGH);
 }



 void MqttMessageInterpreter::interpretTopic()
 {
     Serial.println("String: "+ m_PayloadStr);
     if(m_Topic == nullptr)
        return;

    if(strcmp(m_Topic, GLOBALS_TOPIC_GET_VOL) == 0)
    {
        if(volCallback)
            volCallback(m_PayloadStr.toFloat());
    }
    else if(strcmp(m_Topic, GLOBALS_TOPIC_GET_SOURCE) == 0)
    {
        if(srcCallback)
            srcCallback(m_PayloadStr);
    }
    else if(strcmp(m_Topic, GLOBALS_TOPIC_GET_MUTE) == 0)
    {
        if(muteCallback)
            muteCallback(static_cast<bool>(m_PayloadStr.equals("true")));
    }
    else
    {
        Serial.print("Unknown Topic: ");
        Serial.println(m_Topic);
    }  
 }

void MqttMessageInterpreter::SetNewVolumeCallback(MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK)
{
    this->volCallback = volCallback;
}


void MqttMessageInterpreter::SetNewSourceCallback(MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK)
{
    this->srcCallback = srcCallback;
}


void MqttMessageInterpreter::SetNewMuteCallback(MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK)
{
    this->muteCallback = muteCallback;
}