//
//    FILE: MCP23S17_performance.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2021-12-30
// PUPROSE: test MCP23017 library


#include "MCP23S17.h"
#include "SPI.h"

MCP23S17 MCP(10, 5, 6, 7);

uint32_t start, stop;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("MCP23S17_test version: ");
  Serial.println(MCP23S17_LIB_VERSION);
  Serial.println();
  delay(100);

  SPI.begin();
  bool b = MCP.begin();

  MCP.pinMode8(0, 0x00);  // 0 = output , 1 = input
  MCP.pinMode8(1, 0x00);

  Serial.print("TEST digitalWrite(0):\t");
  delay(100);
  start = micros();
  for (int i = 0; i < 16; i++)
  {
    MCP.digitalWrite(0, i % 2);  // alternating HIGH/LOW
  }
  stop = micros();
  Serial.println((stop - start) / 16.0);

  Serial.print("TEST digitalWrite(pin):\t");
  delay(100);
  start = micros();
  for (int pin = 0; pin < 16; pin++)
  {
    MCP.digitalWrite(pin, 1 - pin % 2); // alternating HIGH/LOW
  }
  stop = micros();
  Serial.println((stop - start) / 16.0);

  Serial.print("TEST digitalRead(pin):\t");
  delay(100);
  start = micros();
  for (int pin = 0; pin < 16; pin++)
  {
    volatile int val = MCP.digitalRead(pin);
  }
  stop = micros();
  Serial.println((stop - start) / 16.0);
  Serial.println();

  Serial.println("\ndone...");
}


void loop()
{
}


// -- END OF FILE --
