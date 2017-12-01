/* Security system
 * Assembled by David Mortin
 */


//***************Includes****************

#include <Wire.h> // Allows communication with the LCD over I2C
#include "rgb_lcd.h" // Header file for LCD

//***************Declarations************

rgb_lcd lcd; // Declares LCD object
const int pinButton = 4, pinSpeaker = 3, pinMotion = A0; //Define variables for the component pins
int RawReading = 0, toggle = 0; // Basic variables
int c = 1915; // Switching time for the note "c"
int Alarm_tone = c;
int Alarm_length = 200;

//****************Setup******************

void setup() {
    lcd.begin(16, 2); // set up the LCD's number of columns and rows
    pinMode(pinButton, INPUT); 
    pinMode(pinSpeaker, OUTPUT);
    Serial.begin(9600);
    lcd.setRGB(0,100,100);
}

//*****************Main Loop*************

void loop() {
    lcd.clear();
    pollButton();
  
    RawReading = analogRead(pinMotion); // Read the raw value in bits from the motion sensor
    
    lcd.home(); // Bring the print location to the first position of the LCD
    if(toggle==0) lcd.print("Disarmed");
    if(toggle==1) lcd.print("Armed");
    lcd.setCursor(0,2); // Set the cursor to the bottom line for the upcoming input

    if(RawReading>500&&toggle==1){ // Alarm tripped!
      lcd.print("ALERT!");
      lcd.setRGB(255,0,0);
      playTone(Alarm_tone, Alarm_length);
      digitalWrite(pinSpeaker, LOW);
      delay(250);
      }
    else if(toggle==1){ // Armed but no alarm
      lcd.print("All is calm >.>");
      lcd.setRGB(20,20,20);
    }
    
    delay(15); // Delay 15ms to avoid asking the LCD to print while it's still printing
}

void pollButton(){
  if(digitalRead(pinButton)){ // This function will activate if a non zero value is read from the button when this line occurs
      if(toggle == 0) 
      {
        lcd.print("Arming");
        toggle = 1; // If the toggle value is 0, make it 1
        delay(10000); // Give the user 10 seconds to leave the area before arming the alarm
      }
      else{
        lcd.setRGB(0,100,100);
        toggle = 0; // Otherwise make it 0
      }
      delay(500); // Delay 500ms to allow for button release and debouncing
      lcd.clear(); // Clear the LCD so that it can be rewritten without stray characters
    }
}

void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000; i += tone * 2) {
        digitalWrite(pinSpeaker, HIGH);
        delayMicroseconds(tone);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(tone);
    }
}
