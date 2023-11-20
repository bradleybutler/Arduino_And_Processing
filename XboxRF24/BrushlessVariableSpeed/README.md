# Brushless Variable Speed
This code takes inputs from RF24 and uses it to control two brushless motors. The left thumbstick x value should be mapped -100 to 100 and the right thumbstick y value 0-180 in Processing, states 0 and 1 respectively

## Parts
### Heading
Contains info on name, dates, and purpose
### Pre-Setup
Get libraries going

Define motors as servos

make radio

Make array

Make integers
### Setup
Attach motors

Start radio
### Loop
Read radio and make array

Set integers to array

If loops that modify speed based on direction value
