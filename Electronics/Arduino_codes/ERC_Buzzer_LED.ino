#include <stdio.h>
#include <stdbool.h>
const int detectorPin = A0;
const int red = 6;
const int green = 3;
const int blue = 5;
const int buzzer=8;
bool flag=false;
const int Digging=7;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(Digging,INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(detectorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(detectorPin), detect, CHANGE);
  Serial.begin(9600);
}
void detect()
{
  if (digitalRead(Digging)==0)
  {
    flag=true;
    noTone(buzzer);
    int signal=analogRead(detectorPin);
    int d=map(signal,0,1,0,2);//Need to dtermine ranges experimentally
    if (d>3)
      {
      analogWrite(red,255);
      analogWrite(green,255);
      tone(buzzer,600);
      delay(600);
      noTone(buzzer);
      delay(1000);
      }
    else if (0.5<d<3)//depends on height of robot from ground
    {
      analogWrite(red,255);
      analogWrite(green,150);
      tone(buzzer,600);
      delay(500);
      noTone(buzzer);
      delay(500);
    }
    else
    {analogWrite(red,255);
      tone(buzzer,600);
      detect();
    }
    flag=false;}
}
void loop() 
{
  if (digitalRead(Digging)==0)
  {
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    if (flag==false)
      {
      analogWrite(green,255);
      tone(buzzer,600);
      delay(1000);
      noTone(buzzer);
      delay(2000);
      }
  }
  else
    {
      noTone(buzzer);
      digitalWrite(red,LOW);
      digitalWrite(green,LOW);
      digitalWrite(blue,HIGH);
    }
}
