/*
  Nightlight
  Checks the light sensor for a threshold value and responds with an LED light
  depending on the value read. The value of light needed to shut off the LED
  can be adjusted coursly with THRESHOLD or more finely with the 
  potentionometer. The LED light may also be turned on using the attached 
  tactile button.

  Author: Matthew J. Kirkland
  Date:   04/26/2017
  Ver:    1.3
*/

#define THRESHOLD 400 //adjust to change when the LED turns on
                      //the higher numbers -> more light recieved
                      //the lower number -> less light recieved

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(4, OUTPUT); //LED (night light)
  pinMode(8, INPUT);  //button (manual on switch)
  pinMode(A1, INPUT);  //potentiometer (fine tunes THRESHOLD value)
  pinMode(A0, INPUT);  //light sensor
}

// the loop function runs over and over again forever
void loop(){

  delay(200); //delay when the light sensor is checked (saves power)
  
  //get value from light sensor
  int lightValue = analogRead(0);

  //calculate the new light value bound
  float lightBound = THRESHOLD * (1-analogRead(1)/THRESHOLD);  //create lightBound using THRESHOLD 
                                                               //macro and potentiometer reading

  //check if upper threshold is met or button is depressed. If either is true, the LED
  //is turned on
  if (lightValue < lightBound || digitalRead(8))
    digitalWrite(4,HIGH);  //turn LED on
  else
    digitalWrite(4, NULL);  //turn LED off
}
