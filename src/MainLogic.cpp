 
 #include "MainLogic.h"
 
 MainLogic::MainLogic()
 {
    
 }


void MainLogic::NewVolumeCallback(float vol)
{
    Serial.print("v: ");
    Serial.println(vol);

}

void MainLogic::NewSourceCallback(String source)
{
    Serial.print("s: ");
    Serial.println(source);
}


void MainLogic::NewMuteStatusCallback(bool mute)
{
    Serial.print("m: ");
    Serial.println(mute);
}