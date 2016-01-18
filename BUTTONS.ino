void ReadButtons() 
{
  if(analogRead(A1) <700) {DOWN = false;} else {DOWN = true;}
  if(analogRead(A2) <700) {RIGHT = false;} else {RIGHT = true;}
  if(analogRead(A0) <700) {UP = false;} else {UP = true;}
  if(analogRead(A3) <700) {A = false;} else  {A = true;}
  if(analogRead(A5) <700) {LEFT = false;} else  {LEFT = true;}
  if(analogRead(A4) <700) {B = false;} else  {B = true;}
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



void PrintAnalogPorts()
{
  Serial.print("A0=");
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print("A1=");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print("A2=");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print("A3=");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print("A4=");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.print("A5=");
  Serial.print(analogRead(A5));
  Serial.print(" ");
  Serial.print("A6=");
  Serial.print(analogRead(A6));
  Serial.print(" ");
  Serial.print("A7=");
  Serial.println(analogRead(A7));
}
