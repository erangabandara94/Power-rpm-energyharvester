#define inputA 6
#define inputB 7

int counter1, counter2 = 0; 
int aState;
int bState;
int aLastState; 
int bLastState;  
float rpm1, rpm2 = 0;       // rpm1 = Leg, rpm2 = Hand
float t1, t2 = 0;
void setup() { 
   pinMode (inputA,INPUT);
   pinMode (inputB,INPUT);
   Serial.begin (9600);
   //Serial.println("Date and time, counter");
   aLastState = digitalRead(inputA); 
   bLastState = digitalRead(inputB); 
   //t1 = millis();
} 

void loop() { 
   aState = digitalRead(inputA); 
   bState = digitalRead(inputB);
   if (aState != aLastState){  
     counter1 ++;
     //Serial.print(",");
     //Serial.println(counter);
    
     if (counter1 == 1){
      t1 = millis();
      }

     if (counter1 == 10){
        //t2 = millis();
        //dt = t1 - t2;
        rpm1 = 8437.5/(millis()-t1);
        //Serial.print(rpm1);
        //Serial.print("  ");
        counter1 = 0;
        //t1 = t2;
      }
   }

    if (bState != bLastState){  
     counter2 ++;
     //Serial.print(",");
     //Serial.println(counter);
    
     if (counter2 == 1){
      t2 = millis();
      }

     if (counter2 == 10){
        //t2 = millis();
        //dt = t1 - t2;
        rpm2 = 8437.5/(millis()-t2);
        //Serial.println(rpm2);
        counter2 = 0;
        //t1 = t2;
      }
   }  
   Serial.print(rpm1);
   Serial.print("  ");
   Serial.println(rpm2);
   aLastState = aState;
   bLastState = bState;
}
