Notes about connecting various board to arduino.

Arduino 2-hum_sig_orange,resistor

gnd-hum_yellow, lcd_prpl

5v-blue_hum, lcd_yellow

Arduino A5-SCL-grn

Arduino A4-SDA-blue

HX711 CLK - Arduino A0
HX711 data - Arduino A1


Also Need to have the library for LCD installed, adafruit sensors, HX711

Note Rev3 requires the HX711 files to be in the same folder as code

Rev4 solves this by user having to create a library of HX711



