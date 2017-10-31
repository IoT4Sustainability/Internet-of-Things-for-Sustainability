#include"rgb_lcd.h"

rgb_lcd myScreen;
int THRESHOLD = 400;
double value = 0;

int red = 180;
int green = 180;
int blue = 180;

void setup() {
  // Set the LCD screen up. Contains errors, fix them!
  /* Errors between these lines */
  myScreen.begin(20, 5);
  myScreen.setRGB(red, red, red);
  /* -------------------------- */

  myScreen.print("Meter Value");
  
  // Set pins up for the potentiometer and button respectively
  pinMode(A0, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  // Read in from analog the value of the potentiometer
  value = analogRead(A0);

  // If the button is pressed, run the algorithm from the 
  // nightlight program on the previously read in value to
  // see what the nightlight was reading in.
  if(digitalRead(4) == 1) {
    value = THRESHOLD * ( 1 - ( value/THRESHOLD ));
  }

  // Set cursor and print value, then wait .2 seconds
  myScreen.setCursor(0,1);
  myScreen.print(value);
  
  delay(200);
}
