#include <RGB_LED.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define waitTime 1000

RGB_LED LED1(redPin, greenPin, bluePin);
long LEDupTime;
byte i = 0;

void setup()
{
  LED1.begin(CATHODE);
  LED1.setRGB(0, 0, 0);
}

void loop()
{
  if (millis() > LEDupTime) LEDupdate();
}

void LEDupdate()
{
  LEDupTime = millis() + waitTime;
  i++;
  if (i == 8) i = 1;
  nextColor();
}

void nextColor()
{
  if (i == 1) LED1.setRGB(0, 0, 255);
  if (i == 2) LED1.setRGB(0, 255, 255);
  if (i == 3) LED1.setRGB(0, 255, 0);
  if (i == 4) LED1.setRGB(255, 0, 0);
  if (i == 5) LED1.setRGB(255, 0, 255);
  if (i == 6) LED1.setRGB(255, 255, 0);
  if (i == 7) LED1.setRGB(255, 255, 255);
}

