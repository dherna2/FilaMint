Notes about wire connections to arduino, sensors with boards and prototype/Filamint board.  

gnd: hum(furthest pin right with holes facing up next to empty pin), lcd ("G" written on LCD board)

5v: hum(furthest pin left with holes facing up next to signal pin) , lcd ("P" written on LCD board)

Arduino 2 - hum_sig-resistor (2nd pin from left with holes facing up) - 328p pin4  
[Need to fix code to be digital pin 0 for hum_sig to make Filamint board work]

Arduino A0 - HX711 SCK -  328p pin23  
[Need to fix code to be digital pin 8 to make Filamint board work]

Arduino A1 - HX711 data - 328p pin24  
[Need to fix code to be analog pin 3 to make Filamint board work]

Arduino A5 - SCL ("L" written on LCD board) - 328p pin28 

Arduino A4 - SDA ("D" written on LCD board) - 328p pin27

Also Need to have the library for LCD installed, adafruit sensors, HX711  
Rev3 requires the HX711 files to be in the same folder as code  
Rev4+ solves this by having user create a library called HX711 .h and .cpp files

![alt text][logo]

[logo]: https://github.com/dherna2/FilaMint/blob/master/code/ece411-t04-filamint-V5.3.jpg "Homer is awsome"

![alt text][logo2]

[logo2]: https://github.com/dherna2/FilaMint/blob/master/code/ece411-t04-filamint-sch-V5.3.jpg "Homer is awsome"

![alt text][logo3]

[logo2]: https://github.com/dherna2/FilaMint/blob/master/code/atmega-pinout.png "Homer is awsome"
