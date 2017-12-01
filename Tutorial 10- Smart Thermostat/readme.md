
# Creating a Smart Thermostat
### Challenge Level: 5/5
![Final-ST](https://user-images.githubusercontent.com/22579849/32919212-ce20f272-cad9-11e7-8f69-36cb04f01ef9.jpg) <br />

## Introduction
### In this tutorial you will...
 1. Discuss the logic of the Smart Thermostat.
 2. Build the Smart Thermostat.
 3. Test the system to ensure that it is working.
  
## Explanation
In this tutorial, we will be creating a Smart Thermostat. This tutorial involves using networking multiple Intel Galileo board together. The purpose is to have an outdoor node that obtains temperature information and sends it to the indoor node that reads it's own temperature. Based on these readings the Smart Thermostat can make 'smart' suggestions for the user based on indoor and outdoor conditions. These suggestions are provided with a webserver as seen in the WeatherStation tutorial.
 
## Required Materials
 1. Intel Galileo board kit x 2
 2. PC with Arduino IDE installed (see Tutorial 1)
 3. Grove shield x 2
 4. Grove LCD x 2
 5. Grove temperature sensor x 2
 6 Mini PCI-e Wireless card (Intel Centrino Advanced N6230) x 2
 7 Working WPA2 wireless network

## Building a Smart Thermostat

### How it works
The Smart Thermostat works by way of 2 Intel Galileo boards communicating with eath other. The outdoor node gathers and reports it's temperature data to it's LCD. The outdoor continues to then post this information on a webserver. The indoor nodes also gathers temperature data and reports it to it's LCD. In order to fetch the outdoor node's temperature, it connects to the outdoor node webserver and decodes the HTML code in order to fetch the outdoor node's temperature. After this is done, it updates it's LCD with both the indoor and outdoor temperature. It then posts suggestions for heating and cooling on a webserver of it's own.
 
### Assembly
#### Installing the components
This build requires building 2 separate Intel Galileo boards. Install the temperature sensor and LCD in the following format on both of the Grove shields. <br />

Port | Component
--- | ---
A1  |  Temperature Sensor
I2C |  LCD 

<br />![Shield-ST](https://user-images.githubusercontent.com/22579849/32919209-cdd7a112-cad9-11e7-9d17-0a655524c450.jpg) <br />
![Shield2-ST](https://user-images.githubusercontent.com/22579849/32919208-cdbedd44-cad9-11e7-9cb9-01ed4d157e08.jpg) <br />
After the installation is of the shield components is complete, connect the shields to each Galileo board. Attach the wireless cards to each board if this is not already done (see WeatherStation tutorial for details). Connect one of the Intel Galileo boards to your PC and upload the outdoor node sketch. This wil be the outdoor node.
![Shield3-ST](https://user-images.githubusercontent.com/22579849/32919210-cdf1120a-cad9-11e7-8747-c96cd5583ba6.jpg) <br />

#### Update the IP address
We need to obtain the IP address of the outdoor node. So upon upload of the OutdoorNode sketch, open the serial monitor and obtain the IP address. Disconnect the outdoor node from the PC. It should now be complete and outputting temperature data to the LCD. If not, ensure that the SSID and password match the network that it is connecting to.<br />
![OutdoorNode-ST](https://user-images.githubusercontent.com/22579849/32919211-ce059acc-cad9-11e7-9acb-10a124c56ff4.jpg) <br />
Open the IndoorNode sketch, near the top of the file there is line that determines the IP address of the server. If this IP address does not match the outdoor node's IP address, please update it. Take this time to ensure that the network credentials match the outdoor node's network credentials. Also, the targetted temperature can be changed at this time to whatever the user desires.

### Results
![IndoorNode-ST](https://user-images.githubusercontent.com/22579849/32919213-ce3e02fe-cad9-11e7-9cbb-01da304db9d2.jpg) <br />
Upload the IndoorNode sketch to the indoor node. Ensure that you obtain the Indoor node's IP address. It should start displaying an indoor and outdoor temperature on the LCD. Please make sure that the outdoor node is working and is still on at this point. Connect a wireless device to the network and open a browser. Enter the IP address of the indoor node into the search bar. An HTTP website should display with suggestions based on the target, indoor, and outdoor temperature.
![IndoorWebServer-ST](https://user-images.githubusercontent.com/22579849/32919059-609eea9c-cad9-11e7-86e6-b01bd4d754a4.JPG) <br />
![Final-ST](https://user-images.githubusercontent.com/22579849/32919212-ce20f272-cad9-11e7-8f69-36cb04f01ef9.jpg) <br />

### Exploratory Questions
 1.  What would happen if the outdoor node changed it's HTTP server to print the temperature in a different location on the page? Would the indoor node still be able to interpret the outdoor temperature?
 2.  If the outdoor node is not working, how does the indoor node react? Can you tell why that is the case? (hint: look at the IndoorNode code)

### In this tutorial we did the following.
 
 1. Discussed the logic of the Smart Thermostat.
 2. Built the Smart Thermostat.
 3. Tested the system to ensure that it is working.
  
## BONUS CHALLENGE(S)

### Three's Company
Attempt to add a third node to the configuration. The third node will be another outdoor node. The indoor node should recieve both outdoor node's values but will report an average of the 2 outdoor node's temperatures.
