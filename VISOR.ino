
void ReadEndSwitches()
{
 Serial.print("VisorCloseEndSwitch="); Serial.println(digitalRead(visorCloseDetectionSwitch));
Serial.print("VisroOpenEndSwitch="); Serial.println(digitalRead(visorOpenDetectionSwitch));
Serial.println();
}


//maybe
void MoveVisorWithEndSwitches()
{
 
  //If the visor is somewhere in between open and closed, open it.
  if(visorCloseDetectionSwitch == LOW and visorOpenDetectionSwitch == LOW)
  {
    OpenVisor();
  }
  
  //If visor is detected as CLOSED, open it
  else if (visorCloseDetectionSwitch == HIGH)
  {
    OpenVisor();
  }
  
  //if visor is detected as OPEN, close it. 
  else if (visorOpenDetectionSwitch == HIGH)
  {
    CloseVisor();
  }
  
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
