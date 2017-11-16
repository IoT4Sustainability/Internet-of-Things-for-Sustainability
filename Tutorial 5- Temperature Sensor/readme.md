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

## Components

#### LCD
The LCD is explained in the LCD tutorial. We will write to it as well as change the color based on inputs. 
#### Button
The button is a simple switch. Pressing it closes the switch and releasing opens it. The Arduino libraries handle the debouncing of the button. 
#### Temperature Sensor
The temperature sensor reads temperature on a scale of 0-1023, or 0000000000 to 1111111111 in binary. We will use a library function to read the value, but it is our responsibility to convert the binary value to familiar units.

## Building a Nightlight

### How it works
At its core, this project will read the temperature, convert the reading to celsius, and display it to the LCD. To make this more fun, we will add the following features
1) The button will switch between the Celsius reading and the converted Fahrenheit value. This will give practice with if statements. 
2) The temperature will averaged over a window of time to smooth out any jitters. This will show some simple iterative C math.
3) For fun, we will change the color of the LCD screen based on the temperature. The default will be blue for cold and red for warm, but challenge yourself to see how the function works and change these colors.

#### Installing the components
Install the sensors using the provided quick connect cables. Please install each of the components into the corresponding ports...<br />

Port | Component
--- | ---
A0 | Temperature Sensor
D3 | Tactile Button
I2C | LCD

After ensuring that all of the components were installed in the correct port, please plug in the power cable to the Intel Galileo and connect the USB cable to the board and your computer. Open the Arduino IDE, open a new file, and begin writing your code below.

![image](https://user-images.githubusercontent.com/24983989/32183398-7190250e-bd56-11e7-8a59-46504574b320.png)

## Write Your Code
This project will exclusively use given code (though feel free to personalize it!) but it is good practice to avoid copy pasting, as simply typing the code in will help you process how each line works. 
Includes
At the beginning of the file we simply include the header files that we will use functions from. 

 ![image](https://user-images.githubusercontent.com/24983989/32183416-7d41ce20-bd56-11e7-8ecc-b9d0f952f411.png)
 
### Declarations
Next, we declare all of the objects and variables we will use globally. This is not an efficient way to use memory, but it keeps everything simple and easy to read. Significant declarations are described in the comments, but the rest will be explained when they are used. 
	Note: Two basic types of variables are used here:
		Int declares an integer value, which will truncate (drop) any decimal value
		Float declares a floating point value, which will maintain decimal values 
		
 ![image](https://user-images.githubusercontent.com/24983989/32183421-81a0e848-bd56-11e7-828a-bdb64c09a290.png)
 
### Setup
The setup function is used to configure and start peripheral communications that the board will need to use. 
Note: It is generally a good idea to initialize serial communications when programming in the Arduino IDE. It will allow you to print out values from within your code that you can simply read off of the serial monitor. This makes it much easier to determine what is happening within your code. Make sure that the baud rate (rate at which bits are sent on the line, in this case 9600) is matched to the baud rate on the receiving end. 

![image](https://user-images.githubusercontent.com/24983989/32183439-87892248-bd56-11e7-96c6-0c5866dbf2ba.png)
 
### Reading Inputs
We now begin the loop, which is the backbone of the Arduino environment. This function will loop through its code infinitely until something makes it stop. 
The first step in the loop is to read the inputs and set the corresponding variables. First, if we read a non-zero value on the button, we toggle our “toggle” variable. We then delay for half a second to allow the button to be released and settle to zero. There are cleaner ways of doing this once we can’t afford that delay time, but for now this keeps it simple. 

![image](https://user-images.githubusercontent.com/24983989/32183451-8da8b4e0-bd56-11e7-86a5-fe0f3bf4b20c.png)
 
 
### Calculations
Now that we have the readings from our sensors we need to calculate our outputs. The first two equations bring the temperature reading from a scale of 0-1023 to a temperature in Celsius. Next we take a rolling average and compare the current temperature to it to determine the LCD color. Feel free to change the r and b equations to personalize your project!

![image](https://user-images.githubusercontent.com/24983989/32183456-92039028-bd56-11e7-8247-f8a23bec922d.png)
 

### Outputs
We are now ready to output our calculated values to the LCD. We use the LCD library to output the temperature in the units determined by toggle as well as to color it by the values of our r and b equations. 

![image](https://user-images.githubusercontent.com/24983989/32183461-974f201a-bd56-11e7-8c2d-3fdbd54b4845.png)
 
### Compile
You are now ready to compile your code! 


### Results
Once the board begins to run the program, you should see the temperature output to the LCD. Play with the temperature changes and units until you're comfortable with how it all works!

### Exploratory Questions

1. What happens if you breathe on the temperature sensor? What do you think would happen if you did this for several minutes?
2. Is the temperature sensor reading ambient temperature, or the temperature of an object in front of it?

### In this tutorial we did the following.
 
1.	Connected peripheral devices to the Galileo
2.	Read values from sensors
3.	Calculated outputs
4.	Printed to the LCD
  
## BONUS CHALLENGE(S)

### Temperature Sensor 2.0
1) Attempt to modify the code to print purple for hot and green for cold.
2) Try to add a Kelvin option. 
