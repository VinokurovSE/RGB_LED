#include <RGB_LED.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define waitTime 5

RGB_LED LED1(redPin, greenPin, bluePin);
long LEDupTime;

void setup()
{
  LED1.begin(CATHODE);
}

void loop()
{
  if (millis() > LEDupTime) LEDupdate();
}

void LEDupdate()
{
  LEDupTime = millis() + waitTime;
  if (LED1.RGBstep() == 1) LED1.setColor(random(0, 255), random(0, 255), random(0, 255));
}
