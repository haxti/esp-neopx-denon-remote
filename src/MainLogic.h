#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <Arduino.h>

class MainLogic {

    public:
    MainLogic();

    void NewVolumeCallback(float vol);
    void NewSourceCallback(String source);
    void NewMuteStatusCallback(bool mute);


};


#endif