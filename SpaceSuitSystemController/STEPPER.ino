


void InitializeStepper(int motorSpeed)
{
  myStepper.setSpeed(motorSpeed);
}


void MoveStepper(int movement)
{
 myStepper.step(movement);
}



