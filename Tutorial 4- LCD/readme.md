# The Most Important Tool - The LCD Screen

## Introduction

### Topics to be Covered
  1. Learn about the LCD screen
  2. Modify LCD to change colors and content
  3. Display Important Data

### Explanation
This tutorial introduces one of the most useful items in our Seed kit, the LCD screen. An LCD screen is a backlit monitor screen, and we are going to learn how to use one and why it is so useful. We will alter already defined variables to change the color of the screen, and hopefully find a color we like, and then learn what we can display on the screen and the limitations of our screen. But enough of the explanation, lets get into the meat of this tutorial.

### Required Materials
  1. Intel Galileo and Grove shield
  2. Arduino IDE
  3. LCD Screen from Grove kit and a connector

## The Grove LCD RGB Backlight Screen
The Grove LCD Screen is one of the most powerful and important attachments we have for our Galileo board. It is the best way of sending information in the program back out to us, the user. Other sensors and attachments we have for our board consist mostly of having two states, such as the on or off state of the button, or a scale of states ranging from 1 to a large number, as with the potentiometer that can be rotated for different values. On the other hand, the LCD screen can display any number of unique things that we want it to, albeit in a limited amount. It also is the board's way of communicating with us, while a button and potentiometer are how we communicate to the board. Key uses of the LCD screen are to display the values contained within variables of the program, or to display the value that another sensor sends to the board. If we look at the case where there is a button hooked up to our board and we want to know what value the button returns, we can just set that up to print straight to the LCD screen so we know what value it is exactly. 

### The LCD Screen and Strings
The information that the LCD screen can convey to us is limited in terms of how much it can display at once due to the size of the screen, but can still display important information within the program that we otherwise don't have access to. In a normal computer program, you transmit data to the user through a computer monitor, and this data can take the form of text, pictures or even full length videos. Using our LCD screen as the monitor, the data we can transmit to the user is limited to two rows of sixteen letters, numbers or symbols, also called a string. To the programming language C, a string is a grouping of any single characters on a keyboard, and is usually contained within a string declared variable, or within two quotation marks. In the following line of code: 

> myLCDScreen.print( "Hello World" );

The phrase within the quotation marks, Hello World, are the contents of the string. The quotation marks themselves are not a part of it, but are used to identify the string between them. An important thing to note is that for every quotation mark in your code, there MUST be a closing quotation mark somewhere after it. If there is not, then the program will think every single thing after the first quotation mark is part of a string, and it may skip over most of your program. On the other hand, you can't just omit the quotation marks and have myLCDScreen.print(Hello World), or it is going to try and find something called Hello World, which leads to even more errors. So be careful and make sure your quotation marks line up. 

## LCDScreenBasic
We can finally get to the interesting part of the tutorial, setting up our board and giving it a program to run. The picture below shows the setup of our board. 

![lcdscreen](https://user-images.githubusercontent.com/14320086/32156182-0b723404-bcf9-11e7-8688-839ebd2e820e.jpg) <br />

We need our Intel Galileo board and shield, a single connector, and the LCD screen. The LCD screen needs to be connected to an IC2 port, of which there are four on the shield. Any one of them will work for our screen. 
