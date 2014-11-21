
/*
#define DPAD_UP A0; 
#define DPAD_DOWN A1; 
#define DPAD_LEFT A2; 
#define DPAD_RIGHT A3; 
#define DPAD_A A4; 
#define DPAD_B A5; 
#define DPAD_START A6; 
#define DPAD_SELECT A7; 
*/

int VisorButton()
{
 return  DPad_A_State();
}

int RotatorButton()
{
  return DPad_B_State();
}


int DPad_A_State()
{
  return digitalRead(A4);
}

int DPad_B_State()
{
  return digitalRead(A5);
}

