#include <Servo.h>
#include "TimerOne.h"
#include "TimerThree.h"

Servo myservo;
double soundFreq = 50;
double lightFreq = 50;      //in Hz (u will need to do the conversions)
double servoPosition = 100; //this goes from 0 to 1023
String inString = "";
int option = 0;             //this is the state where u are (1 for light, 2 for sound, 3 for Servo).
double soundPeriod;
double lightPeriod;
bool messageSet = 0;
int dutyLight = 25;
int dutySound = 512;

//button interrupt variables

long frequency = 15; //


volatile int BT1State = LOW; //initial button state
volatile int BT2State = LOW; //initial button state

volatile long lastDebounceTime = 0;   // the last time the interrupt was triggered
long debounceDelay = 10;    // the debounce time; decrease if quick button presses are ignored
const int BT1Interrupt = 0;  // Button interrupt
const int BT2Interrupt = 1;  // Button interrupt

//button interrupt variables


void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  Timer3.initialize();
  myservo.attach(10);
  
  attachInterrupt(BT1Interrupt, BT1Rise, RISING); //BTN1 interrupt
  attachInterrupt(BT2Interrupt, BT2Rise, RISING); //BTN2 interrupt
}

void loop() {
  delay(500);           //to be removed
  Serial.println(frequency);  //to be removed
  if (Serial.available() > 0) {
                
                if (option == 0) {
                  char tempChar = Serial.read();
                  if (isDigit(tempChar)) {
                    inString += (char)tempChar;
                  }
                  if (tempChar == '\n') {
                    option = inString.toInt();
                    inString = "";
                    if ((option == 1) || (option == 2) || (option == 3))
                    {                 
                    Serial.print("Please, type the desired ");
                    if(option == 1)
                    {
                       Serial.println("light frequency");
                       }
                    else if(option == 2)
                    {
                      Serial.println("sound frequency");
                    } 
                    else if(option == 3)
                    {
                      Serial.println("Servo PWM Width");
                    }
                  
                }
                }
                }
                else if(option == 1)
                {
                  char tempOpt1 = Serial.read();
                  if(isDigit(tempOpt1)){
                    inString += (char)tempOpt1; 
                    }
                  if (tempOpt1 == '\n')
                  {
                    lightFreq = inString.toInt();
                    inString = "";
                  }   
                }  
                else if(option == 2)
                {
                  char tempOpt2 = Serial.read();
                  if(isDigit(tempOpt2)){
                    inString += (char)tempOpt2; 
                    }
                  if (tempOpt2 == '\n')
                  {
                    soundFreq = inString.toInt();
                    inString = "";
                  }   
                } 
                else if(option == 3)
                {
                  char tempOpt3 = Serial.read();
                  if(isDigit(tempOpt3)){
                    inString += (char)tempOpt3; 
                    }
                  if (tempOpt3 == '\n')
                  {
                    servoPosition = inString.toInt();
                    inString = "";
                  }   
                } 
                else option = 0;               
}

lightPeriod = (1/lightFreq)*1000000;
soundPeriod = (1/soundFreq)*1000000;



if (lightFreq > 0)
{
  Serial.print("Light frequency fixed to: ");
  Serial.println(lightFreq, 2);
  Timer1.pwm(11,dutyLight,lightPeriod);
  option = 0;
  messageSet = 0;
}
if (soundFreq > 0)
{
  Serial.print("Sound frequency fixed to: ");
  Serial.println(soundFreq, 2);
  Timer3.pwm(5, dutySound, soundPeriod);
  option = 0;
  messageSet = 0;
}
if(servoPosition > 0)
{
  Serial.print("Servo PWM Width fixed to: ");
  Serial.println(servoPosition, 2);
  servoPosition = map(servoPosition, 0, 1023, 0 , 90 );
  myservo.write(servoPosition);
  option = 0;
  messageSet = 0;
}

//if(option == 4)
//{
//  Serial.println("System stopped, all signals set to 0.");
//  soundFreq = 0;
//  lightFreq = 0;
//  servoPWM = 0;
//  soundTone.stop();
//  option = 0;  
//  messageSet = 0;
//}
if(option == 0 && !messageSet)
{
  Serial.println("Type 1 for light, 2 for sound or 3 for Servo PWM Width:");
  messageSet = 1;
}

soundFreq = 0;
lightFreq = 0;
servoPosition = 0;

}

//////button interrupt routines
void BT2Rise()
{
   long currentTime = millis();
   if ((currentTime - lastDebounceTime) > debounceDelay)
   {
       lastDebounceTime = currentTime;
       if (BT2State == LOW)
       {
           BT2State = HIGH;
           frequency--;
           attachInterrupt(BT2Interrupt, BT2Fall, FALLING);
       }

   }
}


void BT1Rise()
{
   long currentTime = millis();
   if ((currentTime - lastDebounceTime) > debounceDelay)
   {
       lastDebounceTime = currentTime;
       if (BT1State == LOW)
       {
           BT1State = HIGH;
           frequency++;
           attachInterrupt(BT1Interrupt, BT1Fall, FALLING);
       }
   }
}

void BT1Fall()
{
   long currentTime = millis();
   if ((currentTime - lastDebounceTime) > debounceDelay)
   {
      lastDebounceTime = currentTime;
      if (BT1State == HIGH)
     {
         BT1State = LOW;
         Serial.println(frequency);
         attachInterrupt(BT1Interrupt, BT1Rise, RISING);
     }

   }
}

void BT2Fall()
{
   long currentTime = millis();
   if ((currentTime - lastDebounceTime) > debounceDelay)
   {
      lastDebounceTime = currentTime;
      if (BT2State == HIGH)
     {
         BT2State = LOW;
         Serial.println(frequency);
         attachInterrupt(BT2Interrupt, BT2Rise, RISING);
     }

   }
}



void IncreaseFreq() {
  frequency++;
}

void DecreaseFreq() {
  frequency--;
}

