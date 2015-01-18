

 void  InitializeStepper()
 {
 //Set Stepper Reset pin for normal operations
  digitalWrite(stepperResetPin, HIGH);
  
  //Put the Stepper Driver into Sleep Mode
  digitalWrite(stepperSleepPin, LOW);
 }


void MoveStepper(boolean dir,int steps){
  
  //Wake up the Stepper Driver from sleep
  digitalWrite(stepperSleepPin, HIGH);
  delay(1);
  
  //Set the Direcion
  digitalWrite(stepperDirPin,dir); 
  delay(1);
  
  cli();
 
  //Toggle the stepper pin for each step
  for(int i=0;i<steps;i++)
  {
    digitalWrite(stepperStepPin, HIGH);
    delayMicroseconds(600);//Speed Controlled Here
  
    digitalWrite(stepperStepPin, LOW);
    delayMicroseconds(600); //Speed Controlled here
  }
  
  sei();
  
  //Put the Stepper Driver back to sleep, saves power and heat.
  digitalWrite(stepperSleepPin, LOW);
  delay(50);
}


