# Arduino Array Sending
### This code takes an array from Processing and converts it before sending it to the receiving Arduino
All that needs to be changed from code to code is the size of the array and the pins for the RF24 radio
## Parts of code
### Heading
Basic info regarding purpose of code, name, and dates
### Pre-Setup
Libraries made for RF24

RF24 Radio created

String created

Array created
## Setup
Serial Began

Radio began

Radio address and purpose defined
## Loop
Read serial

Define character for makearray loop

Call on makearray loop

Send array
## MakeTheArray() loop
Make the array from serial
