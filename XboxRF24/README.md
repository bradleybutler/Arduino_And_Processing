# Xbox Remote for RF24L01 Control
## This code allows you to use an Xbox or other common remote for the remote control of Arduino projects
### This code was done for use in the MECH202 "Barbie Boat Battle" competition at Colorado State University. This code, while my own, was influenced and assisted by the tutorials of MakeUseOf and HowToMechatronics. This code can be easily modified for your own personal projects
#### Concept
This consists of three seperate codes. 
Processing will use the Game Control Plus library to take inputs from your controller, and send that via serial to your transmitting Arduino. This can be done based on your method, I recommend using arrays if multiple components need control, or you can skip the array if only one element needs to be controlled.
The Arduino that receives the serial input will then transmit that input via RF24L01 to another Arduino Uno. This code needs to be able to decode the array before it can send it, or can send the value directly if it is not in array form
The Receiving Arduino then needs to understand the array yet again, and can then use those values to control your object as wanted
## Codes in this Repository include
### Fully Formed -

### ProcessingArraySending - Processing (Serial Transmitting)
This processing code will send an array via serial to Arduino
### BrushedMotorDriver - Arduino (RF24 Receiving)
This code shows how to use a motor driver for brushed motors and how they can be controlled remotely. This code was not properly tested as I did not have access to brushed motors or their drivers
### ProjectFinal - Arduino (RF24 Receiving)
This code is the final for my project. This code is quite simple as speed control and reversing was not possible with our drivers. All outputs go to relays for their control so HIGH and LOW values are all that is necessary
### BrushlessVariableSpeed - Arduino (RF24 Receiving)
This code shows how to use brushless motor drivers and has the ability to control motor power steering as function of joystick position

### Basis - 

### 
