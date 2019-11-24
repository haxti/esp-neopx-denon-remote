 
 #include "MainLogic.h"
 
 MainLogic::MainLogic()
 {
    
 }


void MainLogic::NewVolumeCallback(uint8_t vol)
{
    Serial.println(vol);

}

void MainLogic::NewSourceCallback(char* source, unsigned int len)
{
    Serial.println(source);
}


void MainLogic::NewMuteStatusCallback(bool mute)
{
    Serial.println(mute);
}