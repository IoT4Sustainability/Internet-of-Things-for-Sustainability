# Creating a Security Alarm
### Challenge Level: 2/5
![assembled_system](https://user-images.githubusercontent.com/24983989/33233337-a480a10a-d1c9-11e7-84cb-06b58bd180b1.jpg) <br />


## Introduction
### In this tutorial you will...
  1. Introduce the concept of pulse width modulation
  2. Introduce and use the motion sesor
  3. Build a working security alarm
  
## Explanation
In this tutorial, we will be creating a security alarm. A motion sensor will detect the presence of an intruder and sound an alarm. The LCD and tactile button will form the user interface. The button will arm and disarm the system, giving the user time to depart before arming. The LCD will indicate the state of the alarm and add commotion to the alarm. The buzzer will provide the audible alarm, and we will use it to create an appropriate tone for an alarm. 
 
## Required Materials
 1. Intel Galileo board kit and PC with Arduino IDE installed (see Tutorial 1)
 2. Grove shield
 3. Grove LCD
 4. Grove motion sensor
 5. Grove tactile button
 6. Grove buzzer
 
## Buzzer control
### Sound Waves
The sound waves we hear are made up of oscillating waves, with different frequencies causing us to hear different pitches. We could theoretically use the analog pins on the arduino to exactly replicate the sine wave of a pure musical note. However, this would take a lot of processing. Instead, we can use the digital pins to create a square wave at the same frequency. 

![waves](https://user-images.githubusercontent.com/24983989/33233344-af27eff0-d1c9-11e7-86c8-67f27c0651be.JPG) <br />


A square wave will have the same dominant tone as a sine wave, but the corners will distort the musical note. The additional amplitude will make the sound louder than an equivalent square wave. The harmonics that create the square wave occur at much higher frequencies than the main oscillation, so they will make the sound higher than the main frequency. To learn more about basic sound wave shapes and hear samples of each, visit the following page: https://public.wsu.edu/~jkrug/MUS364/audio/Waveforms.htm.

### Pulse Width Modulation
Now that we have a square wave planned, we need a method of creating it. The pulse width modulation pins are intended for use simulating a sine wave by varying the duty cycle.
![pwm](https://user-images.githubusercontent.com/24983989/33233342-ad25236c-d1c9-11e7-9a5e-7e43b5ff10ff.JPG) <br />
A duty cycle of 50% at a high enough frequency would create an output voltage that is half of the input voltage. By varying the duty cycle over time, a digital (square wave) signal can be used to model an analog (sine wave) one. 
In our case, we are just taking advantage of the fast switching of the PWM pins to create high frequency pitches. The relations are fairly intuitive, with higher frequencies creating higher pitches. Below is a relation between musical notes and the frequencies available to us. <br />

| Frequency | Musical Note | Time Between Switches |
| :---: | :---: | :---: |
| 261 Hz  | c | 1915 microseconds |
| 294 Hz  | d | 1700 microseconds |
| 329 Hz | e | 1519 microseconds |
| 349 Hz  | f | 1432 microseconds |
| 392 Hz  | g | 1275 microseconds |
| 440 Hz | a | 1136 microseconds |
| 493 Hz  | b | 1014 microseconds |
| 523 Hz  | C | 956 microseconds |


 
## Motion Detection
![motion_sensor](https://user-images.githubusercontent.com/24983989/33233386-51825fec-d1ca-11e7-8d55-1882a055035d.jpg) <br />

The motion sensor in our kit is a passive infrared detector. Infrared energy is given off by humans in the form of heat, and a large increase in that heat caused by motion will trip the sensor. The threshold for detection is necessarily set high enough that it will not trip when the sun rises, slightly changing the infrared energy hitting the sensor.  

## Building a Security Alarm

### How it works
Everything we write in this code is effectively digital, which makes our logic lives easy. If the button is pressed, arm or disarm. If motion is detected and the device is armed, fire alarm. For the tone of the alarm, we will simply write the speaker high, delay for the switching time, write it low, delay again, and repeat for the duration of the note. 
 
### Assembly

#### Installing the components
Install the UV sensor, temperature sensor, and LCD using the provided quick connect cables. The following table has been provided for your useage. <br />

Port | Component
--- | ---
A0  |  Motion Sensor
D1  |  Tactile Button
D3 | Buzzer
I2C |  LCD 

The result should look something similar to the following. <br />
![assembled_system](https://user-images.githubusercontent.com/24983989/33233337-a480a10a-d1c9-11e7-84cb-06b58bd180b1.jpg) <br />


#### Upload code
As per usual, download the Security.ino file and compile it to your board. 

### Results
Once the program is running, the LCD should display that it is currently disarmed. <br />
![disarmed_state](https://user-images.githubusercontent.com/24983989/33233340-ab256f18-d1c9-11e7-86a2-0ffe67599915.jpg) <br />
Prepare for obnoxious noises, and press the button. The system should give ten seconds, then all bets are off. <br />
![arming_state](https://user-images.githubusercontent.com/24983989/33233335-9f0347c8-d1c9-11e7-8025-5ad8fbed28e1.jpg) <br />
![calm_state](https://user-images.githubusercontent.com/24983989/33233338-a8be0e1a-d1c9-11e7-91ed-2a5e07cc74aa.jpg) <br />
Once it detects motion it will set off an alarm! <br />
![armed_state](https://user-images.githubusercontent.com/24983989/33233334-9d3b5dea-d1c9-11e7-9a83-575838392692.jpg) <br />

### Exploratory Questions
 1.  How would the sound change if we used sine waves? Triangle waves? 
 2.  What are the limitations of this device as a security device? What functionality could be added to address these concerns. 

### In this tutorial we did the following.
 
 1. Learned about sound waves and PWM.
 2. Walked through the logic for a security alarm.
 3. Installed the physical components.
 4. Finished and tested the security system.
  
## BONUS CHALLENGE(S)

### 99 good tones, but this pitch ain't one
Change the tone of your alarm, and explain to your neighbor why yours is the best. Bonus points if you can add notes for a musical alarm. 
### A TA's worst nightmare
Make your alarm the most obnoxious one in the class. Be creative! If you want to involve the motor and are confident in your coding, reference the Grove_Servo file under File->Sketchbook.
