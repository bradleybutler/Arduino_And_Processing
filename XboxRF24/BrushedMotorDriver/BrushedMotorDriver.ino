//WorkingReceiveProcessingArrayMotorDriver
//Created 10/25/23
//Last revised: 11/20/23
//Code by Bradley Butler
//This code should work for controlling a DC motor with a L298N module. We are not using a L298N module.
//thus, this code is obsolete for our brushless motor purposes. In your processing code set joysticks or triggers to map 0-255 and control states 0 and 1. Set anything to toggle state 2 for reversing
//create libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//create an RF24 object
RF24 radio(3, 2);  // CE, CSN
//create the array that controls everything
int state[5];
// Motor A connections
int enA = 5;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 6;
int in3 = 9;
int in4 = 10;

void setup()
{
  while (!Serial);
  //LED test pins
  pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  // Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
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
    //if reverse is not on
    if (state[2]==0){
      analogWrite(enA,state[0]);
      analogWrite(enB,state[1]);
      //forward both
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,HIGH);
      digitalWrite(in4,LOW);
    }
    //if reverse is on
    if (state[2]==1){
      analogWrite(enA,state[0]);
      analogWrite(enB,state[1]);
      //reverse both
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
    }
  }
}


