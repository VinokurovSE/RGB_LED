#include <RGB_LED.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define waitTime 200

RGB_LED LED1(redPin, greenPin, bluePin);
long LEDupTime;

void setup()
{
  Serial.begin(115200);
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
  Serial.println("___________________");
  Serial.print("R: ");
  Serial.println(LED1.readRED());
  Serial.print("G: ");
  Serial.println(LED1.readGREEN());
  Serial.print("B: ");
  Serial.println(LED1.readBLUE());
  Serial.println();
}
