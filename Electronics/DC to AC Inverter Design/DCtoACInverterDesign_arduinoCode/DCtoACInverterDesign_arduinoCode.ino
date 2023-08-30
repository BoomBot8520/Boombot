//IMPORTANT
//Circuit runs on the principle of MOSFET H-Bridge inverter.
//The circuit runs on four MOSFETS - 2 PMOS, and 2 NMOS.
//PMOS pulls up the current through the drain and NMOS pulls down through the source.
//MOSFETS are operated alternatingly to induce polarity change in each cycle
//Self-working circuit, with no input required.
//Frequency of the signal can be altered by changing the delay time in the code between MOSFET switching.
//Oscilloscope provides real-time output voltage form.


//CONSTANTS
int pmos1 = 10;
int nmos1 = 9;
int pmos2 = 11;
int nmos2 = 6;

void setup()
{
  pinMode(pmos1, OUTPUT);
  pinMode(pmos2, OUTPUT);
  pinMode(nmos1, OUTPUT);
  pinMode(nmos2, OUTPUT);
  
  digitalWrite(pmos1, LOW);
  digitalWrite(pmos2, LOW);
  digitalWrite(nmos1, LOW);
  digitalWrite(nmos2, LOW); //start with all MOSFETS closed (0 gate voltage)
}

void loop()
{
  digitalWrite(pmos1, HIGH);
  digitalWrite(nmos2, HIGH);
  delay(30);              //turns on the first pair
  
  digitalWrite(pmos1, LOW);
  digitalWrite(nmos2, LOW);
  delay(30);              //turns off the first pair
  
  digitalWrite(pmos2, HIGH);
  digitalWrite(nmos1, HIGH);
  delay(30);              //turns on the second pair
  
  digitalWrite(pmos2, LOW);
  digitalWrite(nmos1, LOW);
  delay(30);              //turns off the second pair
}