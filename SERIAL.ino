
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    int inByte = Serial.read();
    if(DEV) Serial.print("DataRecieved: "); Serial.println(inByte);
    inByte -= 48;
    if(DEV) Serial.print("DataModified: "); Serial.println(inByte);
     if(inByte == 0)
     {
       OpenVisor();
     }
     //Custom - Toggle Rotator - This variable must be actioned against later
     if(inByte == 1)
     {
        CloseVisor();
     }

          //Custom - Toggle Rotator - This variable must be actioned against later
     if(inByte == 6)
     {
       MoveStepperRamping(1000);
     }
     
     if(inByte == 5 )
     {
       MoveStepperRamping(-1000);
     }
     
  }
}
