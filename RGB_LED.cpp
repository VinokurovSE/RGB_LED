#include "RGB_LED.h"

RGB_LED::RGB_LED(byte rPin, byte gPin, byte bPin)
{
  redPin = rPin;
  greenPin = gPin;
  bluePin = bPin;
}

void RGB_LED::begin(bool common)
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  commonPin = common;

  if (commonPin == 0)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  if (commonPin == 1)
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }
}

void RGB_LED::setColor(byte RED, byte GREEN, byte BLUE)
{
  RED_goal = RED;
  GREEN_goal = GREEN;
  BLUE_goal = BLUE;
}

bool RGB_LED::RGBstep()
{
  endOfColorConversion = 1;

  if (RED_goal != RED_now)
  {
    RED_goal > RED_now ? RED_now++ : RED_now--;
    analogWrite(redPin, commonPin == 0 ? RED_now : map(RED_now, 0, 255, 255, 0));
    endOfColorConversion = 0;
  }

  if (GREEN_goal != GREEN_now)
  {
    GREEN_goal > GREEN_now ? GREEN_now++ : GREEN_now--;
    analogWrite(greenPin, commonPin == 0 ? GREEN_now : map(GREEN_now, 0, 255, 255, 0));
    endOfColorConversion = 0;
  }

  if (BLUE_goal != BLUE_now)
  {
    BLUE_goal > BLUE_now ? BLUE_now++ : BLUE_now--;
    analogWrite(bluePin, commonPin == 0 ? BLUE_now : map(BLUE_now, 0, 255, 255, 0));
    endOfColorConversion = 0;
  }

  return endOfColorConversion;
}

byte RGB_LED::readRED()
{
  return RED_now;
}

byte RGB_LED::readGREEN()
{
  return GREEN_now;
}

byte RGB_LED::readBLUE()
{
  return BLUE_now;
}

void RGB_LED::setRGB(byte RED, byte GREEN, byte BLUE)
{
  RED_goal = RED;
  RED_now = RED;
  GREEN_goal = GREEN;
  GREEN_now = GREEN;
  BLUE_goal = BLUE;
  BLUE_now = BLUE;
  analogWrite(redPin, commonPin == 0 ? RED : map(RED, 0, 255, 255, 0));
  analogWrite(greenPin, commonPin == 0 ? GREEN : map(GREEN, 0, 255, 255, 0));
  analogWrite(bluePin, commonPin == 0 ? BLUE : map(BLUE, 0, 255, 255, 0));
}
