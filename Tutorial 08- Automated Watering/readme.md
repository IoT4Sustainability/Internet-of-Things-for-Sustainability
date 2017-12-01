# Automated Watering
### Challenge Level: 1/5
![moisturecomplete](https://user-images.githubusercontent.com/27307550/32209821-86c913c4-bdc7-11e7-89e2-738802b986e4.jpg)

## Introduction

### In this tutorial you will...
  1. Be introduced to the concepts of **Polling** a pin
  2. Using an analog value to control code flow
  
## Explanation
The Automated Watering device monitors the moister content of the soil it is placed in.  If the moisture level goes to low it displays a message on the LCD that informs the user that any plant in the dry soil needs to be watered.
 
## Required Materials
 1. Intel Galileo board kit and PC with Arduino IDE installed (see Tutorial 1)
 2. Grove shield
 3. Grove Soil Moisture Sensor
 4. Grove LCD
 5. 2x Grove Cables
 
 
## Core Concepts
 
### Polling a Pin
**Polling** is when a microcontroller periodically checks the value of a sensor.  By default our code polls the sensor every 1 second using a **Software Delay**.

### Software Delay
A **Software Delay** is a line of code that tells the processor to wait for a defined amount of time before continuing program execution.
The code:
delay(1000);
Will pause the code for 1 second (1000 milliseconds)
 
 ### Analog Values
Analog values convey information by encoding it into a number scale.  For example, you could say that sunlight is very bright and returns an analog value of 1024; a room has medium lighting and returns a value of 512, and a cave is very dark and returns a value of 0.  The moister sensor returns analog values, so we can detect a spectrum of moister in the soil.
**NOTE**: In contrast to analog values, digital values can only be high or low (1 or 0).  In our example above a digital sensor could only tell us if there was light or not, but not how bright the light was.

## Building the Automated Watering Device

### How it works
The device will poll the moister sensor ever 1 second and store the latest value into the integer variable named "moistureLevel."  If the value is below the low moister threshold then the screen turns red, and it will display a message asking for water. Else, the screen will be green and the message displayed will tell the user that the moister level is OK.

During testing the moister sensor’s analog value was between 0-50 when the soil was dry and higher after the plant was watered.  This value may need to be adjusted depending on your particular sensor and the type of plant being watered.
 
### Assembling the Device
#### Step 1
Make sure the board is not connected to the power supply or USB, and that you are not electrically charged (to avoid zapping the board and causing damage).  Connect the Moister Sensor to the analog port A0.

#### Step 2
Connect the LCD to any of the 4 I2C ports.  (The I2C protocol uses a hardware address to communicate with the LCD, so it will be able to find it when it is connected to any of the 4 I2C ports.)

#### Step 3
Connect the microcontroller to its power supply and to a computer via the USB cable.  Program the microcontroller with the code provided with this project.

### Results
After waiting a few minutes, the board should now be running the Automated Watering program.  Gently plug the two pronged moister sensor into dry soil.  Make sure the metal strips are completely covered by soil, but the small electrical components are not close enough to the dirt to get wet. You should see a message telling you the soil is true dry followed by an analog number from the sensor.  Add water slowly to the far side of the pot away from the sensor, and be careful not to spill any liquid on your board.  The message should now change and the analog value will increase to around 500.

![moisturecomplete](https://user-images.githubusercontent.com/27307550/32209821-86c913c4-bdc7-11e7-89e2-738802b986e4.jpg)

### Exploratory Questions
 1. Lay your finger across the metal prongs on the moister sensor while the program is running.  What do you observe on the screen?  Why are you getting these results?
 2. Currently the board is wasting a lot of power checking the sensor and displaying a new value to the LCD every second.  Since the water could take days or weeks to evaporate or be absorbed by the plant, what could we change in the code to make our device more power friendly?

### In this tutorial we used the following.
 
  1. **Polled** sensors
  2. Analog values
  3. Timing delays
  
## BONUS CHALLENGE(S)

### Average Soil Moisture
Since there are different soil moistures at different locations in a large pot we need to read from different locations to make our device more accurate.  Modify the code to accept values from 3 separate moister sensors placed at different areas in a pot and average their values.

### Too Much Water
It is possible to over water some varieties of plants.  Modify the code to turn the screen red and warn the user when they have added too much water to the pot. (When the sensor reading is over 500.)
**HINT**: Separate the 'if/else' portion of the code into 3 separate 'if' statements to add a 3rd condition to display.
if(x >= y){...code...};
if(x <= y && x >= z){...code...}; //The && operator will evaluate true if both conditions on either side are met.
if(x <= z){...code...};
