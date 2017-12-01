#include <rgb_lcd.h>
#include <Wire.h>

rgb_lcd lcd;

const int moisterSensorPinA0 = 0; //assign pin A0
const int LOWMOISTERTHRESHOLD = 50; //low moister analog value

void setup() 
{ 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.home();

  pinMode(moisterSensorPinA0, INPUT);
}

void loop() 
{
  int moistureLevel = 0;

  lcd.clear();
  lcd.home();
    
  while(1) //stay in this loop forever
  {
    moistureLevel = analogRead(moisterSensorPinA0); //read current sound limit setting

    if(LOWMOISTERTHRESHOLD >= moistureLevel) //soil is dry
    {
      lcd.setRGB(255, 0, 0); //red screen
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("I need water!!!");
      lcd.setCursor(0,1);
      lcd.print(analogRead(moisterSensorPinA0));
    } 
    else //else soil is moist
    {
      lcd.setRGB(50, 255, 50); //green screen
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Water level OK.");
      lcd.setCursor(0,1);
      lcd.print(analogRead(moisterSensorPinA0));
    }

    delay(1000);  // 1 second update rate
  }
}
