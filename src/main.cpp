#include <logic_analyzer.hpp>

void setup()
{
  pinMode(D0, OUTPUT);
  init_logic_analyzer();
}

void loop()
{
  delay(1000);
  digitalWrite(D0, HIGH);
  delay(1000);
  digitalWrite(D0, LOW);
}