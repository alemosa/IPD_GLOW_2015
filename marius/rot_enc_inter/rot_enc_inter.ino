/* read a rotary encoder with interrupts
   Encoder hooked up with common to GROUND,
   encoder0PinA to pin 2, encoder0PinB to pin 4 (or pin 3 see below)
   it doesn't matter which encoder pin you use for A or B  

   uses Arduino pullups on A & B channel outputs
   turning on the pullups saves having to hook up resistors 
   to the A & B channel outputs 

*/ 

#define encoder0PinA  4 //in reality B on circuit
#define encoder0PinB  2 // in rality A on circuit
#define BOUNCE_DURATION 5   // define an appropriate bounce time in ms for your switches

volatile unsigned int encoder0Pos = 0;
volatile unsigned int encoder0PosL = 0;
volatile unsigned long bounceTime=0; // variable to hold ms count to debounce a pressed switch
volatile unsigned long bounceEnterTime=0; // variable to hold ms count when interrupt entered
volatile unsigned long bounceFlag=0; // variable state of interrupt


void setup() { 


  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(digitalPinToInterrupt(encoder0PinB), doEncoder_M, RISING);  // encoder pin on interrupt 0 - pin 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk

} 

void loop(){
// do some stuff here - the joy of interrupts is that they take care of themselves
 // delay(20);
  if (encoder0Pos != encoder0PosL ){
    Serial.println (encoder0Pos, DEC);
    Serial.println(bounceTime, DEC);
    Serial.println(bounceEnterTime, DEC); 
    encoder0PosL = encoder0Pos;
  }
}

void doEncoder() {
  /* If pinA and pinB are both high or both low, it is spinning
   * forward. If they're different, it's going backward.
   *
   * For more information on speeding up this process, see
   * [Reference/PortManipulation], specifically the PIND register.
   */
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }

  
}
void doEncoder_M(){
 
   if (bounceFlag = 0){
      bounceTime = millis(); 
   }
   else{
      if(millis() > bounceTime + BOUNCE_DURATION)  {
          bounceFlag = 0;
          bounceEnterTime = millis();
         if (digitalRead(encoder0PinA) == LOW) {  // check channel B to see which way
                                               // encoder is turning
          encoder0Pos = encoder0Pos - 1;         // CCW
          } 
          else {
            encoder0Pos = encoder0Pos + 1;         // CW
          }

      }
      
   }
   

}

/* See this expanded function to get a better understanding of the
 * meanings of the four possible (pinA, pinB) value pairs:
 */
void doEncoder_Expanded(){
  if (digitalRead(encoder0PinA) == HIGH) {   // found a low-to-high on channel A
    if (digitalRead(encoder0PinB) == LOW) {  // check channel B to see which way
                                             // encoder is turning
      encoder0Pos = encoder0Pos - 1;         // CCW
    } 
    else {
      encoder0Pos = encoder0Pos + 1;         // CW
    }
  }
  else                                        // found a high-to-low on channel A
  { 
    if (digitalRead(encoder0PinB) == LOW) {   // check channel B to see which way
                                              // encoder is turning  
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }

  }
  //Serial.println (encoder0Pos, DEC);          // debug - remember to comment out
                                              // before final program run
  // you don't want serial slowing down your program if not needed
}

/*  to read the other two transitions - just use another attachInterrupt()
in the setup and duplicate the doEncoder function into say, 
doEncoderA and doEncoderB. 
You also need to move the other encoder wire over to pin 3 (interrupt 1). 
*/ 
