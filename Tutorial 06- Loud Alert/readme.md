# Ambient Noise Monitor
### Challenge Level: 3/5
![working](https://user-images.githubusercontent.com/27307550/30575225-2dccce48-9cb4-11e7-921e-7d7463074c6d.jpg)

## Introduction

### In this tutorial you will...
  1. Be introduced to the concepts of **Polling** pins
  2. Learn to use **Running Averages** to find an average senor level over time
  3. Make an adaptable sound monitor that can be tuned to work in different environments
  
## Explanation
The Ambient Noise Monitoring device will listen to the noise level in the room, and give a visual warning when the noise exceeds a threshold set by the user.  Similar devices are used in libraries, classrooms, and cathedrals to help ensure that noise stays at a courteous level.
 
## Required Materials
 1. Intel Galileo board kit and PC with Arduino IDE installed (see Tutorial 1)
 2. Grove shield
 3. Grove potentiometer
 4. Grove Sound Sensor
 5. Grove LCD
 6. 3x Grove Cables
 ![parts](https://user-images.githubusercontent.com/27307550/30575227-2dcdb38a-9cb4-11e7-95b8-bfc429507e36.jpg)
 
 
## Core Concepts
 
### Running Average
A **Running Average** is the average of a data set over the most recent period of time.  For example, if you were to take a measurement of the temperature outside once an hour for 10 hours you would be taking an average of those ten data points.  To keep a **Running Average** of the most recent ten hours would mean that when you measured your eleventh hour you would discard the oldest data point you collected and re-compute the average.

### Array
**Arrays** are a set of variables that we can use to make it easier to work with large collections of data.  In the code for this project we will be tracking 40 data points to calculate our **Running Average**.  Instead of making  40 integer variables with unique names we can simply make an **Array** of integer values and access each through its corresponding index.
**NOTE**: **Array** indexes start at 0.  An **Array** of 40 elements would be accessed with **Array**[0], **Array**[1], … ,**Array**[39].

### Software Delay
A **Software Delay** is a line of code that tells the processor to wait for a defined about of time before continuing program execution.
 

## Building the Ambient Noise Monitor

### How it works
The device will keep a **Running Average** of the ambient sound in the environment and display a message on the LCD screen stating whether the noise level in the environment is acceptable or too loud.  A **Running Average** is the average of a data set over the most recent period of time.  Our device will average the sound collected over the previous 10 seconds, and discard the oldest data point as a new ones are collected from the sensor.  This average noise level over the previous ten seconds is what the device will compare with the limit we set to determine if the noise level is acceptable.  This stops a sneeze or cough from causing the LCD to flicker red.

This **Running Average** is implemented in the code with a 40 element **Array**, an Infinite Loop, and a **Software Delay** of 250ms (or 1/4th second).  

Every time the code loops it reads the sound level from the sound sensor, removes the oldest sound data value in the **Array**, adds the new sound data value to the **Array**, calculates the new average sound value of the **Array**, updates the LCD accordingly, and waits for 250ms in a **Software Delay** before repeating the process again in an Infinite Loop.  Since we are adding in a new sound value every 1/4th second, and we are holding onto the most recent 40 sound values, we can calculate that we are keeping a **Running Average** of the sound captured during the previous ten seconds.  Reading the value from a sensor in a cyclic way like this is referred to as **Polling** the sensor.

To ensure the device can be used in a wide variety of environments we want to make sure that the acceptable sound limit can be set by the user.  This means we need to provide the user with a way to interact with the threshold variable that we hard coded in previous projects.  We will accomplish this with the Rotary Angle Sensor.  By using the sensor as a dial, the user can set the threshold value.  If the code detects that the threshold value has been changed since the last time it executed the loop it will show the currently value of the **Running Average**, and the new value being entered by the user using the Rotary Sensor.  After 20 loop cycles (5 seconds) the display will revert to its normal state.
 
### Assembling the Device
#### Step 1
Make sure the board is not connected to the power supply or USB, and that you are not electrically charged (to avoid zapping the board and causing damage).  Connect the Rotary Angle Sensor to the analog port A0.
![pento](https://user-images.githubusercontent.com/27307550/30575224-2dccdfaa-9cb4-11e7-8687-17e69c4bc1eb.jpg)

#### Step 2
Connect the Sound Sensor to analog port A1.
![mic](https://user-images.githubusercontent.com/27307550/30575223-2dcc2b32-9cb4-11e7-8b60-3dcf9168188d.jpg)

#### Step 3
Connect the LCD to any of the 4 I2C ports.  (The I2C protocol uses a hardware address to communicate with the LCD, so it will be able to find it when it is connected to any of the 4 I2C ports.)
![lcd](https://user-images.githubusercontent.com/27307550/30575226-2dcd174a-9cb4-11e7-8829-825637d3f111.jpg)

#### Step 4
Connect the microcontroller to its power supply and to a computer via the USB cable.  Program the microcontroller with the code provided with this project.

### Results
After waiting a few minutes, the board should now be running the Noise Monitor program.  Spin the Rotary Angle Sensor until the limit value displayed on the LCD is close to, but greater than, the sound value.  Make loud noises or blow on the Sound Sensor and observe how the LCD reacts.

![working](https://user-images.githubusercontent.com/27307550/30575225-2dccce48-9cb4-11e7-921e-7d7463074c6d.jpg)

### Exploratory Questions
 1. See if you can make the device react to you clapping your hands a single time as loud as you can.  Why is it difficult to make the device react to a single loud sound like this? 
 2. What would you change in the code to poll the sensor at a different speed?  How would this affect the resolution of the average sound?

### In this tutorial we did the following.
 
  1. Learned about **Running Averages**.
  2. **Polled** sensors at different rates.
  3. Used an **Array** to store a large set of data.
  4. Utilized a **Software Delay** to control the resolution of a sensor.
  5. Designed a device that can be tuned to work in many different environments.
  
## BONUS CHALLENGE(S)

### More Feedback!
Modify the code to print different messages (or change the brightness of LCD screen) depending on how far below or above the sound limit we are.
