

#include <Stepper.h>

  //define Pins 
const int visorClosedDetectionSwitch = 3;
const int visorOpenDetectionSwitch = 4;
const int rotatorRelay  = 5;
     


const int stepsPerRevolution = 200;                    // change this to fit the number of steps per revolution for you motor
Stepper myStepper(stepsPerRevolution, 10,11,12,13);     // initialize the stepper library on pins 8 through 11:                                 
int stepCount = 0;                                    // number of steps the motor has taken                                   
const int maxSteps = 20000;                           //Watchdog: helps shut down the motor in case the end contacts fail
const int StepperMotorSpeed = 10;



void setup()
{
  Serial1.begin(9600); //comms to LED arduino controller
  InitializePins();
  InitializeStepper(StepperMotorSpeed);
  
}


void loop()
{
  CheckVisorOpenCloseButton();
  CheckRotatorButton();
}


void InitializePins()
{
  pinMode(visorClosedDetectionSwitch, INPUT_PULLUP);
  pinMode(visorOpenDetectionSwitch, INPUT_PULLUP);
  pinMode(rotatorRelay, OUTPUT);
}


