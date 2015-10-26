
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    int inByte = Serial.read();
    Serial.print("DataRecieved: "); Serial.println(inByte);
    inByte -= 48;
    Serial.print("DataModified: "); Serial.println(inByte);
     if(inByte == 0)
     {
        MoveStepper(19700);
       
     }
     //Custom - Toggle Rotator - This variable must be actioned against later
     if(inByte == 1)
     {
       MoveStepper(-19700);
     }

          //Custom - Toggle Rotator - This variable must be actioned against later
     if(inByte == 6)
     {
       MoveStepper(400);
     }
          if(inByte == 5)
     {
       MoveStepper(-400);
     }
     
  }
}
