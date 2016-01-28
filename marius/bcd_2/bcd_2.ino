const int Bin1 = 44; //These are all identifying the binary inputs of
const int Bin2 = 46; //the 4511 Seven Segment Decoder
const int Bin3 = 48;
const int Bin4 = 50;

/*const int bin1 = 44; //These are all identifying the binary inputs of
const int bin2 = 46; //the 4511 Seven Segment Decoder
const int bin3 = 48;
const int bin4 = 50;
*/

const int GND = 52;
const int VCC = 53;

void setup() //Enters the setup phase
{
  pinMode(Bin1, OUTPUT); // sets up binary output one as a digital output
  pinMode(Bin2, OUTPUT); //and so on...
  pinMode(Bin3, OUTPUT);
  pinMode(Bin4, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);

  digitalWrite(GND, B0); 
  digitalWrite(VCC, B1);

  digitalWrite(44, B0); 
  digitalWrite(46, B0);
  digitalWrite(48, B0); 
  digitalWrite(50, B0);
}

void loop() // Pretty much just saying "loop whatever code is after this line"
{
  
  digitalWrite(Bin1, B0); //Write "0" to the display
  digitalWrite(Bin2, B0);
  digitalWrite(Bin3, B0);
  digitalWrite(Bin4, B0);
  delay(500);
  digitalWrite(Bin1, B1); //Write "1" to the display
  digitalWrite(Bin2, B0);
  digitalWrite(Bin3, B0);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second (or else the numbers would be a blur)
  digitalWrite(Bin1, B0); //Write "2" to the display
  digitalWrite(Bin2, B1);
  digitalWrite(Bin3, B0);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B1); //Write "3" to the display
  digitalWrite(Bin2, B1);
  digitalWrite(Bin3, B0);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B0); //Write "4" to the display
  digitalWrite(Bin2, B0);
  digitalWrite(Bin3, B1);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B1); //Write "5" to the display
  digitalWrite(Bin2, B0);
  digitalWrite(Bin3, B1);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B0); //Write "6" to the display
  digitalWrite(Bin2, B1);
  digitalWrite(Bin3, B1);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B1); //Write "7" to the display
  digitalWrite(Bin2, B1);
  digitalWrite(Bin3, B1);
  digitalWrite(Bin4, B0);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B0); //Write "8" to the display
  digitalWrite(Bin2, B0);
  digitalWrite(Bin3, B0);
  digitalWrite(Bin4, B1);
  delay(500); //Wait for half of a second
  digitalWrite(Bin1, B1); //Write "9" to the display
  digitalWrite(Bin2, B0);
  digitalWrite(Bin3, B0);
  digitalWrite(Bin4, B1);
  delay(500); //Wait for half of a second
}
