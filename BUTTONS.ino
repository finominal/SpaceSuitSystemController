void ReadButtons() 
{
  if(analogRead(A1) <500) {DOWN = true;} else {DOWN = false;}
  if(analogRead(A2) <500) {RIGHT = true;} else {RIGHT = false;}
  if(analogRead(A0) <500) {UP = true;} else {UP = false;}
  if(analogRead(A3) <500) {A = true;} else  {A = false;}
  if(analogRead(A5) <500) {LEFT = true;} else  {LEFT = false;}
  if(analogRead(A4) <500) {B = true;} else  {B = false;}
}


void PrintButtons()
{
Serial.print("LEFT=");
  Serial.print(LEFT);
  Serial.print(" ");
  Serial.print("RIGHT=");
  Serial.print(RIGHT);
  Serial.print(" ");
  Serial.print("UP=");
  Serial.print(UP);
  Serial.print(" ");
  Serial.print("DOWN=");
  Serial.print(DOWN);
  Serial.print(" ");
  Serial.print("A=");
  Serial.print(A);
  Serial.print(" ");
  Serial.print("B=");
  Serial.print(B);
  Serial.println(" ");
}

