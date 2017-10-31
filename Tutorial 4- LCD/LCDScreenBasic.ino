#include"rgb_lcd.h"

// Gives a name to our RGB LCD screen and initializes it
rgb_lcd myScreen;
int i = 0;

// Following values must be within 0 and 255 and
// indicate how strong that color is in the LCD.
// Change one or more of the color numbers to change the screen color
/*  Can Modify This Code */
int red = 255;
int green = 255;
int blue = 255;
/*-----------------------*/

void setup() {
  // .begin initializes the size of the screen, do not change this.
  // The size of our LCD screen is sixteen columns and two rows of characters.
  myScreen.begin(16,2);

  // Sets the color of the screen to the previously declared values
  myScreen.setRGB(red, green, blue);

  // Prints out a 16 or less character sentence on the first line.
  // Characters past 16 will just not appear.
  myScreen.print("Timer:");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Sets the cursor to the first spot on the second row
  myScreen.setCursor(0,1);
  i++;
  // Prints the integer value of i to the screen every 1000 ms, or 1 second
  myScreen.print(i);
  delay(1000);
}
