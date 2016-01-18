
void CheckLedProgramChange()
{
  if(UP == HIGH)
  {
    while(UP == HIGH){ReadButtons();}
    Serial.print(3);
  }
      
  if(DOWN == HIGH)
  {
    while(DOWN == HIGH){ReadButtons();}
    Serial.print(1);
  }
  
  if(LEFT == HIGH)
  {
    while(LEFT == HIGH){ReadButtons();}
    Serial.print(2);
  }
  
  if(RIGHT == HIGH)
  {
    while(RIGHT == HIGH){ReadButtons();}
    Serial.print(0);
  }
  }
