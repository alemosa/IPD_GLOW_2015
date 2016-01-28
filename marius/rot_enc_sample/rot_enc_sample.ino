 int val; 
 int encoder0PinA = 2;
 int encoder0PinB = 4;
 int Frequency = 50;
 int encoder0PinBLast = LOW;
 int n = LOW;

 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   Serial.begin (9600);
 } 


 
 void loop() { 
   n = digitalRead(encoder0PinB);
   delay(3); //lower frequency, debounce in reality
   if ((encoder0PinBLast == LOW) && (n == HIGH)) {
     delay(20);  //avoid sampling on raising edge 

     if (digitalRead(encoder0PinA) == LOW) {
         if (Frequency > 40){
         Frequency--;
         }
     
         else {
            //opportunity to flash screen to inform user}}
         }
       
     } 
     else {
        if (Frequency <60){
            Frequency++;
          }
         else {
         //opportunity to flash screen to inform user}
       
        }
     }
     
     
   Serial.print (Frequency);
   Serial.print ("\n");
   
   }/*
    if ((encoder0PinBLast == HIGH) && (n == LOW)) {
     delay(40);  

     if (digitalRead(encoder0PinA) == HIGH) {
         Frequency--;
       
     } 
     else {Frequency++;}
     
    
   Serial.print (Frequency);
   Serial.print ("\n");
   
   } */
   encoder0PinBLast = n; 
 }
