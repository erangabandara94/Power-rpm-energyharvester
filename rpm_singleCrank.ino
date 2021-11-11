#define inputA 6

int counter = 0; 
int aState;
int aLastState;  
float rpm = 0;
float t1, t2, dt = 0;
void setup() { 
   pinMode (inputA,INPUT);
   
   Serial.begin (9600);
   //Serial.println("Date and time, counter");
   aLastState = digitalRead(inputA);  
   //t1 = millis();
} 

void loop() { 
   aState = digitalRead(inputA); 
   if (aState != aLastState){  
     counter ++;
     //Serial.print(",");
     //Serial.println(counter);
    
     if (counter == 1){
      t1 = millis();
      }

     if (counter == 10){
        //t2 = millis();
        //dt = t1 - t2;
        rpm = 8437.5/(millis()-t1);
        Serial.println(rpm);
        counter = 0;
        //t1 = t2;
      }
   }
   aLastState = aState; 
}
