 //works only ccw, clockwise has a great error
 
 int val; 
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int Frequency = 50;
 int encoder0PinBLast = LOW;
 int n = LOW;
 int startloop = 0;
 int endloop = 0;

 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   Serial.begin (9600);
 } 


 
 void loop() { 
   n = digitalRead(encoder0PinB);
   //int startloop = millis();
   if ((encoder0PinBLast == LOW) && (n == HIGH)) {
     //delay(5);  

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
     //int endloop = millis()  -startloop;
   
     Serial.print (Frequency);
     //Serial.print ("\ndifference ms");
     //Serial.print (endloop );
     Serial.print ("\n");
   }
   encoder0PinBLast = n; 
 }
