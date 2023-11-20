//WorkingReceiveProcessingArray
//Created 10/23/23
//Last revised: 10/25/23
//Code by Bradley Butler with code grammer assistance by ChatGPT
//This code is a modification of the RFRelayTransmitter code. This code includes input from chat GPT on how to receive
//and modify Processings Array. This code takes an array from Processing, converts it into something it understands,
//and can run "if" statements based on that. This array is then sent via RF24 to our receiving Arduino

//Important order instructions: This arduino MUST be COM3, the COM that processing writes too. This code must be ran
//with the serial monitor unopened, before the processing code is run
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(3, 2);  // CE, CSN
String dataString;
int state[5];
void setup() {
Serial.begin(9600);
radio.begin();
  radio.setChannel(1);  // Set channel number here, between 0 to 125
  //set the address
  //radio.openWritingPipe(address);
  radio.openWritingPipe(0xA1A1A1A1A1LL);
  //Set module as transmitter
  radio.stopListening();
}

void loop() {
     // Checking if the Processing IDE has send a value or not

//state = Serial.read();    // Reading the data received and saving in the state variable
//int a = int(state);
if (Serial.available()) {
  char c = Serial.read();
  if (c!= '\n'){
    dataString += c;
  } else {
    makethearray();
    radio.write(&state,sizeof(state));
    dataString = "";
  }
}
}
void makethearray(){
  int numTokens = 0;
  char* tokens[5];
  char* token = strtok((char*)dataString.c_str(), ",");
  while (token !=NULL){
    tokens[numTokens++]=token;
    token = strtok(NULL,",");
  }
  if (numTokens == 5){
    for(int i=0;i<5;i++){
      state[i]=atoi(tokens[i]);
    }
    }
    }
