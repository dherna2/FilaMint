Notes about wire connections to arduino, sensors with boards and prototype/Filamint board.  

gnd: hum(furthest pin right with holes facing up next to empty pin), lcd ("G" written on LCD board)

5v: hum(furthest pin left with holes facing up next to signal pin) , lcd ("P" written on LCD board)

Arduino 2 - hum_sig-resistor (2nd pin from left with holes facing up) - 328p pin4  
Note prototype is model after board which has digital pin 0 and 2 shorted

Arduino 8 - HX711 SCK -  328p pin14  

Arduino A3 - HX711 data - 328p pin26  

Arduino A5 - SCL ("L" written on LCD board) - 328p pin28 

Arduino A4 - SDA ("D" written on LCD board) - 328p pin27

Also Need to have the library for LCD installed, adafruit sensors, HX711  

Note for filamint board connectors have + for vcc and - for gnd helps with connector orientation

![alt text][logo]

[logo]: https://github.com/dherna2/FilaMint/blob/master/code/ece411-t04-filamint-V5.3.jpg "Homer is awsome"

![alt text][logo2]

[logo2]: https://github.com/dherna2/FilaMint/blob/master/code/ece411-t04-filamint-sch-V5.3.jpg "Homer is awsome"

![alt text][logo3]

[logo3]: https://github.com/dherna2/FilaMint/blob/master/code/atmega-pinout.png "Homer is awsome"
