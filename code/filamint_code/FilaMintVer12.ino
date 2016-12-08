/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

/********************
This program will display a menu for the user. It will display the menu options
and be able to change the backlight color (including shutting the screen off the save battery life).
This program will also include button interaction with the user.

FilaMint, 2016
Portland State University


If you alter code please update version number in the version number tracking section below
 ********************/

// version number tracking
#define Ver 12

//This will inlcude the library to the arduino
#include <HX711.h>
#include <Adafruit_RGBLCDShield.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <math.h>

//The shield uses I2C pins
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// Definitions for LCD color
#define OFF 0x0
#define RED 0x1
#define BLUE 0x4
#define WHITE 0x7

// Definitions for Humidity Sensor
#include "DHT.h"
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio


#define DHTPIN 2  // pin assignment using arduino code
#define DHTTYPE DHT22  // Sensor type
DHT dht(DHTPIN, DHTTYPE);

// Definitions for weight sensor
// parameter "gain" is ommited; the default value 128 is used by the library
HX711 scale(A3, 8);    // pin assignment using arduino code

//variable for filament length variable (units: m)
float len = 0;
//variable for weight of spool
float spool = 0;


void setup()
{
  
  // The LCDs # columns and # rows
  lcd.begin(12,2);

  //Print welcome message
  lcd.setBacklight(WHITE);   // Turns on Backlight
  lcd.print("FilaMint ");   // revision tracking
  lcd.print(Ver);           // comment out on Final version
  dht.begin();  // starting humidity sensor
  // weight
  // by the SCALE parameter (not set yet)
  scale.set_scale(2280.f);     // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
  delay(2000);
  
  lcd.clear();
  lcd.print("Initializing...");
  lcd.setCursor(0,1);
  lcd.print("Place new spool"); //previously: lcd.print("Down for Type");
  delay(10000);
  
  lcd.clear();
  lcd.print("Ready");
  delay(1500);
  lcd.clear();
  lcd.print("Press select for");
  lcd.setCursor(0,1);
  lcd.print("a new reading");
}

//unsigned integer of 8 bits length
uint8_t i=0;

const int button = 4;   // Number of buttons
int buttonState = 0;    // Variable for reading button status


void loop()
{
  //set the cursor to column 0, line 1
  lcd.setCursor(0,1);
  float length, mass, h;
  float diameter = 1.75;
  float density = 1.259;
  //checks for button press
  uint8_t buttons = lcd.readButtons();
  //THEY SELECTED TO GO BACK TO MAIN MENU
	if ((buttons & BUTTON_UP) | ((h < 40) & (length > 25)))
	{
		lcd.clear();
		lcd.print("Press select for");
		lcd.setCursor(0,1);
		lcd.print("a new reading");
	}
	else if(buttons & BUTTON_SELECT)
	{
	// Setup LCD 
		lcd.clear();
		lcd.setCursor(0,0);
		lcd.setBacklight(WHITE);
		lcd.print("Reading...");
    
		// Wait a few seconds between measurements.
		// Reading temperature or humidity takes about 250 milliseconds!
		// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
		delay(2000);  
    
		// Read temperature as Celsius (the default)
		float h = dht.readHumidity();
		float mass = scale.get_units();
	
		int length = abs(mass/(density*3.1415*(diameter/2)*(diameter/2)));
	
		// Check if any reads failed and exit early (to try again).
		if (isnan(h))
		{
			lcd.clear();
			lcd.setCursor(0,0);
			lcd.print("Failed to read from DHT sensor!");
			return;
		}

		//calculate the length of filament
		//CALCULATIONS AND CONVERSIONS
		//only focusing on PLA filament at 1.75mm
		//PLA density = 1.25g/cm^3
		//PLA radius = 1.75/2 mm
		//equation for conversion is mass/density*pi*r^2 = length

	
		// Shows data of sensors
		//HUMIDITY READING
		lcd.clear();
		lcd.print("Humidity: ");
		lcd.print(h);
		lcd.print("%"); //units

		//FILAMENT READING
		lcd.setCursor(0,1);  // Move cursor to next line to show both readings
		lcd.print("Filament: ");
		lcd.print(length);
		lcd.print("m"); //units
		delay(5000);
		lcd.clear();
		lcd.print("Press select for");
		lcd.setCursor(0,1);
		lcd.print("a new reading");
	}
	h = dht.readHumidity();
	mass = scale.get_units();
	length = abs(mass/(density*3.1415*(diameter/2)*(diameter/2)));
	// High Humidity alarm text
	if (h > 40)
	{
		lcd.clear();
		lcd.print("WARNING! ");
		lcd.setCursor(0,1);
		lcd.print("Humidity: ");
		lcd.print(h);
		lcd.print("%");
		delay(5000);
		lcd.clear();
		lcd.print("WARNING! ");
		lcd.setCursor(0,1);
		lcd.print("Replace silica");
		delay(2000);
	}
	//Low filament length warning
	else if (length < 10)
	{
		lcd.clear();
		lcd.print("WARNING!");
		lcd.setCursor(0,1);
		lcd.print("Filament: ");
		lcd.print(length);
		lcd.print("m");
		delay(5000);
		lcd.clear();
		lcd.print("WARNING!");
		lcd.setCursor(0,1);
		lcd.print("Replace spool");
		delay(2000);
	}
}
