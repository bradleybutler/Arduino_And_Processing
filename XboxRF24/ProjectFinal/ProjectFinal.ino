//Final Boat Code
//Created 10/26/23
//Last revised: 11/20/23
//Code by Bradley Butler
//This code is to interface with a relay to control 2 brushless motors and 2 bilge pumps, one a cannon and one connected to sprayers
//create libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//create an RF24 object
RF24 radio(3, 2);  // CE, CSN
//create the array that controls everything
int state[5];
int cannon=8;
int motor1pin=5;
int motor2pin=6;
int sprayers=7;
//setup
void setup()
{
  while (!Serial);
  pinMode(motor1pin,OUTPUT);
  pinMode(motor2pin,OUTPUT);
  pinMode(cannon,OUTPUT);
  pinMode(sprayers,OUTPUT);
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
    //if thumbstick back
    if(state[0]==0){
      state00(); 
    //if thumbstick left
    }
    if(state[0]==1){
      state01();
    }
    //if thumbstick right
    if(state[0]==2){
      state02();
    }
    //if thumbstick forward
    if(state[0]==3){
      state03();
    }
    if(state[1]==1){
      digitalWrite(cannon,HIGH);
    }
    if(state[1]==0){
      digitalWrite(cannon,LOW);
    }
    if(state[2]==1){
      digitalWrite(sprayers,HIGH);
    }
    if(state[2]==0){
      digitalWrite(sprayers,LOW);
      }
    }
}

void state03(){
//full speed
      digitalWrite(motor1pin,HIGH);
      digitalWrite(motor2pin,HIGH);
}
void state02(){
      //on left off right
      digitalWrite(motor1pin,HIGH);
      digitalWrite(motor2pin,LOW);
}
void state01(){
      //on right off left
      digitalWrite(motor1pin,LOW);
      digitalWrite(motor2pin,HIGH);
}
void state00(){
//check if the reverse bumper is down
      //if(state[1]==1){
      //reverse bumper is down
      //full speed
      //digitalWrite(motor2pin,LOW);
      //digitalWrite(motor1pin,LOW);
      //digitalWrite(cannon1,HIGH);
      //digitalWrite(pump,HIGH);
    //}
      //reverse bumper isn't on, stop boat
      //else{
      digitalWrite(motor2pin,LOW);
      digitalWrite(motor1pin,LOW);
      //digitalWrite(cannon1,LOW);
      //digitalWrite(cannon2,LOW);
  }
void ABTN(){

}
void BBTN(){

}
void YBTN(){

}
void XBTN(){

}