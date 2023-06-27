#include <SoftwareSerial.h>
SoftwareSerial SMESerial (D6, D7);
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLuEekBoX9"
#define BLYNK_DEVICE_NAME "BPMMonitoring"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define BLYNK_DEBUG
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(9600);
  SMESerial.begin(9600);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  sensor();
  delay(500);
}

void sensor()
{
  if (SMESerial.available()<1)  return;
  char R=SMESerial.read();
  if (R!='\r')                 return;
  int bpm=SMESerial.parseInt();
  Serial.println("♥  A HeartBeat Happened ! "); 
  Serial.println(String("BPM: ") + bpm); 
  Blynk.virtualWrite(V0, bpm);
}
