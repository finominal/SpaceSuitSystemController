void CheckRotatorButton()
{
    if(RotatorButton() == HIGH)
  {
    while(RotatorButton() == HIGH){;} //wait for button to be released, ensures nice solid presses.
  }
  
  //Toggle the relay
  digitalWrite(rotatorRelayPin, !digitalRead(rotatorRelayPin));
}
