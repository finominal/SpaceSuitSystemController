
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    int inByte = Serial.read();
    Serial.print("DataRecieved: "); Serial.println(inByte);
    inByte -= 48;
    Serial.print("DataModified: "); Serial.println(inByte);
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
     if(inByte == 6 && digitalRead(visorCloseDetectionSwitch) == 1)
     {
       MoveStepperRamping(400);
     }
     if(inByte == 5 && digitalRead(visorOpenDetectionSwitch) == 1)
     {
       MoveStepperRamping(-400);
     }
     
  }
}
