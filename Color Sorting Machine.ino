/*     Arduino Project - Color Sorting Machine
 *
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *
 */
#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo topServo;
Servo bottomServo;

int frequency = 0;
int color=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(7);
  bottomServo.attach(8);

  Serial.begin(9600);
}

void loop() {

  topServo.write(115);
  delay(500);
  
  for(int i = 115; i > 65; i--) {
    topServo.write(i);
    delay(25);
  }
  delay(500);
  
  color = readColor();
  delay(10);  

  switch (color) {
    case 1:  //red
    bottomServo.write(50);
   //Serial.println(bottomServo.write());
    break;

    case 2:  //orange
    bottomServo.write(75);
    break;

    case 3:   //green
    bottomServo.write(95);
    break;

    case 4:  //yellow
    bottomServo.write(115);
    break;
 
    case 5:   //brown
    bottomServo.write(135);
    break;

    case 6:   //blue
    bottomServo.write(155);
    break;
    
    case 0:
     //bottomServo.write(20);
    break;
  }
  delay(300);
  
  for(int i = 65; i > 29; i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 29; i < 115; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}

// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);

  if(R<=54 & R>=32 & G<=95 & G>=51){
    color = 1; // Red
  }
  if(G<=57 & G>=41 & B<=41 &B>=36){
    color = 2; // Orange
  }
  if(R<=62 & R>=40 & G<=55 & G>=40){
    color = 3; // Green
  }
  if(R<=47 & R>=30 & G<=49 & G>=28){
    color = 4; // Yellow
  }
  if(R<=46 & R>=40 & B<=33 & B>=32){
    color = 5; // Pink
  }
  if (G<=49 & G>=37 & B<=32 &B>=31){
    color = 6; // Blue
  }
  return color;  
}