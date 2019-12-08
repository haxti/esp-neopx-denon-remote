#ifndef MQTT_MESSAGE_INTERPRETER_H
#define MQTT_MESSAGE_INTERPRETER_H

#include <Arduino.h>
#include <functional>



#define MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK std::function<void(float)> volCallback
#define MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK std::function<void(String)> srcCallback
#define MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK std::function<void(bool)> muteCallback

class MqttMessageInterpreter
{

public:
    MqttMessageInterpreter();
    void SetNewVolumeCallback(MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK);
    void SetNewSourceCallback(MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK);
    void SetNewMuteCallback(MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK);

    void MqttClientCallback(char* topic, byte* payload, unsigned int length);

private:
    char* m_Topic = nullptr;
    String m_PayloadStr;
    MQTT_MESSAGE_INTERPRETER_VOLUME_CALLBACK;
    MQTT_MESSAGE_INTERPRETER_SOURCE_CALLBACK;
    MQTT_MESSAGE_INTERPRETER_MUTE_CALLBACK;

    void interpretTopic();


};

#endif