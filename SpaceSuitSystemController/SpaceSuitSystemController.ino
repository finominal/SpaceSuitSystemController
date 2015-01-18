

//#include <Stepper.h>

#define STEP_DIR_OPEN false
#define STEP_DIR_CLOSE true

  //define Pins 
const int visorClosedDetectionSwitch = 3;
const int visorOpenDetectionSwitch = 4;
const int rotatorRelayPin  = 5;
     
const int stepsPerRevolution = 200;                    // change this to fit the number of steps per revolution for you motor
//Stepper myStepper(stepsPerRevolution, 10,11,12,13);     // initialize the stepper library on pins 8 through 11: 


//const int stepperMode0 = 7;
//const int stepperMode1 = 8;
//const int stepperMode2 = 9;
const int stepperDirPin = 15;
const int stepperStepPin = 14; //11;
const int stepperResetPin = 10; //12;
const int stepperSleepPin = 16; //13;

int stepCount = 0;                                    // number of steps the motor has taken                                   
const int maxSteps = 20000;                           //Watchdog: helps shut down the motor in case the end contacts fail
const int StepperMotorSpeed = 10;


void setup()
{
  delay(2000);
  
  Serial.begin(9600); //comms to LED arduino controller
  Serial.println("Starting");
  delay(1000);
  InitializePins();
  InitializeStepper();

  
}

void loop()
{
  CheckVisorOpenCloseButton();
  CheckRotatorButton();
}

void InitializePins()
{
  //Sensor pins
  pinMode(visorClosedDetectionSwitch, INPUT_PULLUP);
  pinMode(visorOpenDetectionSwitch, INPUT_PULLUP);
  pinMode(rotatorRelayPin, OUTPUT);
  
  //Stepper Pins
  pinMode(stepperDirPin, OUTPUT);
  pinMode(stepperStepPin, OUTPUT);
  pinMode(stepperResetPin, OUTPUT);
  pinMode(stepperSleepPin, OUTPUT);
  
}




