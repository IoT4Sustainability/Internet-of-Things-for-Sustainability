// Project: Smart Thermostat: Outdoor Node
// Creator: Matt Kirkland
// Date:    10/29/2017
// Notes:   Displays the current temperature(Fahrenheit) and UV index on an LCD.
//          Sends data to indoor node.

#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include <WiFi.h>

#define pinTempSensor 1  //TEMP sensor
#define B 4275            //Base value of the thermistor
#define R0 100000         //The resistor value (100k)
#define rgbR  100         //
#define rgbG  255         //RGB values for the LCD
#define rgbB  255         //

char ssid[] = "Galileans";    // Please set this value to SSID
char pass[] = "IoTGalileo";   // Please set this value to Network Key
int temp,uv = 0;              // starting temperature and uv index values
int status = WL_IDLE_STATUS;

WiFiServer server(80);
rgb_lcd lcd;

void setup() {
  // establish serial connection
  Serial.begin(9600);
  // set up the LCD
  lcd.begin(16, 2);
  lcd.setRGB(rgbR, rgbG, rgbB);
  lcd.print("Temperature");
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid,pass);
    delay(1000);
  } 
  //start server
  server.begin();
  // print status of connection
  printWifiStatus();
}

void loop() { 
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
          //read client request
          char client_request = client.read();
          if (client_request == '\n' && currentLineIsBlank) {
            //print HTML to connected client
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println("Refresh: 3");
            client.println();
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            //print current temperature and UV inedex
            client.print("Current outdoor temperature: ");
            client.print(temp);
            client.println("<br />");
            client.println("</html>");
            break;
          }
          if (client_request == '\n') { currentLineIsBlank = true; }
          else if (client_request != '\r') { currentLineIsBlank = false; }
      }
    }
    //give the client time to respond
    delay(1);
    //close the connection
    client.stop();
  }
  //update outdoor temperature
  temp = get_temp();
  //update LCD
  print_lcd(temp);
  delay(1000);
}

int get_temp() {
  int t = analogRead(pinTempSensor);
  float R = 1023.0/t-1.0;
  R = R0*R;
  int temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  return (temperature * 9) / 5 + 32;  // convert from celsius to fahrenheit
}

void print_lcd(int temp) {
  lcd.setCursor(0,1);
  lcd.print(temp);
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
