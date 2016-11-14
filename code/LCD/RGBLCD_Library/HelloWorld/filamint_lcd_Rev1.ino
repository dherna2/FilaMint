#include <Adafruit_RGBLCDShield.h>

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

void setup() {
  //Debugging output
  Serial.begin(9600);
  //The LCDs # columns and # rows
  lcd.begin(12,2);

  //Print welcome message
  lcd.print("FilaMint");
  lcd.setBacklight(BLUE);
}

//unsigned integer of 8 bits length
uint8_t i=0;

void loop() {
  //set the cursor to column 0, line 1
  lcd.setCursor(0,1);
  
  //checks for button press
  uint8_t buttons = lcd.readButtons();

  if (buttons){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.setBacklight(WHITE);

  /*******
   if(humidity == high){
   lcd.setCursor(0,1);
   lcd.print("WARNING: High humidity." + \n + "Please add new silica beads.");
   lcd.setBacklight(BLUE);}

   if(filament == low){
   lcd.setCursor(0,1);
   lcd.print("WARNING: Low Filament.: +\n + "There is approximately " + filament_length + " left.");
   lcd.setBacklight(BLUE);}

   
   *******/

}
  
}
