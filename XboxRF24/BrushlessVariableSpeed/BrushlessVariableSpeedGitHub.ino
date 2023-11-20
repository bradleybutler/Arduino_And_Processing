//Brushless motor control (variable speed version)
//Created 10/26/23
//Last revised: 11/14/23
//Code by Bradley Butler
//This code is to interfaces with 2 brushless ESC for speed control
//This code takes the left thumbsticks x position and the right thumbsticks y position to modify the speed and direction of the boat
//create libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
//define motors as servos
Servo Motor1;
Servo Motor2;
//create an RF24 object
RF24 radio(3, 2);  // CE, CSN
//create the array that controls everything
int state[5];
//define speed integer for later modification
int speed;
//define pins for motors and relays
int motor1pin=9;
int motor2pin=10;
//setup
void setup()
{
  while (!Serial);
  //Attach motor 1 to ESC pin
  //Motor1.attach(motor1pin,1000,2000);
  Motor1.attach(motor1pin,1000,2000);
  //Attatch motor 2 to ESC pin
  Motor2.attach(motor2pin,1000,2000);
  //get fancy radio stuff going
    Serial.begin(9600);
  radio.begin();
  radio.setChannel(1);  
  radio.openReadingPipe(1,0xA1A1A1A1A1LL);
  radio.setChannel(1);
  radio.startListening();
}

void loop(){
if (radio.available())
  {
    radio.read(&state, sizeof(state));
    for (int i = 0; i < 5; i++) {
      Serial.print(state[i]);
      if (i < 4) {
        Serial.print(", ");
      }
    }
    Serial.println();
    speed=state[1];
    dir=state[0];
    //if direction joystick says right
    if (dir>0){
      //Left motor is right thumbsticks speed value
      Motor1.write(speed);
      //lower right motor as a function of position
      Motor2.write(speed*((100-dir)/100));
    }
    //if direction joystick says left
    if (dir<0);{
      //lower left motor as a function of position
      Motor1.write(speed*((100+dir)/100));
      //Right motor is right thumbstick's speed value
      Motor2.write(speed);
    }
    if (dir==0){
      //normal speed for both
      Motor1.write(speed);
      Motor2.write(speed);
    }
   //if your driver can reverse use nested if loops and a reverse button assigned to an array value
  }
}