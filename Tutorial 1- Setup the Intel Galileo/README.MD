# Setup the Intel Galileo

## Introduction

### In this tutorial you will...
  1. Get the Intel Galileo firmware updated and install necessary drivers
  2. Installing the Operating System (OS) on the Intel Galileo
  3. Installl the Arduino software development environment
  4. Run the example blinking light program on the Intel Galileo
  
## Explanation
 
 In order to start using the Intel Galileo, we will need to setup the board so that way we can push code to it. This requres
 installing drivers, flashing the board (if a gen 1 board), and setting up the Arduino Integrated Development Environment (IDE).
 The Arduino IDE will allow us to easily write code and send commands to the Intel Galileo. 
 
## Required Materials
 
 1. Intel Galileo board
 2. Power and USB cable for Intel Galileo
 3. A computer with an internet connection and 7Zip installed
 4. A 4 Gigabyte(GB) SD card 
 5. An SD card reader
 
## Setup the Intel Galileo

### Plugging in the Intel Galileo Board
 1. Plug in the intel Galileo using the provided 5v wall cable. After a small period of time, 2 green lights should appear on the board. The first light will turn on when the board recieves power and the other will turn on when the board is ready to be connected to a computer.
 2. Connect the Intel Galileo to a computer using the provided USB cable. It is important that both the USB cable and the power cable are plugged into the board. Otherwise the Intel Galileo will not recieve enough power to function correctly.

### Installing Intel Galileo Driver (Windows PCs only)

On the compuer connected to the Intel Galileo...
 1. Download the latest version of the firmware and drivers package. We have included this file in the folder for version 1.1.0 for Windows and Mac. As of this writing, this is the most up to date package. If you would like to download a more up to date software please follow this link: https://downloadcenter.intel.com/product/78906/Intel-Galileo-Boards. Select your operating system and the correct file.
 2. Navigate to the folder "Galileo Driver". Right click on the "linux-cdc-acm.inf" file and select "install" from the proceding menu. Upon success, a message "The operation completed successfully" should appear.
![Installing Windows Driver](https://cloud.githubusercontent.com/assets/22579849/23929965/9145b500-08e6-11e7-950e-1ef34fe9a166.PNG)

 3. Restart the compuer.
 
### Installing the Arduino Integrated Development Environment(IDE)
On the compuer connected to the Intel Galileo...
 1. Download the latest Arduino IDE from their webpage or download the one on our page if you are using Windows OS. As of this writing, 1.8.1 is the most up to date package. Here is the link for that: https://www.arduino.cc/en/main/software.
 2. Run the file(s) and follow the on-screen instructions to install the software. (screen shot 2)
 3. Open the Arduino IDE when it is done installing. (screen shot 3)
 4. In the Arduino IDE...
    1. Navigate to "Tools" -> "Board" and click on "Board Manager". (screen shot 4)
    2. In the "Board Manager" window, scroll down to "Intel i586 Boards". Select the most up to date. (screen shot 5)In this case, it is "1.6.2+1.0" and click "install". The bottom part of the window will state that it is downloading "board definitions". Wait until it is done. If installed correctly, scrolling back down to "Intel i586 Boards" should say "installed" along with the version you installed. (screen shot 6)

### Updating the Intel Galileo Firmware
On the compuer connected to the Intel Galileo...
 1. Navigate to the "firmware-updater-1.1.0.exe" file and run it.
 2. Click update. Ensure not to reomove the power or usb cable from the Intel Galileo. A message should appear when the firmware was installed correctly. (screen shot 7)
 
### Installing the Intel Galileo Operating System (OS)
On the compuer connected to the Intel Galileo...
 1. Insert the provided SD card or an SD card of at least 4GB in size into the computer.
 2. Download the Intel Galileo OS from Intel for the latest version. The file is called "SDCard.1.1.1.tar.bz2". Here is the link to that file: https://downloadcenter.intel.com/download/26418/Intel-Galileo-Board-Software-Package?product=78919.
 3. Open the file using 7Zip. (screen shot 8)
 4. In the 7Zip folder, right-click "SDCard.1.1.1.tar" and click open. Wait until the tar file is done untarring. (screen shot 9)
 5. Copy the contents of the "image-full-galileo" folder into the main directory of the SD card. (screen shot 10) (screen shot 11) (screen shot 12)
 6. Eject the SD card from the computer. Insert the SD card into the Intel Galileo. (picture)
## Summary
 
### In this tutorial we did the following.
 
  1. Installed drivers for the Intel Galileo
  2. Updated the firmware of the Galileo
  3. Downloaded the Galileo OS and installed it onto an SD card
  4. Installed the Arduino IDE
  5. Blinked the internal LED on the Galileo
