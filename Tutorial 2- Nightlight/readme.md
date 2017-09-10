# Creating a Nightlight

## Introduction

### In this tutorial you will...
  1. Be introduced to the concepts of digital and analog signals
  2. Learn to use the light sensor, button, and potentiometer
  3. Build a working nightlight
  
## Explanation
In this tutorial we will be building a working nightlight. This nightlight will detect the light level in it's surroundings and make a  decision based on the light level to turn on an LED or not. The LED will have a manual activation via a tactile button. Meaning the light can be turned on with a button. The nighlight will also adjust it's decision making based on the position of a potentiometer (turn knob).
However before we can start to build the nightlight, we need to understand some basic concepts of signals and understand how each sensor and actuator works. Once that it done, we will begin assembling the nightlight components and review the logic of how the nightlight works.
 
## Required Materials
 1. Intel Galileo board kit and PC with Arduino IDE installed (see Tutorial 1)
 2. Grove shield
 3. Grove button
 4. Grove potentiometer
 5. Grove light sensor
 
## Digital vs. Analog Signals

### Digital Signals
Digital signals in the scope of our tutorials will refer to the logical interpretation of eletricity. Electricity is a medium with which information can be transmitted. Examples of this are obvious and prevelant. The computer that you are likely viewing this tutorial on operates by processing electrical signals and interpretting that into meaningful logic. Digital signals have a finite (non-infinite) number of possible states. An example of this is the standard household lightswitch. A lightswitch can be either 'on' or 'off'. That's it. Many digital signals are 2 state but there are plently of examples of digital signals that operate on many more states.

### Analog Signals
Analog signals are similar to digital signals in that they represent information by way of a series of separate states. However, while digital signals represent data in a finite number of states, analog signals represent data in an infite number of states. This sounds complicated but it is rather straightforward. An example makes this clear. A traditional volume knob for an mp3 player or computer interprets sound data in a range of values. If a volume knob operated with digital signals, there would only be a few number of volume levels (or potentially only 'on' or 'off').
 
## Grove Tactile Button
The Grove button is a button that comes with our Grove shield kits. There is not too much to say about it. A button is a button. It should be noted that this device communicates using digital signals. The button is a simple device that operates solely on 2 different logical states: 'on' and 'off'. When 'on' data and power may flow freely though the device. When 'off' no signal is allowed through the device. This will be useful for our manual activation of our nightlight.

## Grove Potentiometer
The Grove potentiometer is a bit more complicated. Much like the button, it connects signal from it's source to desination. However, this device operates using analog signals. Meaning depending on the state (position of the dial), the potentiometer will allow only certain amounts of power from it's input to output. This will be used in the nightlight for fine tuning it's performance dynamically while the nightlight is 'on'.
 
## Grove Light Sensor
The Grove light sensor is the first sensor that we will look at. It operates via analog signals, much like the potentiometer. The output signal from this sensor is 'low' when it detects small amounts of light. As the amount of light it detects increases, the output signal increases. Simply, when it is bright out, the sensor value is 'higher' and when it is dark out, the sensor value is 'lower'.

## Building a Nightlight

### How it works
This is how a nightlight works...so logically our sensors should do the following...schematics...etc...

### Assembling the Sensors
Step by step on installing the sensors...

### A Look at the Code
How to open the code...undertanding what the code is doing (high level)...how to run the program

### Results
The night light should now be working...troubleshooting tips...pictures of it working...congrats!

## Summary
 
### In this tutorial we did the following.
 
  1. Learned about the difference between Digital and Analog signals.
  2. Introduced the light sensor, button, and potentiometer.
  3. Installed the physical components.
  4. Walked through the Nightlight logic and code.
  5. Relished in our vicotry. Hurrah! A nightlight!
