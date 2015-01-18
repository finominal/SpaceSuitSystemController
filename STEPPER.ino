


int waitMs = 800;

void MoveStepper(int steps)
{
  //set direciton
  if(steps <0)
  {
    digitalWrite(DIRECTION, LOW);
    delay(1);
    
    int moved = 0;
    while(moved < abs(steps) && visorOpenDetectionSwitch == LOW)
    {
      pinMode(STEP, HIGH);
      delay(waitMs);
      pinMode(STEP, LOW);
      delay(waitMs);
      
      moved++;
    }
  }
  else
  {
    digitalWrite(DIRECTION, HIGH);
    delay(1);
    
    int moved = 0;
    while(moved < abs(steps) && visorClosedDetectionSwitch == LOW)
    {
      pinMode(STEP, HIGH);
      delay(waitMs);
      pinMode(STEP, LOW);
      delay(waitMs);
      
      moved++;
    }
  }
}


void InitializeStepper()
{
   //stepperPins
 pinMode(ENABLE, OUTPUT);
 pinMode(RESET, OUTPUT);
 pinMode(SLEEP, OUTPUT);
 pinMode(STEP, OUTPUT);
 pinMode(DIRECTION, OUTPUT);
 
 digitalWrite(ENABLE, LOW);
 digitalWrite(RESET, LOW);
 digitalWrite(SLEEP, LOW);
  digitalWrite(STEP, LOW);
  digitalWrite(STEP, LOW);
}

