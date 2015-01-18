#include <Stepper.h>


const int stepsPerRevolution = 200;                    // change this to fit the number of steps per revolution for you motor
Stepper myStepper(stepsPerRevolution, 10,11,12,13);     // initialize the stepper library on pins 8 through 11:                                 
int stepCount = 0;                                    // number of steps the motor has taken                                   
const int maxSteps = 20000;                           //Watchdog: helps shut down the motor in case the end contacts fail
const int StepperMotorSpeed = 10;

boolean UP, DOWN, LEFT, RIGHT, A, B;

boolean rotatorOn = false;

const int rotatorPin = 4;

//define Sensor Switch Pins 
const int visorClosedDetectionSwitch = 11;
const int visorOpenDetectionSwitch = 12;

//define stepper communication pins
#define ENABLE 8
#define RESET 9
#define SLEEP 10
#define STEP 11
#define DIRECTION 12

void setup()
{
  Serial.begin(9600); //comms to LED arduino controller
  InitializeStepper();
  TestMove(-500);
}

void loop()
{
  ReadButtons();
}


void ToggleRotator()
{
  if (B == true)
  {
   rotatorOn = !rotatorOn;
  }
  
  if(rotatorOn == true)
  {
    digitalWrite(rotatorPin,LOW);
  }
  else
  {
    digitalWrite(rotatorPin,HIGH);
  }
  
  while(B == true)
 {
   ReadButtons();
 } 

 Serial.println("Exit B Button Press");
 delay(5);
 
}


void ReadButtons()
{
  if(analogRead(A6) >500) {LEFT = true;} else {LEFT = false;}
  if(analogRead(A5) >500) {RIGHT = true;} else {RIGHT = false;}
  if(analogRead(A4) >500) {UP = true;} else {UP = false;}
  if(analogRead(A7) >500) {DOWN = true;} else  {DOWN = false;}
  if(analogRead(A2) >500) {A = true;} else  {A = false;}
  if(analogRead(A3) >500) {B = true;} else  {B = false;}
}

void InitializePins()
{
 pinMode(4,OUTPUT); //toggle relay for rotator
}

//This code has a dependancy on the stepper code. 

void CheckVisorOpenCloseButton()
{
  if(B == HIGH)
  {
   // while(B == HIGH) //wait for button to be released, helps stop looping
   // MoveVisor();
  }
}


void MoveVisor()
{
 
  //If the visor is somewhere in between open and closed, open it.
  if(visorClosedDetectionSwitch == LOW and visorOpenDetectionSwitch == LOW)
  {
    OpenVisor();
  }
  
  //If visor is detected as CLOSED, open it
  else if (visorClosedDetectionSwitch == HIGH)
  {
    OpenVisor();
  }
  
  //if visor is detected as OPEN, close it. 
  else if (visorOpenDetectionSwitch == HIGH)
  {
    CloseVisor();
  }
  
}

void OpenVisor()
{
  while(visorOpenDetectionSwitch == LOW)
  { 
    MoveStepper(10);
    // ? Do we need to set a timer here, or will the stepper motor speed take care of that? 
  }
  MoveStepper(-1); //once contact switch is triggered, move a little further so that the contact switch is definately closed.
}

void CloseVisor()
{
  while(visorClosedDetectionSwitch == LOW)
  {
    MoveStepper(1);
  }
  MoveStepper(-10); //once contact switch is triggered, move a little further so that the contact switch is definately closed.
}



void InitializeStepper(int motorSpeed)
{
  myStepper.setSpeed(motorSpeed);
}



