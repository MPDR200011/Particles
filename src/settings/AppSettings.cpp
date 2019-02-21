#include "AppSettings.h"

using namespace sf;

//Frame rate control
int ticksPerSecond = 60;
float secondsPerSecond = 60.0F;

float framePeriod = 1.0F / ticksPerSecond;

float timeStep = secondsPerSecond * framePeriod;
float timePerFrame = timeStep;

//Units and constants
const float pixelsPerMeter = 1/49140.0F;

//Useful App data
Vector2f windowCenter = Vector2f(0,0);
void updateWindowCenter(RenderWindow &window){
    windowCenter = Vector2f(window.getView().getSize().x/2.0F, window.getView().getSize().y/2.0F);
}