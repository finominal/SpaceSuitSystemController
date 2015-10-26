//#include <Stepper.h>

const int stepsPerRevolution = 200;                    // change this to fit the number of steps per revolution for you motor
//Stepper myStepper(stepsPerRevolution, 10,11,12,13);     // initialize the stepper library on pins 8 through 11:                                 


boolean UP, DOWN, LEFT, RIGHT, A, B;

boolean rotatorOn = false;

const int rotatorPin = 4;

//define Sensor Switch Pins 
const int visorClosedDetectionSwitch = 2;
const int visorOpenDetectionSwitch = 3;


//define stepper communication pins
#define M0 5
#define M1 6
#define M2 7
#define ENABLE 8
#define RESET 9
#define SLEEP 10
#define STEP 11
#define DIRECTION 12



void setup()
{
  Serial.begin(9600); //comms to LED arduino controller
  InitializeStepper();
  //MoveStepper(4900);

}



void loop()
{
  //ReadButtons();
  //MoveVisor();
 SerialMoveVisor();
}

void SerialMoveVisor()
{
 serialEvent() ;
  
}

void PrintButtons()
{
Serial.print("LEFT=");
  Serial.print(LEFT);
  Serial.print(" ");
  Serial.print("RIGHT=");
  Serial.print(RIGHT);
  Serial.print(" ");
  Serial.print("UP=");
  Serial.print(UP);
  Serial.print(" ");
  Serial.print("DOWN=");
  Serial.print(DOWN);
  Serial.print(" ");
  Serial.print("A=");
  Serial.print(A);
  Serial.print(" ");
  Serial.print("B=");
  Serial.print(B);
  Serial.println(" ");
}



void ReadButtons()
{
  if(analogRead(A1) >500) {LEFT = true;} else {LEFT = false;}
  if(analogRead(A2) >500) {RIGHT = true;} else {RIGHT = false;}
  if(analogRead(A0) >500) {DOWN = true;} else {DOWN = false;}
  if(analogRead(A3) >500) {UP = true;} else  {UP = false;}
  if(analogRead(A5) >500) {A = true;} else  {A = false;}
  if(analogRead(A4) >500) {B = true;} else  {B = false;}
}




//This code has a dependancy on the stepper code. 

void MoveVisor()
{
  if(UP == true)
  {
    while(UP == true) //wait for button to be released, helps stop looping
    {
      MoveStepper(100);
      ReadButtons();
    }    
  }
  else if(DOWN == true)
  {
    while(DOWN == true) //wait for button to be released, helps stop looping
    {
      MoveStepper(-100);
      ReadButtons();
    }
  }
}



void MoveVisorWithEndSwitches()
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
    MoveStepper(100);
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






