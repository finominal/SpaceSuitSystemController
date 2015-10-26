
//DRV8825

long wait = 250;

void MoveStepper(int steps)
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

/*
  //ramp up and down
  MoveSteps( 30, wait*12);
  MoveSteps( 30, wait*10);
  MoveSteps( 30, wait*8);
  MoveSteps( 30, wait*6);
  MoveSteps( 30, wait*4);
  MoveSteps( 20, wait*2);
  MoveSteps( 20, wait*1.5);
  MoveSteps( abs(steps)-380, wait);
  MoveSteps( 20, wait*1.5);
  MoveSteps( 20, wait*2);
  MoveSteps( 30, wait*4);
  MoveSteps( 30, wait*6);
  MoveSteps( 30, wait*8);
  MoveSteps( 30, wait*10);
  MoveSteps( 30, wait*12);
  */

  int rampMax =  wait*20;
  int ramp = rampMax;
  long stepsToTake = 0;

  int cr = 0;
  int cs = 0;

  while (ramp > wait)
  {
    MoveSteps( 10, ramp);
    ramp = ramp/1.4;
    cr = cr+10;
  }

stepsToTake = abs(steps) - (cr*2);
  while(cs < stepsToTake)
  {
    MoveSteps( 10, wait);
    cs = cs+10;
  }

  while (ramp < rampMax)
  {
    MoveSteps( 10, ramp);
    ramp = ramp*1.4;
  }

  
  DisableStepper();
}

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
 
 digitalWrite(DIRECTION, LOW);
 digitalWrite(STEP, HIGH);
 digitalWrite(SLEEP, HIGH);
 digitalWrite(RESET, HIGH);
 digitalWrite(ENABLE, HIGH);
 digitalWrite(M0, LOW);
 digitalWrite(M1, HIGH);
 digitalWrite(M2, LOW);
}

