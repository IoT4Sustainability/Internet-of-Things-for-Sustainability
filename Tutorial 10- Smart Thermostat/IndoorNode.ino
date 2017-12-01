// Project: Weather Station: Indoor Node
// Creator: Matt Kirkland
// Date:    10/29/2017
// Notes:   Reads outside UV index and temperature from outdoor node.
//          Prints outdoor node data and indoor temperature on an LCD.

#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include <WiFi.h>

#define pinTempSensor A0  //TEMP sensor
#define B 4275            //Base value of the thermistor
#define R0 100000         //The resistor value (100k)
#define rgbR  100         //
#define rgbG  255         //RGB values for the LCD
#define rgbB  255         //

char ssid[] = "Galileans";    // Please set this value to SSID
char pass[] = "IoTGalileo";   // Please set this value to Network Key
int target_temp = 70;         // Please set this value to desired temperature (degrees Fahrenheit)
int outdoor_temp, indoor_temp = 0;
int status = WL_IDLE_STATUS;

IPAddress server(192,168,1,62);  //Please set this to the IPv4 address of the server
WiFiClient client;
WiFiServer cli_server(80);  //HTML webserver (user site)
rgb_lcd lcd;

void setup() {
  // establish serial connection
  Serial.begin(9600);
  // set up the LCD
  lcd.begin(16, 2);
  lcd.setRGB(rgbR, rgbG, rgbB);
  lcd.print("Inside   Outside");
  // connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid,pass);
    delay(1);
  }
  // print status of connection
  printWifiStatus();
  //start client-side server
  cli_server.begin();
}

void loop() {
  //try to connect to server
  if (client.connect(server, 80)) {
    // Make a HTTP request to server
    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: 192.168.1.62");
    client.println("Connection: close");
    client.println();
    //await response
    String html = "";
    while (client.available()) {
      char c = client.read();
      html = html + c;
      if (html.indexOf("Current outdoor temperature: ")>0) {
        html = "";
        while (client.available() && c != '<') {
          html = html + c;
          c = client.read();
        }
        outdoor_temp = html.toInt();
      }
    }
    //disconnect from server
    client.stop();
  }
  
  //update values and LCD
  indoor_temp = get_temp();
  printvals_lcd();
  
  //run webserver for user interface
  WiFiClient client = cli_server.available();
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
            //current indoor and outdoor temperatures
            client.print("Current indoor temperature: ");
            client.print(indoor_temp);
            client.println("<br />");
            client.print("Current outdoor temperature: ");
            client.print(outdoor_temp);
            client.println("<br />");
            client.print("Target temperature: ");
            client.print(target_temp);
            client.println("<br />");
            //print suggestions based on target, outside, and inside temperature
            client.print("SmartThermostat suggestions: <br />");
            client.println("<h3><ul>");
            if (target_temp < indoor_temp && outdoor_temp < indoor_temp) { client.println("<li>Open a window!</li>"); }
            else if (target_temp < indoor_temp) { client.println("<li>Turn on the AC!</li>"); }
            else if (target_temp > indoor_temp && outdoor_temp > indoor_temp) { client.println("<li>Open a window!</li>"); }
            else if (target_temp > indoor_temp) { client.println("<li>Turn on the heater!</li>"); }
            else { client.println("<li>Temperature is just right. Enjoy!</li>"); }
            client.println("</ul></h3>");
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
  delay(500);
}

int get_temp() {
  int t = analogRead(pinTempSensor);
  float R = 1023.0/t-1.0;
  R = R0*R;
  int temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  return (temperature * 9) / 5 + 32;  // convert from celsius to fahrenheit
}
void printvals_lcd() {
  lcd.setCursor(0,1);
  lcd.print(indoor_temp);
  lcd.setCursor(9,1);
  lcd.print(outdoor_temp);
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
