
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
A network is defined as a series of nodes connected together for information sharing or other useful purposes. The internet is a great example of exactly how powerful and useful networks can be in our useful lives. For this reason, Internet of Things devices are almost always connected to a network of some kind (if not internet connected). In this tutorial we will introduce some basic network functionality. However in order to do so, one must understand how nodes communiate on a network.

Imagine a crowded room of people and you want to communicate with someone in particular. Simply shouting what you want to tell them might be sufficient. But in order for them to understand who you are talking to, you would usually state their name to get their attention. IP addresses are the names given to nodes on a network in order for them to talk to each other. IP addresses can come in a variety of forms. However, the IP addresses that we will be seeing/using come in the form of '192.168.xxx.xxx'. Simply using a machine's IP address will allow one to send data to them.

### Wireless 
Speaking of networking, let's talk about what sort of network we will be using for this tutorial (and future tutorials). We will be using a wireless router to create an access point for our Intel Galieo boards and other devices to connect to. This network will also allow a computer or cellphone to connect to the network and communicate with a board by using it's IP address. The wireless router should already be setup by your instructor(s). However, keep in mind that any network could be used in place. We simply wanted a network that was not connected to the internet.
 
## Wifi Card (Intel Centrino Advanced N6230)
In order for our Intel Galileo boards to connect to the wireless network, we will need a wireless card to do so. A wireless card is a device that will attach to our boards that will enable them to see and communicate on any wireless network. The Intel Centrino card is compatiable with the Galileo and is capable of communicating on a variety of common wireless protocols; Hence, why we chose to use it.

## Building a WeatherStation

### How it works
A weatherstation reports the current weather. The WeatherStation will report the current temperature (in Fahrenheit) and UVindex on an LCD screen. In addition our weather station will report these values on a webserver hosted on the weather node. In layman's terms, this wil allow us to connect a computer or cellphone and it will display some information on a website. In addition this website will display clothing suggestions based on the current weather conditions.
 
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
