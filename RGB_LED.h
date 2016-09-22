/*
  RGB_LED library for easy management RGB LEDs..
  Created by Vinokurov_SE, September 23, 2016.
  Released into the public domain.
*/

#ifndef RGB_LED_h
#define RGB_LED_h
#include "Arduino.h"

#define ANODE 1
#define CATHODE 0

class RGB_LED
{
  public:
    RGB_LED(byte redPin, byte greenPin, byte bluePin);
    void begin(bool common);
    void setColor(byte RED, byte GREEN, byte BLUE);
    bool RGBstep();
    void setRGB(byte RED, byte GREEN, byte BLUE);
	byte readRED();
	byte readGREEN();
	byte readBLUE();
	
	

  private:
    byte redPin;
    byte greenPin;
    byte bluePin;
	
	bool commonPin;
	bool endOfColorConversion;

    byte RED_goal = 0;
    byte GREEN_goal = 0;
    byte BLUE_goal = 0;

    byte RED_now = 0;
    byte GREEN_now = 0;
    byte BLUE_now = 0;
};
#endif

