# RGB_LED Arduino Library

![The essence of the RGB color scheme](http://ipic.su/img/img7/fs/RGB.1474563605.png)

## The advantage of using the library:
  - Separate management of multiple LEDs
  - Setting a common contact: anode or cathode
  - Smooth concurrent LED control
  - Setting colors without smooth
---
The first thing you want to include the library:
```sh
#include <RGB_LED.h>
```

Then we create objects for our LEDs. You can use another name.  
The argument specifies the PWM ports:
```sh
RGB_LED LED1(9, 10, 11);
RGB_LED LED2(3, 5, 6);
```
---
Next, we turn to the Setup function.  
Argument: common contact (ANODE or CATHODE).
```sh

  LED1.begin(CATHODE);
  LED2.begin(ANODE);
```
---
Next, I will discuss about the features that you can use as you need to.  
I just talk about what they do, and how they can be used.  
Color may be in the range from 0 to 255 (byte).  
Are listed, separated by commas, in turn: Red, Green, Blue.  
Тumbering system does not matter, you can use variables.  
I will use LED1 object.
---
Set color without a smooth change. 
```sh
LED1.setRGB(FF, CC, 00);
```
---
Set the color to which to aspire.  
This function will not change the color of the LED.  
This requires a function that will come after.
```sh
LED1.setColor(red, green, blue);
```
---
Take a step to the color that you want.  
Regardless, brighter or fainter new colors for the red, green, or blue, one step to the selected color will be made.  
Returns 1 if the desired color has been achieved, otherwise 0.
```sh
LED1.RGBstep();
```
---
If you want to know what color it is now made, you can use these functions:
```sh
LED1.readRED();
LED1.readGREEN();
LED1.readBLUE();
```
They will return the appropriate amount of color (byte).   

---

## Examples
The next example only smoothly will light random color.
```sh
#include <RGB_LED.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

RGB_LED LED1(redPin, greenPin, bluePin);

void setup()
{
  Serial.begin(9600);
  LED1.begin(CATHODE);
  LED1.setColor(random(0, 255), random(0, 255), random(0, 255));
  while (LED1.RGBstep() == 0)
  {
    Serial.print("R: ");
    Serial.print(LED1.readRED());
    Serial.print(", G: ");
    Serial.print(LED1.readGREEN());
    Serial.print(", B: ");
    Serial.println(LED1.readBLUE());
    delay(25);
  }
}

void loop()
{
}
```
The delay is necessary to ensure that things are not going too fast.
To understand that we have, I concluded that the information in the port monitor.

At the same time we can do this: take it
```sh
  LED1.begin(CATHODE);
  LED1.setColor(random(0, 255), random(0, 255), random(0, 255));
```
And do this:
```sh
  LED1.begin(CATHODE);
  LED1.setRGB(255, 255, 255);
  LED1.setColor(random(0, 255), random(0, 255), random(0, 255));
```
Now we see how instantly appeared white turns into another.

---
```sh
#include <RGB_LED.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

RGB_LED LED1(redPin, greenPin, bluePin);

long stepTimer = 0;

void setup()
{
  Serial.begin(9600);
  LED1.begin(CATHODE);
}

void loop()
{
  if (millis() > stepTimer)
  {
    stepTimer = millis() + 10;
    if (LED1.RGBstep() == 1) LED1.setColor(random(0, 255), random(0, 255), random(0, 255));
  }

  //    Your code
}
```
As you can see, you absolutely can easily insert your code without having to worry about what color will change yet Arduino does not react to pressing the button.
