#ifndef MQTT_MESSAGE_INTERPRETER_H
#define MQTT_MESSAGE_INTERPRETER_H

#include <Arduino.h>
#include <functional>



#define MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK std::function<void(uint8_t)> volCallback
#define MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK std::function<void(char*, unsigned int)> srcCallback
#define MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK std::function<void(bool)> muteCallback

class MqttMessageInterpreter
{

public:
    MqttMessageInterpreter();
    MqttMessageInterpreter& SetNewVolumeCallback(MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK);
    MqttMessageInterpreter& SetNewSourceCallback(MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK);
    MqttMessageInterpreter& SetNewMuteCallback(MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK);

    void MqttClientCallback(char* topic, byte* payload, unsigned int length);

private:
    char* m_Topic = nullptr;
    byte* m_Payload = nullptr;
    unsigned int m_PayloadLen = 0;
    MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK;
    MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK;
    MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK;

    void interpretTopic();


};

#endif