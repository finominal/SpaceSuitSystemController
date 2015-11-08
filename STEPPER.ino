
//DRV8825

long wait = 250;
long maxSteps = 5000;


void OpenVisor()
{
  EnableStepper();
  
  Serial.print("Open Visor ");
  
  //set direciton for open
  digitalWrite(DIRECTION, HIGH);

  delay(1);//wait for direciton change in stepper controller

  int rampMax =  wait*20;
  int ramp = rampMax;
  long stepsToTake = 0;

  int counterRamping = 0;
  int counterStepping = 0;

  if( visorOpenDetectionSwitch == HIGH)
  {
    
    while (ramp > wait)
    {
      MoveSteps( 10, ramp);
      ramp = ramp/1.4;
      counterRamping = counterRamping+10;
    }

    stepsToTake = maxSteps - (counterRamping*2);
  
    while(counterStepping < stepsToTake && visorOpenDetectionSwitch == HIGH)
    {
      MoveSteps( 10, wait);
      counterStepping = counterStepping+10;
    }

    while (ramp < rampMax)
    {
      MoveSteps( 10, ramp);
      ramp = ramp*1.4;
    }
  }
  DisableStepper();
}

void CloseVisor()
{
  
  EnableStepper();
  
  Serial.print("Close Visor");

  
  //set direction
  digitalWrite(DIRECTION, LOW);

  delay(1);//wait for direciton change in stepper controller

  int rampMax =  wait*20;
  int ramp = rampMax;
  long stepsToTake = 0;

  int counterRamping = 0;
  int counterStepping = 0;

  while (ramp > wait)
  {
    MoveSteps( 10, ramp);
    ramp = ramp/1.4;
    counterRamping = counterRamping+10;
  }

  stepsToTake = maxSteps - (counterRamping*2);
  
  while(counterStepping < stepsToTake && visorCloseDetectionSwitch == HIGH)
  {
    MoveSteps( 10, wait);
    counterStepping = counterStepping+10;
  }

  while (ramp < rampMax)
  {
    MoveSteps( 10, ramp);
    ramp = ramp*1.4;
  }

  DisableStepper();
}



//old, doesnt take into account switches

void MoveStepperRamping(int steps)
{
  
  EnableStepper();
  
  Serial.print("Move Stepper ");
  Serial.println(steps);
  
  //set direciton
  if(steps < 0)
  {
    digitalWrite(DIRECTION, LOW);
  }
  else
  {
    digitalWrite(DIRECTION, HIGH);
  }

  delay(1);//wait for direciton change in stepper controller

  int rampMax =  wait*20;
  int ramp = rampMax;
  long stepsToTake = 0;

  int counterRamping = 0;
  int counterStepping = 0;

  while (ramp > wait)
  {
    MoveSteps( 10, ramp);
    ramp = ramp/1.4;
    counterRamping = counterRamping+10;
  }

  stepsToTake = maxSteps - (counterRamping*2);
  while(counterStepping < stepsToTake )
  {
    MoveSteps( 10, wait);
    counterStepping = counterStepping+10;
  }

  while (ramp < rampMax)
  {
    MoveSteps( 10, ramp);
    ramp = ramp*1.4;
  }

  DisableStepper();
}




//this doesnt work for fast stepping, must ramp
void MoveStepper(int steps)
{
  
  EnableStepper();
  
  Serial.print("Move Stepper ");
  Serial.println(steps);
  
  //set direciton
  if(steps < 0)
  {
    digitalWrite(DIRECTION, LOW);
    Serial.println("direciton Close");
  }
  else
  {
    digitalWrite(DIRECTION, HIGH);
    Serial.println("direciton Open");
  }

  delay(1);//wait for direciton change in stepper controller

  long stepsMoved = 0;
  while(stepsMoved < abs(steps))
  {
    MoveSteps(400, wait);
    steps--;
  }

  DisableStepper();
}


//this doesnt work for fast stepping, must ramp
void MoveSteps(int _steps, int _wait)

 {
    int moved = 0;

    while(moved < _steps )
    {
      //Serial.println("Stepping");
      digitalWrite(STEP, HIGH);
      //delayMicroseconds(wait);
      digitalWrite(STEP, LOW);
      delayMicroseconds(_wait);
      moved++;
    }
 }

 
void EnableStepper()
{
  digitalWrite(ENABLE, LOW);
}


void DisableStepper()
{
  digitalWrite(ENABLE, HIGH);
}

void InitializeStepper()
{
   //stepperPins
 pinMode(DIRECTION, OUTPUT);
 pinMode(STEP, OUTPUT);
 pinMode(SLEEP, OUTPUT);
 pinMode(RESET, OUTPUT);
 pinMode(ENABLE, OUTPUT);
 pinMode(M0, OUTPUT);
 pinMode(M1, OUTPUT);
 pinMode(M2, OUTPUT);
 pinMode(visorCloseDetectionSwitch, INPUT);
 pinMode(visorOpenDetectionSwitch, INPUT);
 
 digitalWrite(DIRECTION, LOW);
 digitalWrite(STEP, HIGH);
 digitalWrite(SLEEP, HIGH);
 digitalWrite(RESET, HIGH);
 digitalWrite(ENABLE, HIGH);
 
 digitalWrite(M0, LOW);
 digitalWrite(M1, HIGH);
 digitalWrite(M2, LOW);
 
 digitalWrite(visorCloseDetectionSwitch, HIGH);
 digitalWrite(visorOpenDetectionSwitch, HIGH);
 
}

