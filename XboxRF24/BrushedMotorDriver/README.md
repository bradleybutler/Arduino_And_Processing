# Brushed Motor Driver
This code is for using the remote to control 2 brushed motors with the use of a L298N motor driver. This is not tested as we did not use brushed motors

In your processing code set joysticks or triggers to map 0-255 and control states 0 and 1. Set anything to toggle state 2 for reversing

For a more intuitive control use the brushless code's system of motor speed as a function of position

## Parts
### Heading
Contains info on name, purpose, and dates
### Pre-Setup
Include Libraries

Make radio

Make array

Setup pins for motor drivers
### Setup
Set pin modes

Set initial state

Define radio as receiver
### Loop
Get radio going

Read array

If reverse isn't on

 - Set speed of motors as states

If reverse is on

 - Set motors to reverse

