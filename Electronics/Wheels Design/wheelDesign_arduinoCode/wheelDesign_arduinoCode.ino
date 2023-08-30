//IMPORTANT
//Enter the linear speed between 0 and 60 cm/s
//Enter the angular velocity between -72 and 72 rad/min
//Negative angular velocity turns to the left, and positive angular velocity turns to the right
//All speeds are constrained
//Calculations are theoretical, and does not include unaccounted forces such as friction, stability of the bot,
//and other natural factors.

#include <math.h>


//CONSTANTS
int motorPin1 = 5;
int motorPin2 = 11;
int motorPin3 = 3;
int motorPin4 = 10;
int radius = 5;	//in cm
int speed = 0;
int angVel = 0;	//in rad/min; constrained between 0 and 72 rad/min
float radFactor = 0;
int flag = 0;
int Lspeed = 0;	//speed of left side wheels
int Rspeed = 0;	//speed of right side wheels

const int wheelDis = 50;	//in cm

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter linear speed between 0 and 60 cm/s.");
  Serial.println("Enter angular speed between -72 and 72 rad/min.");
}

void loop()
{
  Serial.print("Enter the linear speed: ");
  while (Serial.available() == 0)
  {}
  speed = Serial.parseInt();	//enter in cm/s
  Serial.println(speed);
  speed = constrain(speed, 0, 60);	//constrains the speed
  speed = map(speed, 0, 60, 0, 255);	//taken from motor rpm
  Lspeed = speed;
  Rspeed = speed;
                          
                          
  Serial.print("Enter the angular velocity: ");
  while (Serial.available() == 0){}
  angVel = Serial.parseInt();
  Serial.println(angVel);
  
  if (angVel < 0)		//turning left
  {
    angVel *= (-1);
    angVel = constrain(angVel, 0, 72);
    radFactor = map(angVel, 0, 72, 0, 36);
    Lspeed -= radFactor;
    Rspeed += radFactor;
    if (Rspeed >= 255)
    {
      Rspeed = 255;
      Lspeed = 255 - (2*radFactor);
    }
    if (Lspeed <= 0)
    {
      Lspeed = 0;
      Rspeed = 255 + (2*radFactor);
    }
  }
  
  if (angVel > 0)		//turning right
  {
    angVel = constrain(angVel, 0, 72);
    radFactor = map(angVel, 0, 72, 0, 25);
    Lspeed += radFactor;
    Rspeed -= radFactor;
    if (Rspeed < 0)
    {
      Rspeed = 0;
      Lspeed = 255 + (2*radFactor);
    }
    if (Lspeed > 255)
    {
      Lspeed = 255;
      Rspeed = 255 - (2*radFactor);
    }
  }

  if (speed == 0)
  {analogWrite(motorPin1, 0);
   analogWrite(motorPin2, 0);
   analogWrite(motorPin3, 0);
   analogWrite(motorPin4, 0);
  }
  
  else if (speed > 0)
  {
      for (int i = 0; i <= floor(Lspeed); i++)
	  {
       analogWrite(motorPin1, i);
       analogWrite(motorPin3, i);
       delay(10);
      }			//115rpm corresponds to 12 rad/s
      for (int i = 0; i <= floor(Rspeed); i++)
	  {
       analogWrite(motorPin2, i);
       analogWrite(motorPin4, i);
       delay(10);
      }	
  }
}
