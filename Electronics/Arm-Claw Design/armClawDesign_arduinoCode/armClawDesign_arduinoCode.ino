//Do not connect Servo power to over 6V
//Connect Servo motor to Arduino 5V power
//RAIL POWER : 5V
//9V POWER for DC Motor
//claw rotation motor is unidirectional


//IMPORTANT !!!
//Enter 01 to start the spin motor.
//Enter 00 to stop the spin motor
//Enter 11 to lower the Servo1 claw
//Enter 10 to extract the Servo1 claw
//Enter 21 to lower the Servo2 arm
//Enter 20 to extract the Servo2 arm


#include <Servo.h>

Servo servo1;
Servo servo2;

int spinmotorPin = 4;
int spinNumber = 0;
int servoPos1 = 0;
int servoPos2 = 0;

void setup()
{
  servo1.attach(6);
  servo2.attach(9);
  pinMode(spinmotorPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter 01 to start the spin motor.");
  Serial.println("Enter 00 to stop the spin motor.");
  Serial.println("Enter 11 to lower the Servo1 claw.");
  Serial.println("Enter 10 to extract the Servo1 claw.");
  Serial.println("Enter 21 to lower the Servo2 arm.");
  Serial.println("Enter 20 to extract the Servo2 arm.");
  
  servo1.write(servoPos1);
  servo2.write(servoPos2);
}

void loop()
{
  while (Serial.available() == 0)
  {}
  
  spinNumber = Serial.parseInt();
  Serial.println(spinNumber);
  
  if (spinNumber == 1)
  {
    if (digitalRead(spinmotorPin) == 0)
    {
     for (int i = 0; i <= 150; i++)
   	 	{
    	  analogWrite(spinmotorPin, i);
      	  delay(10);
    	} 
    }
  }
  
  else if (spinNumber == 0)
  {
    if (digitalRead(spinmotorPin) == 0)
    {}
    else
    {
      for (int i = 150; i >= 0; i--)
      {
        analogWrite(spinmotorPin, i);
        delay(10);
      }
    }
  }
  
  else if (spinNumber == 11)
  {
    if (servoPos1 != 180)
    {
      servoPos1 += 20;
      servo1.write(servoPos1);
    }
  }
  
  else if (spinNumber == 10)
  {
    if (servoPos1 != 0)
    {
      servoPos1 -= 20;
      servo1.write(servoPos1);
    }
  }
  else if (spinNumber == 21)
  {
    if (servoPos2 != 180)
    {
      servoPos2 += 20;
      servo2.write(servoPos2);
    }
  }
  
  else if (spinNumber == 20)
  {
    if (servoPos2 != 0)
    {
      servoPos2 -= 20;
      servo2.write(servoPos2);
    }
  }
}
