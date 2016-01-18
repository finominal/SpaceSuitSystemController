boolean rotatorOn = false; 
long nextRotatorToggleTime = 0;
int rotatorBrightness = BRIGHTNESS;



void CheckForRotatorToggle()
{
  
  if (B == true && nextRotatorToggleTime < millis() ) //if button pressed and its time to toggle
  {
    
    if(DEV) Serial.println("Rotator Button Press Detected");
    //rotatorOn = !rotatorOn; //flip state
    Serial.print(9);
    
    nextRotatorToggleTime = millis() + 1000; //set the next toggle time, stops flipping and helps debounce
  
    while(B == true) //wait for let go of buttons
    {
      ReadButtons();//read for change
    } 
    
  }

}
