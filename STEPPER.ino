
//DRV8825

long wait = 50;
long maxSteps = 80000;

void OpenVisor()
{
  
  if(DEV) Serial.println("Open Visor");
  
  if( digitalRead(visorOpenDetectionSwitch) == HIGH)
  {
    EnableStepper();
    
    //set direction
    digitalWrite(DIRECTION, HIGH);
  
    delay(1);//wait for direciton change in stepper controller
    
    long counterStepping = 0; 

    //ramp up
    MoveSteps( 10, wait*2);
    counterStepping += 10;

    while(counterStepping < maxSteps && digitalRead(visorOpenDetectionSwitch) == HIGH)
    {
      MoveSteps( 10, wait);
      counterStepping += 10;
    }
  
    DisableStepper();
    
    if(DEV) Serial.println("Open Visor Done ");
    if(DEV) Serial.print("Steps Taken: "); Serial.println(counterStepping); 
     
  }
  else
  {
    if(DEV) Serial.println("Open Visor End Switch already engaged. Aborting opening."); 
   }
  
}


void CloseVisor()
{

  if(DEV) Serial.println("Close Visor");

  if(digitalRead(visorCloseDetectionSwitch) == HIGH)
  {
    EnableStepper();
        
    //set direction
    digitalWrite(DIRECTION, LOW);
  
    delay(1);//wait for direciton change in stepper controller
  
    int counterStepping = 0;

    //ramp up
    MoveSteps( 10, wait*2);
    counterStepping += 10;
  
    while(counterStepping < maxSteps && digitalRead(visorCloseDetectionSwitch) == HIGH)
    {
      MoveSteps( 10, wait);
      counterStepping += 10;
    }

     //override switch to house properly 
     MoveSteps( 2000, wait);
     counterStepping += 2000;
  
    DisableStepper();
    if(DEV) Serial.println("Close Visor Done");
    if(DEV) Serial.print("Steps Taken: "); Serial.println(counterStepping); 
  
  }
  else
  {
    if(DEV) Serial.println("CLose Visor End Switch already engaged. Aborting opening."); 
  }
}



//old, doesnt take into account switches

void MoveStepperRamping(int steps)
{
  
  if((steps < 0 && digitalRead(visorCloseDetectionSwitch) == HIGH) || (steps > 0 && digitalRead(visorOpenDetectionSwitch) == HIGH) ) 
  {
    EnableStepper();
    
    if(DEV) Serial.print("Move Stepper ");
    if(DEV) Serial.println(steps);
    
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
  
    int rampMax =  wait*2;
    int ramp = rampMax;
    long stepsToTake = 0;
  
    int counterRamping = 0;
    int counterStepping = 0;
  
    while (ramp > wait)
    {
      MoveSteps( 10, ramp);
      ramp = ramp/1.05;
      counterRamping = counterRamping+10;
    }
  
    stepsToTake = steps - (counterRamping*2);
    while(counterStepping < stepsToTake )
    {
      MoveSteps( 10, wait);
      counterStepping = counterStepping+10;
    }
  
    while (ramp < rampMax)
    {
      MoveSteps( 10, ramp);
      ramp = ramp*1.05;
    }
  
    DisableStepper();
  }
}




//this doesnt work for fast stepping, must ramp
void MoveStepper(int steps)
{
  
  EnableStepper();
  
  if(DEV) Serial.print("Move Stepper ");
  if(DEV) Serial.println(steps);
  
  //set direciton
  if(steps < 0)
  {
    digitalWrite(DIRECTION, LOW);
    if(DEV) Serial.println("direciton Close");
  }
  else
  {
    digitalWrite(DIRECTION, HIGH);
    if(DEV) Serial.println("direciton Open");
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
  if(DEV) Serial.println("InitializeStepper");
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
 digitalWrite(M1, LOW);
 digitalWrite(M2, HIGH);

 //pullup the end swtiches for the stepper
 digitalWrite(visorCloseDetectionSwitch, HIGH);
 digitalWrite(visorOpenDetectionSwitch, HIGH);
 
}

