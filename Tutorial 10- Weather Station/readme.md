
# Creating a WeatherStation
### Challenge Level: 4/5

## Introduction
### In this tutorial you will...
  1. Introduce the concept of IP addressing and networking
  2. Introduce and install the Wifi Card
  3. Build a working WeatherStation
  
## Explanation
In this tutorial, we will be creating a WeatherStation node.
 
## Required Materials
 1. Intel Galileo board kit and PC with Arduino IDE installed (see Tutorial 1)
 2. Grove shield
 3. Grove LCD
 4. Grove temperature sensor
 5. UV sensor
 6 Mini PCI-e Wireless card (Intel Centrino Advanced N6230)
 7 Working WPA2 wireless network
 
## Networking
### IP Addressing
A network is defined as ... IP addresses are ... 

### Wireless 
We will be using a wireless router to network our WeatherStation node with whatever wireless devices we want!
 
## Wifi Card (Intel Centrino Advanced N6230)
A wireless card is...and works by...

## Building a WeatherStation

### How it works
The logic of how the WeatherStation will work...
 
### Assembly
#### Installing the WifiCard
Please carefully insert the Intel Centrino Advanced N6230 (WifiCard) into the mini PCIe slot of the microcontroller...

#### Installing the components
Install the sensors using the provided quick connect cables. Please install each of the components into the corresponding ports...<br />

Port | Component
--- | ---
A0  |  UV Sensor
A1  |  Temperature Sensor
I2C |  LCD 

#### Update the IP address
Connect to your PC and open this project in the Arduino IDE. Test functionality by ... also take a wireless device and connect to the network and update the IP address and ssid and password...this information is displayed in the ...

### Results
When working it should do ... test by using the webserver to ...

### Exploratory Questions
 1.  How are the server (Intel Galileo) and clients (any connected device that accesses the Intel Galileo webpage)? How can we be sure        that a message made it to to it's intended recipient?
 2.  If the wanted to 

### In this tutorial we did the following.
 
 1. Learned about networking and IP addresses
 2. Walked through the logic for a WeatherStation.
 3. Installed the physical components.
 4. Updated code after finding the IP address of the board and network credentials
 6. Finished and tested the WeatherStation
  
## BONUS CHALLENGE(S)

### A More Helpful Node
Modify the code of the server to add the following suggestions based on UV Index and Temperature.

 1. If the UV index is greater than 7, print the message: "Woah, it's bright. Wear sunglasses."
 2. If the UV index is between 5 and 10 and it is greater than 100 degrees outside, print the message: "Don't go outside!"
 3. If the temperature is between -20 and 28 degrees, print the message: "Freezing cold! Wear lots of layers."
