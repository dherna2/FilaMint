Notes about connecting various board to arduino.

Arduino 2-hum_sig_orange,resistor (2nd pin left holes facing up) - 328p pin4

gnd-hum_yellow, lcd_prpl

5v-blue_hum, lcd_yellow

Arduino A5 - SCL-grn - 328p pin28

Arduino A4 - SDA-blue - 328p pin27

HX711 CLK - Arduino A0 - 328p pin23

HX711 data - Arduino A1 - 328p pin24

Also Need to have the library for LCD installed, adafruit sensors, HX711

Note Rev3 requires the HX711 files to be in the same folder as code

Rev4 solves this by user having to create a library of HX711



