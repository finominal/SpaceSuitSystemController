#include <Stepper.h>

const int stepsPerRevolution = 200;                    // change this to fit the number of steps per revolution for you motor
Stepper myStepper(stepsPerRevolution, 10,11,12,13);     // initialize the stepper library on pins 8 through 11:                                 
int stepCount = 0;                                    // number of steps the motor has taken                                   
const int maxSteps = 20000;                           //Watchdog: helps shut down the motor in case the end contacts fail
const int StepperMotorSpeed = 10;

        


#define DPAD_UP 0; //analogue
#define DPAD_DOWN 1; //analogue
#define DPAD_LEFT 2; //analogue
#define DPAD_RIGHT 3; //analogue
#define DPAD_A 4; //analogue
#define DPAD_B 5; //analogue
#define DPAD_START 6; //analogue
#define DPAD_SELECT 7; //analogue

//define alias for buttons
#define visorOpenCloseButton DPAD_A;
#define rotatorLightToggleButton DPAD_B;

//define Sensor Switch Pins 
#define visorClosedDetectionSwitch = 3;
#define visorOpenDetectionSwitch = 4;


void setup()
{
  Serial1.begin(9600); //comms to LED arduino controller
  //InitializeStepper(StepperMotorSpeed);
}

void loop()
{
 // CheckVisorOpenCloseButton();
}




//This code has a dependancy on the stepper code. 


void CheckVisorOpenCloseButton()
{
  
  if(visorOpenCloseButton == HIGH)
  {
    while(visorOpenCloseButton == HIGH){} //wait for button to be released, helps stop looping
    MoveVisor();
  }
  
}
/*

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
    MoveStepper(-1);
    // ? Do we need to set a timer here, or will the stepper motor speed take care of that? 
  }
  MoveStepper(-10); //once contact switch is triggered, move a little further so that the contact switch is definately closed.
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

*/

