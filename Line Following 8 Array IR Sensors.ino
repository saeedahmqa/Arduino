#include <QTRSensors.h>

QTRSensorsRC qtrrc((unsigned char[]) {2, 3, 4, 5, 6, 7, 8, 9}, 8);

int sensors[8];

void setup()
{
  pinMode(13, OUTPUT);
  for (int i = 0; i < 8; i++)
  {
    pinMode(i + 2, INPUT);
  }
}

void loop()
{
  qtrrc.read(sensors);
  int position = qtrrc.readLine(sensors);
  int motorSpeed = 120;
  int turnSpeed = 50;
  
  if (position > 3500) // robot is on white surface
  {
    digitalWrite(13, HIGH);
    analogWrite(10, motorSpeed + turnSpeed);
    analogWrite(11, motorSpeed - turnSpeed);
  }
  else // robot is on black line
  {
    digitalWrite(13, LOW);
    analogWrite(10, motorSpeed - turnSpeed);
    analogWrite(11, motorSpeed + turnSpeed);
  }
}

