const float VCC   = 5.0;        // supply voltage is from 4.5 to 5.5V. Normally 5V.
const int model = 1;            // enter the model number (see below)
float cutOffLimit = 0.1;        // set the current which below that value, doesn't matter. Or set 0.5
int offset1 = 0;              // set the correction offset value
int offset2 = 0;              // set the correction offset value
/*
          "ACS712ELCTR-05B-T",// for model use 0
          "ACS712ELCTR-20A-T",// for model use 1
          "ACS712ELCTR-30A-T"// for model use 2  
sensitivity array is holding the sensitivy of the  ACS712
current sensors.       
*/
float sensitivity[] ={
          0.185,// for ACS712ELCTR-05B-T
          0.100,// for ACS712ELCTR-20A-T
          0.066// for ACS712ELCTR-30A-T
         }; 

const float QOV =   0.5 * VCC;// set quiescent Output voltage of 0.5V
float voltage1;               // internal variable for voltage
float voltage2;               // internal variable for voltage
float power1;
float power2;
float power3;

void setup() {
    Serial.begin(9600);       // initialize serial monitor
    Serial.println("Time *T, Power1 *P1, Power2 *P2, Power3 *P3");
}

void loop() {
  
  float voltage_raw1 =   (5.0 / 1023.0)* analogRead(A0);    // Read the voltage from sensor
  voltage1 =  voltage_raw1 - QOV + 0.020 ;                  // 0.000 is a value to make voltage zero when there is no current
  float current1 = voltage1 / sensitivity[model];

  float voltage_raw2 =   (5.0 / 1023.0)* analogRead(A1);    // Read the voltage from sensor
  voltage2 =  voltage_raw2 - QOV + 0.020 ;                  // 0.000 is a value to make voltage zero when there is no current
  float current2 = voltage2 / sensitivity[model];

  int volt1 = analogRead(A2);// read the input
  double voltage1 = map(volt1,0,1023, 0, 12700) + offset1;   // map 0-1023 to 0-2500 and add correction offset
  voltage1 /=100;                                           // divide by 100 to get the decimal values
  
  int volt2 = analogRead(A3);// read the input
  double voltage2 = map(volt2,0,1023, 0, 12500) + offset2;   // map 0-1023 to 0-2500 and add correction offset
  voltage2 /=100;                                           // divide by 100 to get the decimal values
  power1 = voltage1*current1;
  power2 = voltage2*current2;
  power3 = power1+power2;

//  Serial.print("Current 1 = ");
//  Serial.print(current1,2);                                
//  Serial.print(" ");
//  Serial.print("Current 2 = ");
//  Serial.print(current2,2);
//  Serial.print(" ");
//  Serial.print("Voltage 1 = ");
//  Serial.print(voltage1,2);
//  Serial.print(" ");
//  Serial.print("Voltage 2 = ");
//  Serial.println(voltage2,2);
  Serial.print(",");
  //Serial.print("Power 1 = ");
  Serial.print(power1,2);
  Serial.print(",");
  //Serial.print("Power 2 = ");
  Serial.print(power2,2);
  Serial.print(",");
  //Serial.print("Power 3 = ");
  Serial.println(power3,2);
  delay(1);
  ;
} 
