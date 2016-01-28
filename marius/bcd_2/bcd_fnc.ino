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
const int Number = 0;
void setup() //Enters the setup phase
{
  pinMode(Bin1, OUTPUT); // sets up binary output one as a digital output
  pinMode(Bin2, OUTPUT); //and so on...
  pinMode(Bin3, OUTPUT);
  pinMode(Bin4, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(GND, B0); 
  digitalWrite(VCC, B1);

  digitalWrite(44, B0); 
  digitalWrite(46, B0);
  digitalWrite(48, B0); 
  digitalWrite(50, B0);
}

void loop() // Pretty much just saying "loop whatever code is after this line"
{
  

  switch(Number) {

   case 0  :
      digitalWrite(Bin1, B0); //Write "0" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
	
   case 1  :
      digitalWrite(Bin1, B1); //Write "1" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
      
   case 2  :
      digitalWrite(Bin1, B0); //Write "2" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
	
   case 3  :
      digitalWrite(Bin1, B1); //Write "3" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
   
   case 4  :
      digitalWrite(Bin1, B0); //Write "4" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
   case 5  :
      digitalWrite(Bin1, B1); //Write "5" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
   
   case 6  :
      digitalWrite(Bin1, B0); //Write "6" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
	
   case 7  :
      digitalWrite(Bin1, B1); //Write "7" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
   
   case 8  :
      digitalWrite(Bin1, B0); //Write "8" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B1);
      break;
	
   case 9  :
      digitalWrite(Bin1, B1); //Write "9" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B1);
      break;
      
   default :
}


}

writeBCD(int ID, int Digit){
   
   const int Bin1 = 44; //These are all identifying the binary inputs of
   const int Bin2 = 46; //the 4511 Seven Segment Decoder
   const int Bin3 = 48;
   const int Bin4 = 50;
   
   Serial.println(Digit);
   
   switch(ID){
   case 0   :
      break;
   case 1   :
      Bin1 = 45;
      Bin2 = 47; 
      Bin3 = 49;
      Bin4 = 51;
      break
   default:
}

   switch(Digit) {

   case 0  :
      digitalWrite(Bin1, B0); //Write "0" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
	
   case 1  :
      digitalWrite(Bin1, B1); //Write "1" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
      
   case 2  :
      digitalWrite(Bin1, B0); //Write "2" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
	
   case 3  :
      digitalWrite(Bin1, B1); //Write "3" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B0);
      break;
   
   case 4  :
      digitalWrite(Bin1, B0); //Write "4" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
   case 5  :
      digitalWrite(Bin1, B1); //Write "5" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
   
   case 6  :
      digitalWrite(Bin1, B0); //Write "6" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
	
   case 7  :
      digitalWrite(Bin1, B1); //Write "7" to the display
      digitalWrite(Bin2, B1);
      digitalWrite(Bin3, B1);
      digitalWrite(Bin4, B0);
      break;
   
   case 8  :
      digitalWrite(Bin1, B0); //Write "8" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B1);
      break;
	
   case 9  :
      digitalWrite(Bin1, B1); //Write "9" to the display
      digitalWrite(Bin2, B0);
      digitalWrite(Bin3, B0);
      digitalWrite(Bin4, B1);
      break;
      
   default :
   
}

writeFrequencyBCD(int Value){
   int Digit1 = 0;
   int Digit0 = 0;
   
   Digit1 = Value \ 10;
   Digit0 = Value mod 10; 
   
   writeBCD(0, Digit0);
   writeBCD(1, Digit1);
   

}