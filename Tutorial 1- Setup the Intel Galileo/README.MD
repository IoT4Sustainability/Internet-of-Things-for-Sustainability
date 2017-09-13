# Setup the Intel Galileo

## Introduction

### In this tutorial you will...
  1. Get the Intel Galileo firmware updated and install necessary drivers
  2. Installing the Operating System (OS) on the Intel Galileo
  3. Install the Arduino software development environment
  4. Run the example blinking light program on the Intel Galileo
  
## Explanation
 
 In order to start using the Intel Galileo, we will need to setup the board so that way we can push code to it. This requres
 installing drivers, flashing the board (if a gen 1 board), and setting up the Arduino Integrated Development Environment (IDE).
 The Arduino IDE will allow us to easily write code and send commands to the Intel Galileo. 
 
## Required Materials
 
 1. Intel Galileo board
 2. Power and USB cable for Intel Galileo
 3. A computer with an internet connection and 7Zip installed
 4. A 1 Gigabyte(or bigger) SD card 
 5. An SD card reader
 
 Most of these are provided  with the Intel Galileo!
 ![Intel Galileo Box](https://cloud.githubusercontent.com/assets/22579849/23934041/bc8bddde-08ff-11e7-81dc-2a321b0c9131.jpg)
 
## Setup the Intel Galileo

### Plugging in the Intel Galileo Board
 1. Plug in the intel Galileo using the provided 5v wall cable. After a small period of time, 2 green lights should appear on the board. The first light will turn on when the board recieves power and the other will turn on when the board is ready to be connected to a computer. ![Board](https://cloud.githubusercontent.com/assets/22579849/23934042/bc8f6256-08ff-11e7-8b69-21833941d653.jpg)
 
 ![Board with Power](https://cloud.githubusercontent.com/assets/22579849/23934043/bc8ffe3c-08ff-11e7-877b-aecc007f479a.jpg)
 
 
 2. Connect the Intel Galileo to a computer using the provided USB cable. It is important that both the USB cable and the power cable are plugged into the board. Otherwise the Intel Galileo will not recieve enough power to function correctly. ![Board with USB](https://cloud.githubusercontent.com/assets/22579849/23934690/46f3521e-0904-11e7-9bff-81b326ae6e5b.jpg)

### Installing Intel Galileo Driver (Windows PCs only)

On the compuer connected to the Intel Galileo...
 1. Download the latest version of the firmware and drivers package. We have included this file in the folder for version 1.1.0 for Windows and Mac. As of this writing, this is the most up to date package. If you would like to download a more up to date software please follow this link: https://downloadcenter.intel.com/product/78906/Intel-Galileo-Boards. Select your operating system and the correct file.
 2. Navigate to the folder "Galileo Driver". Right click on the "linux-cdc-acm.inf" file and select "install" from the proceding menu. Upon success, a message "The operation completed successfully" should appear.
 
 
![Installing Windows Driver](https://cloud.githubusercontent.com/assets/22579849/23929965/9145b500-08e6-11e7-950e-1ef34fe9a166.PNG)

 3. Restart the compuer.
 
### Installing the Arduino Integrated Development Environment(IDE)
On the compuer connected to the Intel Galileo...
 1. Download the latest Arduino IDE from their webpage or download the one on our page if you are using Windows OS. As of this writing, 1.8.1 is the most up to date package. Here is the link for that: https://www.arduino.cc/en/main/software.
 2. Run the file(s) and follow the on-screen instructions to install the software. ![Installing IDE](https://cloud.githubusercontent.com/assets/22579849/23933961/4479c838-08ff-11e7-83bb-9f3648866a9d.PNG)
 3. Open the Arduino IDE when it is done installing. ![Open IDE](https://cloud.githubusercontent.com/assets/22579849/23933974/52b7030c-08ff-11e7-945e-995b8be870ee.PNG)
 4. In the Arduino IDE...
    1. Navigate to "Tools" -> "Board" and click on "Board Manager". ![Board Manger](https://cloud.githubusercontent.com/assets/22579849/23933978/571fd22a-08ff-11e7-94d3-0eb442fe7cf8.PNG)
    2. In the "Board Manager" window, scroll down to "Intel i586 Boards". Select the most up to date. ![Board Manager Install](https://cloud.githubusercontent.com/assets/22579849/23933980/5a9fe11a-08ff-11e7-9cbe-33adc1fa881a.PNG)
    
    In this case, it is "1.6.2+1.0" and click "install". The bottom part of the window will state that it is downloading "board definitions". Wait until it is done. If installed correctly, scrolling back down to "Intel i586 Boards" should say "installed" along with the version you installed. ![Installing Board Packages](https://cloud.githubusercontent.com/assets/22579849/23933982/5d3d7658-08ff-11e7-9e2e-2c25edc7d846.PNG)

### Updating the Intel Galileo Firmware
On the compuer connected to the Intel Galileo...
 1. Navigate to the "firmware-updater-1.1.0.exe" file and run it.
 2. Click update. Ensure not to reomove the power or usb cable from the Intel Galileo. A message should appear when the firmware was installed correctly.
 
 ![Firmware Updater](https://cloud.githubusercontent.com/assets/22579849/23933989/62bd1b60-08ff-11e7-9316-3652e0de7eb5.PNG)
 
### Installing the Intel Galileo Operating System (OS)
On the compuer connected to the Intel Galileo...
 1. Insert the provided SD card or an SD card of at least 1GB in size into the computer.
 2. Download the Intel Galileo OS from Intel for the latest version. The file is called "SDCard.1.1.1.tar.bz2". Here is the link to that file: https://downloadcenter.intel.com/download/26418/Intel-Galileo-Board-Software-Package?product=78919.
 
 
 3. Open the file using 7Zip. ![Install OS 1](https://cloud.githubusercontent.com/assets/22579849/23933990/66ae2d7c-08ff-11e7-9f03-5bb4dd39c9bb.PNG)
 
 
 4. In the 7Zip folder, right-click "SDCard.1.1.1.tar" and click open. Wait until the tar file is done untarring. ![Install OS 2](https://cloud.githubusercontent.com/assets/22579849/23933991/6af04e6a-08ff-11e7-9ec3-6942b4a41c8e.PNG)
 
 
 5. Copy the contents of the "image-full-galileo" folder into the main directory of the SD card. ![Install OS 3](https://cloud.githubusercontent.com/assets/22579849/23933992/6e818ed6-08ff-11e7-87be-f388a6b19d9e.PNG)
 
![Install OS 4](https://cloud.githubusercontent.com/assets/22579849/23933995/733a9d1e-08ff-11e7-9349-07fa7f92ad2f.PNG)
 
![Install OS 5](https://cloud.githubusercontent.com/assets/22579849/23934003/78049552-08ff-11e7-9fe6-73a8e52e0400.PNG)


 6. Eject the SD card from the computer. Insert the SD card into the Intel Galileo. ![The SD Card Inserted](https://cloud.githubusercontent.com/assets/22579849/23934047/bca52758-08ff-11e7-881d-0a64d0e1df3e.jpg)
 
### Blinking LED on Intel Galileo
Now in order to test if the board is working as expected. Run a sample program that will blink the Galileo's builtin LED by doing the following.
1. Plug the Intel Galileo into the computer (if it is not still plugged in).
2. Open up the Arduino IDE. Go to "tools" and select "Intel Galileo" as the board. Then select the port. Use the port that the Intel Galileo is connected on. (Usually COM3 or COM4)
3. Navigate to "Files" -> "Examples" -> "01.Basics". Then select "blink". This is the program that will blink the builtin LED on the Galileo.
4. Click the upload button(arrow icon). After a few minutes, the Arduino IDE should state "Tranfer complete".
5. Congrats! The board should now be blinking it's builtin LED.
![Blinking Board](https://cloud.githubusercontent.com/assets/22579849/23934046/bca24100-08ff-11e7-86d8-b1427c3bc9ac.jpg)

## Summary
 
### In this tutorial we did the following.
 
  1. Installed drivers for the Intel Galileo
  2. Updated the firmware of the Galileo
  3. Downloaded the Galileo OS and installed it onto an SD card
  4. Installed the Arduino IDE
  5. Blinked the internal LED on the Galileo
