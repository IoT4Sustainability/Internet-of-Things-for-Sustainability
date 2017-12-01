#include <rgb_lcd.h>
#include <Wire.h>

rgb_lcd lcd;

const int rotaryPin = 0;
const int micPin = 1;

void setup() 
{ 
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.home();

    pinMode(rotaryPin, INPUT);
    pinMode(micPin, INPUT);
}

void loop() 
{
    int dataArray [40];
    int i = 0;
    int sum = 0;
    int average = 0;
    int soundLimit = 0;
    int soundLimit_temp = 0;
    int settingsDelay = 0;

    // Print a message to the LCD.
    lcd.clear();
    lcd.home();
    lcd.setRGB(255, 255, 255); //white background
    lcd.print("Initializing...");

    for(i=0; i <= 39; i++) //initalize array with room's current sound level
    {
      dataArray[i] = analogRead(micPin);
      delay(250);
    }

    lcd.setRGB(50, 255, 50); //green screen at start
    lcd.clear();
    lcd.setCursor(1,1);
    lcd.print("Acceptable noise level.");

    soundLimit = analogRead(rotaryPin); //set starting values
    soundLimit_temp = soundLimit;
    
  while(1) //stay in this loop forever
  {
          for(i=1; i <= 39; i++) //shift all data 1 index
          {
            dataArray[i-1] = dataArray[i];
            dataArray[i] = 0;
          }
    
          dataArray[39] = analogRead(micPin); //read in current noise
  
          sum = 0;
          for(i=0; i <= 39; i++) //add all data points in the array
            sum += dataArray[i];
  
          average = sum/40; //calculate average

          soundLimit = analogRead(rotaryPin); //read current sound limit setting

          if(soundLimit > (soundLimit_temp + 10) || soundLimit < (soundLimit_temp - 10)) //if current sound limit setting has changed
           settingsDelay = 20; //20 x 250ms = 5 second delay

          soundLimit_temp = soundLimit; //remeber the previous sound limit setting do detect if it changes later

          if(settingsDelay > 0) //if sound limit value setting was changed display the new setting for 5 seconds
          {
            if(average > soundLimit)
              lcd.setRGB(255, 0, 0); //red screen
            else
              lcd.setRGB(50, 255, 50); //green screen
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Sound");
            lcd.print(" ");
            lcd.print("Limit");
            lcd.setCursor(0,1);
            lcd.print(average);
            lcd.setCursor(6,1);
            lcd.print(analogRead(rotaryPin));
            settingsDelay--;
          }
          else //else display the normal screen feedback
          {
            if(average > soundLimit) //if sound is too loud
            {
              lcd.setRGB(255, 0, 0); //red screen
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("It's too loud!");
            } 
            else //else sound level is OK
            {
                lcd.setRGB(50, 255, 50); //green screen
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Acceptable noise");
                lcd.setCursor(0,1);
                lcd.print("level.");
            }
          }
    
          delay(250);  // 1/4 second update rate
  }
}
