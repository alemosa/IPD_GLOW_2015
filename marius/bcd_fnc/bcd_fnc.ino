const int Bin1 = 44; //These are all identifying the binary inputs of
const int Bin2 = 46; //the 4511 Seven Segment Decoder
const int Bin3 = 48;
const int Bin4 = 50;
const int Bin5 = 45; //These are all identifying the binary inputs of
const int Bin6 = 47; //the 4511 Seven Segment Decoder
const int Bin7 = 49;
const int Bin8 = 51;

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
  pinMode(Bin5, OUTPUT); // sets up binary output one as a digital output
  pinMode(Bin6, OUTPUT); //and so on...
  pinMode(Bin7, OUTPUT);
  pinMode(Bin8, OUTPUT);
  
  pinMode(GND, OUTPUT);
  pinMode(VCC, OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(GND, LOW); 
  digitalWrite(VCC, HIGH);


}

void loop() // Pretty much just saying "loop whatever code is after this line"
{
  writeFrequencyBCD(59);
  
  //delay(2000);
//  writeFrequencyBCD(12);
//  delay(2000);
//  writeFrequencyBCD(34);
//  delay(2000);
//  writeFrequencyBCD(56);
//  delay(2000);
//  writeFrequencyBCD(78);
//  delay(2000);
//  writeFrequencyBCD(90);
//  delay(2000);

 
}




void writeBCD(int ID, int Digit){
   
   int Bin1 = 44; //These are all identifying the binary inputs of
   int Bin2 = 46; //the 4511 Seven Segment Decoder
   int Bin3 = 48;
   int Bin4 = 50;
   
   Serial.println(Digit);
   
   switch(ID){
   case 0   :
      break;
   case 1   :
      Bin1 = 45;
      Bin2 = 47; 
      Bin3 = 49;
      Bin4 = 51;
      break;

   }

   switch(Digit) {

   case 0  :
      digitalWrite(Bin1, LOW); //Write "0" to the display
      digitalWrite(Bin2, LOW);
      digitalWrite(Bin3, LOW);
      digitalWrite(Bin4, LOW);
      break;
	
   case 1  :
      digitalWrite(Bin1, HIGH); //Write "1" to the display
      digitalWrite(Bin2, LOW);
      digitalWrite(Bin3, LOW);
      digitalWrite(Bin4, LOW);
      break;
      
   case 2  :
      digitalWrite(Bin1, LOW); //Write "2" to the display
      digitalWrite(Bin2, HIGH);
      digitalWrite(Bin3, LOW);
      digitalWrite(Bin4, LOW);
      break;
	
   case 3  :
      digitalWrite(Bin1, HIGH); //Write "3" to the display
      digitalWrite(Bin2, HIGH);
      digitalWrite(Bin3, LOW);
      digitalWrite(Bin4, LOW);
      break;
   
   case 4  :
      digitalWrite(Bin1, LOW); //Write "4" to the display
      digitalWrite(Bin2, LOW);
      digitalWrite(Bin3, HIGH);
      digitalWrite(Bin4, LOW);
      break;
   case 5  :
      digitalWrite(Bin1, HIGH); //Write "5" to the display
      digitalWrite(Bin2, LOW);
      digitalWrite(Bin3, HIGH);
      digitalWrite(Bin4, LOW);
      break;
   
   case 6  :
      digitalWrite(Bin1, LOW); //Write "6" to the display
      digitalWrite(Bin2, HIGH);
      digitalWrite(Bin3, HIGH);
      digitalWrite(Bin4, LOW);
      break;
	
   case 7  :
      digitalWrite(Bin1, HIGH); //Write "7" to the display
      digitalWrite(Bin2, HIGH);
      digitalWrite(Bin3, HIGH);
      digitalWrite(Bin4, LOW);
      break;
   
   case 8  :
      digitalWrite(Bin1, LOW); //Write "8" to the display
      digitalWrite(Bin2, LOW);
      digitalWrite(Bin3, LOW);
      digitalWrite(Bin4, HIGH);
      break;
	
   case 9  :
      digitalWrite(Bin1, HIGH); //Write "9" to the display
      digitalWrite(Bin2, LOW);
      digitalWrite(Bin3, LOW);
      digitalWrite(Bin4, HIGH);
      break;
     
   
  }
 }

void writeFrequencyBCD(int Value){
   int Digit1 = 0;
   int Digit0 = 0;
   
   Digit0 = Value / 10;
   Digit1 = Value % 10; 
   
   writeBCD(0, Digit0);
   writeBCD(1, Digit1);
   

}
