# Processing Basics
Going through how to make the config files, upload it, and what each part of the code does
## Downloading GCP and G4P
Following MakeUseOf's tutorial except for the Arduino Firmatta part may be more concise https://www.makeuseof.com/tag/arduino-robot-game-controller/

In Processing click sketch > import library > manage libraries

Search for G4P and install it, do the same with GameControl Plus
## Configuring your controller
3:25 in MakeUseOf's tutorial
In Processing click file > examples > Game Control Plus > Gcp_Configurator

Plug in your controller and run the program

Select your controller

Name everything to it's function and drag and drop

Save as a name you can recall
## Importing data
Open a blank sketch and save it

Go into your computer's documents file > Processing > libraries > GameControlPlus > Examples > Gcp_Configurator and copy the data folder

Go into documents > Processing > the name of the sketch you just created and paste the data folder
## Setting up
Here import your libraries with sketch > import library > Game control plus

    import net.java.games.input.*;
    import org.gamecontrolplus.*;
    import org.gamecontrolplus.gui.*;
Also import the serial with 

    import processing.serial.*;
Define your device with ControlDevice and ControlIO, both named to something you can recall

    ControlDevice cont;
    ControlIO control;
Set values for you controller inputs to relate to, booleans for buttons and bumpers and floats for thumbsticks and triggers

Make an array if you will be using one, recommended if you have to control multiple aspects

Define your serial

    Serial myPort;
Now in void setup

Connect to your controller

    control = ControlIO.getInstance(this);
And define it's config file

    cont = control.getMatchedDevice("yourconfig");
Connect to the serial port, changing the COMX value to your Arduino's COM
N

Connect your controller and tell it which config file to do
