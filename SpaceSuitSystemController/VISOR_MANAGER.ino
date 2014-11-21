
void CheckVisorOpenCloseButton()
{

  if(VisorButton() == HIGH)
  {
    while(VisorButton() == HIGH){;} //wait for button to be released, ensures nice solid presses.
    MoveVisor();
  }
  
}

void MoveVisor()
{
 
  //If the visor is somewhere in between open and closed, open it.
  if(digitalRead(visorClosedDetectionSwitch) == LOW && digitalRead(visorOpenDetectionSwitch) == LOW)
  {
    OpenVisor();
  }
  
  //If visor is detected as CLOSED, open it
  else if (digitalRead(visorClosedDetectionSwitch) == HIGH)
  {
    OpenVisor();
  }
  
  //if visor is detected as OPEN, close it. 
  else if (digitalRead(visorOpenDetectionSwitch) == HIGH)
  {
    CloseVisor();
  }
  
}

void OpenVisor()
{
  while(digitalRead(visorOpenDetectionSwitch) == LOW)
  {
    MoveStepper(-1);
    // ? Do we need to set a timer here, or will the stepper motor speed take care of that? 
  }
  MoveStepper(-10); //once contact switch is triggered, move a little further so that the contact switch is definately closed.
}



void CloseVisor()
{

  while(digitalRead(visorClosedDetectionSwitch) == LOW)
  {
    MoveStepper(1);
  }
  MoveStepper(-10); //once contact switch is triggered, move a little further so that the contact switch is definately closed.
}

