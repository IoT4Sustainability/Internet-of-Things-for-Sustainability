# Introduction to Basic Programming

## Introduction

### Topics for this tutorial
  1. Learn the structure of a basic arduino file
  2. Variables and types
  3. Conditionals and loops (if, else, while)
  4. Include libraries

## Explanation
This tutorial will be a basic crash course into the fundamentals of programming your own arduino programs to run on your Galileo board. We will take a look at the code used in the previous Nightlight program, and work on examples similar to that code. The goal is to learn how to write and read simple arduino programs for our own Galileo board. We will cover how to include pre-made libraries, how to declare and use variables, and the importance of conditional statements and loops. 
An important note is that the code we will be using for our Arduino programs mostly follows the syntax of C, C++, and any languages like them, along with its own Arduino flare. Each piece of code will be shown below and hopefully explained in an easy to understand way.

## Required Materials
  1. Intel Galileo and Grove shield
  2. Arduino IDE
  3. Grove button
  4. Grove light sensor
  5. Grove LED

## Arduino Program Structure
### Setup Function
We will start by opening up our Arduino Interactive Development Environment, or IDE for short. After opening the Arduino software, we should start a new file by clicking the blue New File button at the top, which will take us to a screen like this. 
![Opening IDE](https://cloud.githubusercontent.com/assets/22579849/23933974/52b7030c-08ff-11e7-945e-995b8be870ee.PNG)
To begin programming our own first arduino program, we need to understand the major components to include in a .ino file. There are two key parts that we need to add to our own program, and fortunately, the IDE has supplied us with both of those things, albeit empty. When the program is uploaded to the Galileo board, the first thing that runs is setup. The code looks like this:
>  void setup() {
>  // put your setup code here, to run once:
>  
>  }
As it says, this block of code will run once. It is very important to define the various pins on the Galileo shield as either output or input through the use of the pinMode() function. The pinMode() function, as well as any other function, takes a number of input values which are within the parenthesis, points to a larger block of code, and when you use the function call such as pinMode(), it uses the inputs and runs all of the code that it points to. And unless you are building functions, its not that important to know what goes on in one. For us, pinMode() just sets up the connector on the shield to either send information out (output), or to receive information from a source (input). We will start off easy, and add the following line of code on its own line between the two curly braces of the setup function:
>  pinMode(8, INPUT);
This pinMode() function call takes the number 8, and the string INPUT, and does work that we can't see to let us use the pin D8 as an input pin. You can use any number from 1 to 8 to choose D1 to D8 as the connector port, but we are going to use D8. Now, we can plug a button into that pin, and the board will read when we press the button. And lets do just that, plug a connector to a button into the D4 port. The button will not do anything yet, because the loop section is still empty, but its an important start. 
Go ahead and add another pinMode() call to setup another digital port of your choice to be used for an output instead of an input, and then plug in the LED from the nightlight tutorial to that port. If you need to use an analog port in the future, to specify the analog ports, or A0, A1, A2, and A3 on the shield, we simply insert an A before the number we add into the pinMode call, and it looks like this:
>  pinMode(A0, ____);
### Main Loop
The main loop() function, shown below, repeatedly runs after setup() is complete until the power cable is unplugged or the machine turns off. 
>  void loop() {
>    // put your main code here, to run repeatedly:
>
>  }
This is the section that you would put the bulk of the code you wanted to run. In the previous Nightlight tutorial, the code to read the light sensor, check for the button, and turn the light on are all in this section. 
