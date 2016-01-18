//#include <Stepper.h>

const int stepsPerRevolution = 200;                    // change this to fit the number of steps per revolution for you motor
//Stepper myStepper(stepsPerRevolution, 10,11,12,13);     // initialize the stepper library on pins 8 through 11:                                 


boolean UP, DOWN, LEFT, RIGHT, A, B;
boolean DEV = false;

int BRIGHTNESS = 128;

const int rotatorPin = 4;

//define Sensor Switch Pins 
const int visorCloseDetectionSwitch = 2;
const int visorOpenDetectionSwitch = 3;

//define stepper communication pins
#define M0 6
#define M1 7
#define M2 8
#define ENABLE 5
#define RESET 9
#define SLEEP 10
#define STEP 11
#define DIRECTION 12



void setup()
{
  
  Serial.begin(9600); //comms to LED arduino controller
  if(DEV) Serial.println("Hello world!");
  InitializeStepper();
  //MoveStepper(400);
}



void loop()
{
  ReadButtons();

  //PrintAnalogPorts();
  //PrintButtons();
  //PrintEndSwitches();

  //Set Rotator Toggle
  CheckForRotatorToggle();

  //Set new program if direciton button is pressed.
  CheckLedProgramChange();

  //move visor if visor toggle is pressed. 
  CheckVisorOpenClose();

  //check for serial pogram.
  serialEvent();
  delay(100);
}










