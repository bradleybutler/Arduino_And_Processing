//Created 10/17/2023
//Last revised: 11/20/23
//Code by Bradley Butler
//Modify this code to take your own inputs. Must make your own config file

import processing.serial.*;
import net.java.games.input.*;
import org.gamecontrolplus.*;
import org.gamecontrolplus.gui.*;
//define controller for GCP
ControlDevice cont;
ControlIO control;

//set values to be taken from controller
boolean a;
float b;
//create the matrix, change value x to size of your matrix
int[] status = new int[x];
//get serial defined
Serial myPort;
void setup() {
  size(360, 200);
  //connect to controller
  control = ControlIO.getInstance(this);
  //change yourconfig to the name of your config file in data
  cont = control.getMatchedDevice("yourconfig");
  //connect to the arduino's serial, change COMX to COM of your Arduino
  myPort = new Serial(this, "COMX", 9600);
  myPort.bufferUntil('\n');
  if (cont == null) {
    println("controller not connected");
    System.exit(-1);
  }
}
 public void getUserInput(){
   //set values to be read from the GDP configuration. Change mapping as necessary
   b= map(cont.getSlider("nameinconfig").getValue(), -1,1,1,-1);
   a = (cont.getButton("nameinconfig").pressed());
}

void draw(){
  getUserInput();
  //change background color as you want, this is unnecessary
  background(0, 0, 0);
  if (cont.getButton("nameinconfig").pressed())
  {
  status[0]=1;
  }
  else
  {
  status[0]=0;
  }
  status[1]=int(b);
  //make array, nothing here should need to be changed except for delay to preference
  String[] statusStrings = new String[status.length];
  for (int i = 0; i < status.length; i++) {
    statusStrings[i] = str(status[i]);
  }
  String dataArray = join(statusStrings, ",");
   myPort.write(dataArray + '\n');
   println(dataArray);
   delay(50);
  }
