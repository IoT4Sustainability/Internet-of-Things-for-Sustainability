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
<picture>
The Grove button is a button that comes with our Grove shield kits. There is not too much to say about it. A button is a button. It should be noted that this device communicates using digital signals. The button is a simple device that operates solely on 2 different logical states: 'on' and 'off'. When 'on' data and power may flow freely though the device. When 'off' no signal is allowed through the device. This will be useful for our manual activation of our nightlight.

## Grove Potentiometer
<picture>
The Grove potentiometer is a bit more complicated. Much like the button, it connects signal from it's source to desination. However, this device operates using analog signals. Meaning depending on the state (position of the dial), the potentiometer will allow only certain amounts of power from it's input to output. This will be used in the nightlight for fine tuning it's performance dynamically while the nightlight is 'on'.
 
## Grove Light Sensor
<picture>
The Grove light sensor is the first sensor that we will look at. It operates via analog signals, much like the potentiometer. The output signal from this sensor is 'low' when it detects small amounts of light. As the amount of light it detects increases, the output signal increases. Simply, when it is bright out, the sensor value is 'higher' and when it is dark out, the sensor value is 'lower'.
  
## Light Emiting Diode (LED)
<picture of LED> <picure of LED socket kit>
The light emiting diode or LED for short. The LED emits light when it recieves input. The LED operates using There should be three LEDs included in each kit (red, blue, and green). It is important to note that the LED has a cathode lead (negative) and annode lead (positive). The lead that is longest is the annode lead. The LED then plugs directly into the LED socket kit provided. It is important to plug the LED in properly. Please plug the LED's cathode end near the '-' marked terminal and the LED's annode end near the '+'.

## Building a Nightlight

### How it works
As we already know, a nightlight functions by activating a light when it is dark and deactivates when it is light outside. We can use the LED and Light Sensor to perform this functionality. Based on the outputs from the Light Sensor, we need to decided when to send power to the LED (turn it on). Simply...<br />
  + IF LIGHT_LEVEL > THRESHOLD: LED turns on!<br />
  + ELSE:                       LED turns off!<br />
  **NOTE**: LIGHT_LEVEL is the analog output value from our light sensor and THRESHOLD is a value that we decide upon (determines when the lED      turns 'on').<br />
  
We can improve our design further by using the output of our potentiometer to adjust the THRESHOLD value. This is illustrated as...<br />
  + MOD_THRESHOLD = THRESHOLD x POT_VAL<br />
  **NOTE**: MOD_THRESHOLD is the new value used to determine when the LED turns 'on' or 'off'. POT_VAL is the output from the potentiometer.<br />
Now the new formula we can use for decision making is...<br />
  + IF LIGHT_LEVEL > MOD_THRESHOLD: LED turns on!<br />
  + ELSE:                           LED turns off!<br />

But we are not done yet! We can add another basic functionality. If we use the button we can manually turn the LED 'on' of 'off'. Since the button operates using digital signals, this is pretty simple. It looks like this...<br />
  + IF BUTTON:  LED turns on!<br />
  + ELSE:       LED turns off!<br />
  **NOTE**: BUTTON is the output value from the button. When the button is depressed, BUTTON is true. When the button is not depressed, BUTTON       is false. So 'IF BUTTON: LED turns on!' reads as: 'if the button is depressed, then turn on the LED.<br />

Now we can combine all of these functionalities to create this logic statement...<br />
  + IF LIGHT_LEVEL > MOD_THRESHOLD OR BUTTON: LED turns on!<br />
  + ELSE:                                     LED turns off!<br />
  
The above state statement reads as 'If the light level is greater than the modified threshold or the button is depressed, then turn on the LED'. Pretty simple, eh? Please take a moment to download the nightlight code and review it. Don't worry about understanding what each line of code does! But see if you can find where the code is running the above logic.
 
### Assembling the Sensors
#### Installing the Grove Shield...
#### Installing the components...
Install the sensors

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
