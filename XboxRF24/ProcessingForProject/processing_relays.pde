//Created 10/17/2023
//Last revised: 11/20/23
//Code by Bradley Butler
//This code sends arrays over serial for use in a battle boat

import processing.serial.*;
import net.java.games.input.*;
import org.gamecontrolplus.*;
import org.gamecontrolplus.gui.*;
//define controller for GCP
ControlDevice cont;
ControlIO control;

//set values to be taken from controller
float thumblefty;
float thumbleftx;
float thumbrighty;
float thumbrightx;
float lefttrigger;
float righttrigger;
boolean a;
boolean x;
boolean b;
boolean y;
boolean lt;
boolean rt;
//create the matrix
int[] status = new int[5];
//get serial defined
Serial myPort;
void setup() {
  size(360, 200);
  //connect to controller
  control = ControlIO.getInstance(this);
  cont = control.getMatchedDevice("relay2");
  //connect to the arduino's serial, this is why processing must be run AFTER the COM3 arduino is turned on
  myPort = new Serial(this, "COM3", 9600);
  myPort.bufferUntil('\n');
  if (cont == null) {
    println("controller not connected");
    System.exit(-1);
  }
}
 public void getUserInput(){
   //set values to be read from the GDP configuration
   thumblefty= map(cont.getSlider("MotorForward").getValue(), -1,1,1,-1);
   thumbleftx= map(cont.getSlider("MotorDirection").getValue(), -1,1,-1,1);
   lt=(cont.getButton("Reverse").pressed());
   rt=(cont.getButton("Bilge").pressed());
   thumbrightx= map(cont.getSlider("CannonsEach").getValue(), -1,1,-1,1);
   thumbrighty= map(cont.getSlider("CannonsBoth").getValue(), -1,1,-1,1);
   a=(cont.getButton("A").pressed());
   b=(cont.getButton("B").pressed());
   x=(cont.getButton("X").pressed());
   y=(cont.getButton("Y").pressed());
}

void draw(){
  getUserInput();
  background(0, thumblefty, 0);
//if left thumbstick is up
  if (thumblefty > .5)
  {
//tell boat to go forward
 status[0]=3;
  }
//if left thumbstick is down
  if (thumblefty < -.5)
  {
    //tell boat to turn off motors
status[0]=0;
  }
  //if left thumbstick is to the right
  if (thumbleftx>.5)
  {
  status[0]=1;
  }
  if (thumbleftx<-.5)
  {
  status[0]=2;
  }
  //status[0]=int(thumblefty);
  //if (righttrigger<-.1)
  //{

  //}
  //if (righttrigger>-.1)
  //{

  //}
  if (cont.getButton("Reverse").pressed())
  {
  status[1]=1;
  }
  else
  {
  status[1]=0;
  }
  if (cont.getButton("Bilge").pressed())
  {
  status[2]=1;
  }
  else
  {
  status[2]=0;
  }
  if (cont.getButton("A").pressed())
  {
  status[4]=0; 
  }
  if (cont.getButton("B").pressed())
  {
   status[4]=1; 
  }
  if (cont.getButton("X").pressed())
  {
   status[4]=2; 
  }
  if (cont.getButton("Y").pressed())
  {
   status[4]=3; 
  }
  String[] statusStrings = new String[status.length];
  for (int i = 0; i < status.length; i++) {
    statusStrings[i] = str(status[i]);
  }
  String dataArray = join(statusStrings, ",");
   myPort.write(dataArray + '\n');
   println(dataArray);
   delay(50);
  }
