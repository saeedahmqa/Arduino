int sensor = A2; // Connected to sound sensor's output pin.
int redled = 12; // LED lights up when the pump is switched on.
int blueled = 11;
int relay_in = 3;    // Connected to "In" pin of the relay.

#define REF 10   // Threshold value for sound sensor's output.

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(blueled, OUTPUT); 
  pinMode(relay_in, OUTPUT);
 
}
void loop()
{
  
  int sensor_value = analogRead(sensor); // Reading the sound sensor's output value.
  
  if (sensor_value > REF)
  {
    digitalWrite(blueled, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(relay_in, LOW); // Setting the relay in as low, the common pin gets connected to NO pin of the relay.
    delay(200);
   }
   else
   {
    digitalWrite(blueled, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(relay_in, HIGH); // Setting the relay in as high, the common pin gets connected to NC pin of the relay.
   }

   Serial.println(sensor_value);
}
