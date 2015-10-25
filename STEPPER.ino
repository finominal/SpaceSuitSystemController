
//DRV8825

int waitMicroSeconds = 1000;

void MoveStepper(int steps)
{

   EnableStepper();
  
  Serial.print("Move Stepper ");
  Serial.println(steps);
  
  //set direciton
  if(steps <0)
  {
    digitalWrite(DIRECTION, LOW);
  }
  else
  {
    digitalWrite(DIRECTION, HIGH);
  }
  
    delay(1);//wait for direciton change in stepper controller
 
    int moved = 0;
    while(moved < abs(steps) )
    {
      //Serial.println("Stepping");
      pinMode(STEP, HIGH);
      delayMicroseconds(waitMicroSeconds);
      pinMode(STEP, LOW);
      delayMicroseconds(waitMicroSeconds);
      
      moved++;
    }
    
    DisableStepper();
    
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
 
 digitalWrite(DIRECTION, LOW);
 digitalWrite(STEP, LOW);
 digitalWrite(SLEEP, HIGH);
  digitalWrite(RESET, HIGH);
  digitalWrite(ENABLE, HIGH);
}

