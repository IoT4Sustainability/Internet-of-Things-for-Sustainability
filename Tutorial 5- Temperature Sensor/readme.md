# Creating a Temperature Sensor
### Challenge Level: 1/5
![image](https://user-images.githubusercontent.com/24983989/32183398-7190250e-bd56-11e7-8a59-46504574b320.png)

## Introduction

### In this tutorial you will...
  1. Take input from a temperature sensor and a button
  2. Convert measured values to desired units
  3. Print text and color to the LCD

  
## Explanation
In this project we will read a temperature from a sensor and convert it into either Celsius or Fahrenheit depending on button input. We will then print the temperature to the LCD and indicate whether the current temperature is hotter or colder than recent temperatures using the RGB backlight on the LCD. 
 
## Required Materials
1.	Intel Galileo board
2.	Grove shield for sensor connection
3.	Temperature sensor
4.	Button
5.	LCD

## Explain components here

## Building a Nightlight

### How it works

#### Installing the components
Install the sensors using the provided quick connect cables. Please install each of the components into the corresponding ports...<br />

Port | Component
--- | ---
A0 | Temperature Sensor
D3 | Tactile Button
I2C | LCD

After ensuring that all of the components were installed in the correct port, please plug in the power cable to the Intel Galileo and connect the USB cable to the board and your computer. Open the Arduino IDE, open a new file, and begin writing your code below.

![Assembled](https://user-images.githubusercontent.com/22579849/30304750-fe00e0b8-9723-11e7-9600-4a7790477c3d.jpg)

## Write Your Code
This project will exclusively use given code (though feel free to personalize it!) but it is good practice to avoid copy pasting, as simply typing the code in will help you process how each line works. 
Includes
At the beginning of the file we simply include the header files that we will use functions from. 
 
### Declarations
Next, we declare all of the objects and variables we will use globally. This is not an efficient way to use memory, but it keeps everything simple and easy to read. Significant declarations are described in the comments, but the rest will be explained when they are used. 
	Note: Two basic types of variables are used here:
		Int declares an integer value, which will truncate (drop) any decimal value
		Float declares a floating point value, which will maintain decimal values 
 
 
### Setup
The setup function is used to configure and start peripheral communications that the board will need to use. 
Note: It is generally a good idea to initialize serial communications when programming in the Arduino IDE. It will allow you to print out values from within your code that you can simply read off of the serial monitor. This makes it much easier to determine what is happening within your code. Make sure that the baud rate (rate at which bits are sent on the line, in this case 9600) is matched to the baud rate on the receiving end. 
 
 
### Reading Inputs
We now begin the loop, which is the backbone of the Arduino environment. This function will loop through its code infinitely until something makes it stop. 
The first step in the loop is to read the inputs and set the corresponding variables. First, if we read a non-zero value on the button, we toggle our “toggle” variable. We then delay for half a second to allow the button to be released and settle to zero. There are cleaner ways of doing this once we can’t afford that delay time, but for now this keeps it simple. 

 
 
### Calculations
Now that we have the readings from our sensors we need to calculate our outputs. The first two equations bring the temperature reading from a scale of 0-1023 to a temperature in Celsius. Next we take a rolling average and compare the current temperature to it to determine the LCD color. Feel free to change the r and b equations to personalize your project!

 

### Outputs
We are now ready to output our calculated values to the LCD. We use the LCD library to output the temperature in the units determined by toggle as well as to color it by the values of our r and b equations. 
 
### Compile
You are now ready to compile your code! 


### Results
Once the board begins to run the program, you should see the temperature output to the LCD. Play with the temperature changes and units until you're comfortable with how it all works!

![Working](https://user-images.githubusercontent.com/22579849/30304758-fe1fd81a-9723-11e7-8d38-fe3f28e31b4d.jpg) <br />

### Exploratory Questions

1. What happens if you breathe on the temperature sensor? What do you think would happen if you did this for several minutes?
2. 

### In this tutorial we did the following.
 
1.	Connected peripheral devices to the Galileo
2.	Read values from sensors
3.	Calculated outputs
4.	Printed to the LCD
  
## BONUS CHALLENGE(S)

### Temperature Sensor 2.0
1) Attempt to modify the code to print purple for hot and green for cold.
2) Try to add a Kelvin option. 
