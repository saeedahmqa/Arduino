#include <SoftwareSerial.h>
SoftwareSerial SMESerial (6, 7);
#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>    

const int PulseWire = A0;      
const int Ind = 13;           
int Threshold = 550;           
                               
PulseSensorPlayground pulseSensor;  

void setup() {   
  Serial.begin(9600);
  SMESerial.begin(9600);
  Serial.println("Serial Begin");

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(Ind);       
  pulseSensor.setThreshold(Threshold);   
  delay(2000);

   if (pulseSensor.begin()) { // If puslse sensor connect properly
    Serial.println("We created a pulseSensor Object !"); 
  }
}

void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  
if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
  
   Serial.println("♥  A HeartBeat Happened ! "); 
   Serial.println(String("BPM: ") + myBPM);                        
                     
   SMESerial.print('\r');
   SMESerial.print(myBPM);
   SMESerial.print('|');
   SMESerial.print('\n');
  
   Serial.print('\r');
   Serial.print(myBPM);
   Serial.print('|');
   Serial.print('\n');
}
  delay(1000);       
}

  
