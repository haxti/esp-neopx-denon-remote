#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <Arduino.h>

class MainLogic {

    public:
    MainLogic();

    void NewVolumeCallback(uint8_t vol);
    void NewSourceCallback(char* source, unsigned int len);
    void NewMuteStatusCallback(bool mute);


};


#endif