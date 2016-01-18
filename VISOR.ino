
void PrintEndSwitches()
{
 Serial.print("VisorCloseEndSwitch="); Serial.println(digitalRead(visorCloseDetectionSwitch));
Serial.print("VisroOpenEndSwitch="); Serial.println(digitalRead(visorOpenDetectionSwitch));
Serial.println();
}


void CheckVisorOpenClose()
{
    if(A == true)
  {
    while(A == true){ ReadButtons();}//wait for release, helps debouncing
    MoveVisorWithEndSwitches();
   }
  }

//maybe
void MoveVisorWithEndSwitches()
{
  Serial.println("EnterisorOpenClose");
  
  //If the visor is somewhere in between open and closed, open it.
  if(digitalRead(visorCloseDetectionSwitch) == HIGH && digitalRead(visorOpenDetectionSwitch) == HIGH)
  {
    Serial.println("Call OpenVisorMid()");
    OpenVisor();
    
  }
  
  //If visor is detected as CLOSED, open it
  else if (digitalRead(visorCloseDetectionSwitch) == LOW)
  {
     Serial.println("Call OpenVisor()");
    OpenVisor();
  }
  
  //if visor is detected as OPEN, close it. 
  else if (digitalRead(visorOpenDetectionSwitch) == LOW)
  {
     Serial.println("Call Close()");
    CloseVisor();
  }
  Serial.println("ExitVisorOpenClose");
}



//This code has a dependancy on the stepper code. 
/*
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
*/
