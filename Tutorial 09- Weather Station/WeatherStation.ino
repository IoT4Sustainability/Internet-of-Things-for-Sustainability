// Project: Weather Station
// Creator: Matt Kirkland
// Date:    10/29/2017
// Notes:   

#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include <WiFi.h>

#define pinUVSensor 0    //UV radiation sensor
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
  lcd.print("TEMP    UV INDEX");
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid,pass);
    delay(1);
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
            client.print("Current outdoor UV index: ");
            client.print(uv);
            client.println("<br />");
            client.println("Suggestions based on current weather: <br />");
            client.println("<h3><ul>");
            //print suggestions based on current temperature
            if (temp > 80) { client.println("<li>Consider wearing shorts today</li>"); }
            if (temp < 60) { client.println("<li>Consider wearing a jacket today</li>"); }
            if (temp < 40) { client.println("<li>Consider wearing a hat and gloves today</li>"); }
            //print suggestions based on current UV index
            if (uv < 3)  { client.println("<li>Those with sensitive skin should wear SPF 30+ sunscreen</li>"); }
            if (uv >= 3) { client.println("<li>SPF 30+ sunscreen should be applied every 2 hours</li>"); }
            if (uv > 5)  { client.println("<li>Avoid sun exposure between 10AM and 4PM</li>"); }
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
  //update outdoor temperature
  temp = get_temp();
  //update outdoor UV index
  uv = get_uv();
  //update LCD
  printTempUV_lcd(temp,uv);
}

int get_temp() {
  int t = analogRead(pinTempSensor);
  float R = 1023.0/t-1.0;
  R = R0*R;
  int temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
  return (temperature * 9) / 5 + 32;  // convert from celsius to fahrenheit
}

int get_uv() {
  int sensorValue;
  long  sum=0;
  for(int i=0;i<1024;i++) {
    sensorValue=analogRead(pinUVSensor);
    sum=sensorValue+sum;
    delay(2);
  }
  long meanVal = sum/1024;  // get mean value
  uv = (meanVal*1000/4.3-83)/21;
  delay(20);
}

void printTempUV_lcd(int temp, int uv) {
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.setCursor(8,1);
  lcd.print(uv);
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

