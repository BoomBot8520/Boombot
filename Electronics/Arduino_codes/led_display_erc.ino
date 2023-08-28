const int segA1 = 23;
const int segB1 = 25;
const int segC1 = 27;
const int segD1 = 29;
const int segE1 = 31;
const int segF1 = 33;
const int segG1 = 35;
const int segA2 = 39;
const int segB2 = 41;
const int segC2 = 43;
const int segD2= 45;
const int segE2 = 47;
const int segF2 = 49;
const int segG2 = 51;

int input = 0;

void setup()
{
  pinMode(segA1, OUTPUT);
  pinMode(segB1, OUTPUT);
  pinMode(segC1, OUTPUT);
  pinMode(segD1, OUTPUT);
  pinMode(segE1, OUTPUT);
  pinMode(segF1, OUTPUT);
  pinMode(segG1, OUTPUT);
  pinMode(segA2, OUTPUT);
  pinMode(segB2, OUTPUT);
  pinMode(segC2, OUTPUT);
  pinMode(segD2, OUTPUT);
  pinMode(segE2, OUTPUT);
  pinMode(segF2, OUTPUT);
  pinMode(segG2, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Enter number to display: ");
}

int caseRun(int c)
{
  int ones,tens;
  ones=c%10;
  tens=c/10;
  if (tens == 0)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, HIGH);
    digitalWrite(segF1, HIGH);
    digitalWrite(segG1, LOW);
  }
  
  else if (tens ==1)
  {
    digitalWrite(segA1, LOW);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, LOW);
    digitalWrite(segE1, LOW);
    digitalWrite(segF1, LOW);
    digitalWrite(segG1, LOW);
  }
  
  else if (tens == 2)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, LOW);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, HIGH);
    digitalWrite(segF1, LOW);
    digitalWrite(segG1, HIGH);
  }
  
  else if (tens == 3)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, LOW);
    digitalWrite(segF1, LOW);
    digitalWrite(segG1, HIGH);
  }
  
  else if (tens == 4)
  {
    digitalWrite(segA1, LOW);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, LOW);
    digitalWrite(segE1, LOW);
    digitalWrite(segF1, HIGH);
    digitalWrite(segG1, HIGH);
  }
  
  else if (tens == 5)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, LOW);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, LOW);
    digitalWrite(segF1, HIGH);
    digitalWrite(segG1, HIGH);
  }
  
  else if (tens == 6)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, LOW);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, HIGH);
    digitalWrite(segF1, HIGH);
    digitalWrite(segG1, HIGH);
  }
  
  else if (tens == 7)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, LOW);
    digitalWrite(segE1, LOW);
    digitalWrite(segF1, LOW);
    digitalWrite(segG1, LOW);
  }
  
  else if (tens == 8)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, HIGH);
    digitalWrite(segF1, HIGH);
    digitalWrite(segG1, HIGH);
  }
  
  else if (tens == 9)
  {
    digitalWrite(segA1, HIGH);
    digitalWrite(segB1, HIGH);
    digitalWrite(segC1, HIGH);
    digitalWrite(segD1, HIGH);
    digitalWrite(segE1, LOW);
    digitalWrite(segF1, HIGH);
    digitalWrite(segG1, HIGH);
  }
  if (ones == 0)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, HIGH);
    digitalWrite(segF2, HIGH);
    digitalWrite(segG2, LOW);
  }
  
  else if (ones ==1)
  {
    digitalWrite(segA2, LOW);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, LOW);
    digitalWrite(segE2, LOW);
    digitalWrite(segF2, LOW);
    digitalWrite(segG2, LOW);
  }
  
  else if (ones == 2)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, LOW);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, HIGH);
    digitalWrite(segF2, LOW);
    digitalWrite(segG2, HIGH);
  }
  
  else if (ones == 3)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, LOW);
    digitalWrite(segF2, LOW);
    digitalWrite(segG2, HIGH);
  }
  
  else if (ones == 4)
  {
    digitalWrite(segA2, LOW);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, LOW);
    digitalWrite(segE2, LOW);
    digitalWrite(segF2, HIGH);
    digitalWrite(segG2, HIGH);
  }
  
  else if (ones == 5)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, LOW);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, LOW);
    digitalWrite(segF2, HIGH);
    digitalWrite(segG2, HIGH);
  }
  
  else if (ones == 6)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, LOW);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, HIGH);
    digitalWrite(segF2, HIGH);
    digitalWrite(segG2, HIGH);
  }
  
  else if (ones == 7)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, LOW);
    digitalWrite(segE2, LOW);
    digitalWrite(segF2, LOW);
    digitalWrite(segG2, LOW);
  }
  
  else if (ones == 8)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, HIGH);
    digitalWrite(segF2, HIGH);
    digitalWrite(segG2, HIGH);
  }
  
  else if (ones == 9)
  {
    digitalWrite(segA2, HIGH);
    digitalWrite(segB2, HIGH);
    digitalWrite(segC2, HIGH);
    digitalWrite(segD2, HIGH);
    digitalWrite(segE2, LOW);
    digitalWrite(segF2, HIGH);
    digitalWrite(segG2, HIGH);
  }
  return 0;
}


void loop()
{
  int count=analogRead(A3);
  caseRun(count); 
}
