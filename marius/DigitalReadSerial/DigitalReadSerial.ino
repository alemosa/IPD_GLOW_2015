
long frequency = 15; //


volatile int BT1State = LOW; //initial button state
volatile int BT2State = LOW; //initial button state

volatile long lastDebounceTime = 0;   // the last time the interrupt was triggered
long debounceDelay = 10;    // the debounce time; decrease if quick button presses are ignored
const int BT1Interrupt = 0;  // Button interrupt
const int BT2Interrupt = 1;  // Button interrupt

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  attachInterrupt(BT1Interrupt, BT1Rise, RISING);
  attachInterrupt(BT2Interrupt, BT2Rise, RISING);
}

void loop() {
  delay(500);
  Serial.println(frequency);
}


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
