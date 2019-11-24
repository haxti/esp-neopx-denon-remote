#include "Globals.h"

const char* GLOBALS_SSID = "";
const char* GLOBALS_PSK = "";

const char* MQTT_BROKER = "svpiobroker";
const int MQTT_BROKER_PORT = 1883;

const char* GLOBALS_TOPIC_GET_POWER = "denon/0/zoneMain/powerZone";
const char* GLOBALS_TOPIC_SET_POWER = "denon/0/zoneMain/powerZone/set";

const char* GLOBALS_TOPIC_GET_VOL = "denon/0/zoneMain/volume";
const char* GLOBALS_TOPIC_GET_MAX_VOL = "denon/0/zoneMain/maximumVolume";
const char* GLOBALS_TOPIC_GET_MUTE = "denon/0/zoneMain/muteIndicator";
const char* GLOBALS_TOPIC_SET_MUTE = "denon/0/zoneMain/muteIndicator/set";
const char* GLOBALS_TOPIC_SET_VOL_UP = "denon/0/zoneMain/volumeUp/set";
const char* GLOBALS_TOPIC_SET_VOL_DOWN = "denon/0/zoneMain/volumeDown/set";

const char* GLOBALS_TOPIC_GET_SOURCE = "denon/0/zoneMain/selectInput";
const char* GLOBALS_TOPIC_SET_SOURCE = "denon/0/zoneMain/selectInput/set";

const char* GLOBALS_INPUT_COLORS[] = {"#F00000", "#00F000"};
const char* GLOBALS_INPUTS[] = {"GAME", "SPOTIFY" };
/*const char* GLOBALS_INPUTS[] = {"PHONO", "CD", "TUNER", "DVD", "BD", "TV", "SAT/CBL",
                                "MPLAY", "GAME", "NET", "SPOTIFY", "LASTFM", "IRADIO",
                                "SERVER", "FAVORITES", "AUX1", "AUX2", "BT"};*/
