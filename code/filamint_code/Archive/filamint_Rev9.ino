#include <HX711.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_Sensor.h>

/********************
This program will display a menu for the user. It will display the menu options
and be able to change the backlight color (including shutting the screen off the save battery life).
This program will also include button interaction with the user.

FilaMint, 2016
Portland State University

 ********************/

//This will inlcude the library to the arduino
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <math.h>


//The shield uses I2C pins
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

//These definitions are for the color
#define OFF 0x0
#define RED 0x1
#define BLUE 0x4
#define WHITE 0x7

//defining buttons of the LCD 

//#define btnRIGHT  0
//#define btnUP     1
//#define btnDOWN   2
//#define btnLEFT   3
//#define btnSELECT 4

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//weight
HX711 scale(A1, A0);    // parameter "gain" is ommited; the default value 128 is used by the library


void setup()
{
  //Debugging output
  Serial.begin(9600);
  // The LCDs # columns and # rows
  lcd.begin(12,2);
  dht.begin();

  // weight
  // by the SCALE parameter (not set yet)  

  scale.set_scale(2280.f);     // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
  
  lcd.clear();
  lcd.print("New reading");
  lcd.setCursor(0,1);
  lcd.print("Insert new spool");
}

//unsigned integer of 8 bits length
uint8_t i=0;

const int button = 4;   // Number of buttons
int buttonState = 0;    // Variable for reading button status

void loop()
{
  //set the cursor to column 0, line 1
  lcd.setCursor(0,1);
  
  //checks for button press
  uint8_t buttons = lcd.readButtons();
  buttonState = digitalRead(buttons);
  if (buttons & BUTTON_SELECT)
  {
    lcd.clear();
    lcd.print("New reading");
    lcd.setCursor(0,1);
    lcd.print("Insert new spool");
  }
  else if (buttons & BUTTON_DOWN)
  {
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("PLA");
    lcd.setCursor(0,1);
    lcd.print("ABS");
    delay(5000);
    if (buttons & BUTTON_DOWN)
    {
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("ABS 1.75mm");
      lcd.setCursor(0,1);
      lcd.print("ABS 3.00mm");
    }
    else if (buttons & BUTTON_UP)
    {
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("PLA 1.75mm");
      lcd.setCursor(0,1);
      lcd.print("PLA 3.00mm");
    }
  }

  else if(buttons & BUTTON_UP)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.setBacklight(WHITE);
    // Wait a few seconds between measurements.
    delay(2000);  

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    // Check if any reads failed and exit early (to try again).
    if (isnan(h))
    {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // uncomment humidity 
    //move cursor to next line to show both readings
    lcd.clear();
    lcd.print("Humidity: ");
    lcd.print(h);

    lcd.setCursor(0,1);
    lcd.print("Weight: ");
    lcd.print(scale.get_units(), 1);

    if (h > 50)
    {  
      // High alarm text
      lcd.clear();
      lcd.print("High! ");
      lcd.print(h);
    }
  } 
}
