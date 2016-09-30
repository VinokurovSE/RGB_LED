#include <RGB_LED.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define waitTime 200

LiquidCrystal_I2C LCD(0x3F, 20, 2);

RGB_LED LED1(redPin, greenPin, bluePin);
long LEDupTime;

void setup()
{
  LCD.begin();
  LCD.clear();
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
  LCD.home();
  LCD.print("R_");
  LCD.print(LED1.readRED());
  LCD.print(" G_");
  LCD.print(LED1.readGREEN());
  LCD.print(" B_");
  LCD.print(LED1.readBLUE());
  LCD.print(" ");
}
