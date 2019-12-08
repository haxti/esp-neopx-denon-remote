#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "MainLogic.h"
#include "MqttMessageInterpreter.h"
#include "Globals.h"

MainLogic logic;
MqttMessageInterpreter msgInt;
WiFiClient esp;
PubSubClient mqttClient(esp);

void connectWifi()
{
  WiFi.begin();

  Serial.print("Connecting to WiFi ");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print(".");
  }
  Serial.println();

  Serial.println(WiFi.localIP());
}

void connectMqtt()
{
  while(!mqttClient.connected())
  {
    Serial.print("Connecting to MQTT Broker ");
    if(mqttClient.connect("ESP-NEOPIXEL-REMOTE"))
    {
      Serial.println("connected!");
      mqttClient.subscribe(GLOBALS_TOPIC_GET_POWER);
      mqttClient.subscribe(GLOBALS_TOPIC_GET_VOL);
      mqttClient.subscribe(GLOBALS_TOPIC_GET_MAX_VOL);
      mqttClient.subscribe(GLOBALS_TOPIC_GET_MUTE);
      mqttClient.subscribe(GLOBALS_TOPIC_GET_SOURCE);
    }
    else
    {
      Serial.print("failed: ");
      Serial.println(mqttClient.state());
      delay(1000);
    }
    
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
  connectWifi();

  mqttClient.setServer(MQTT_BROKER, MQTT_BROKER_PORT);
  mqttClient.setCallback([] (char* topic, byte* payload, unsigned int length) {
      msgInt.MqttClientCallback(topic, payload, length); 
     });
  Serial.println("Mqtt init done");

  msgInt.SetNewMuteCallback([](bool mute) {
      logic.NewMuteStatusCallback(mute);
  });

  msgInt.SetNewVolumeCallback([](float vol) {
      logic.NewVolumeCallback(vol);
  });

  msgInt.SetNewSourceCallback([](String src) {
      logic.NewSourceCallback(src);
  });

  Serial.println("Logic init done");
}

void loop()
{
  if(!mqttClient.connected())
    connectMqtt();

  mqttClient.loop();
}