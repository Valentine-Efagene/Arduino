//Include SPI library
#include <SPI.h>

//When using the SPI library, you only have to worry
//about picking your slave selects
//By default, 11 = MOSI, 12 = MISO, 13 = CLK

const int SS1=10; //Slave Select Chip 1
const byte REG0=B00000000; //Register 0 Write command
const byte REG1=B00010000; //Register 1 Write command

void setup()
{
  //Set pin directions for SS
  pinMode(SS1, OUTPUT);
  //Initialize SPI
  SPI.begin();
}

void setLed(int SS, int reg, int level)
{
  digitalWrite(SS, LOW); //Set the given SS pin low
  SPI.transfer(reg); //Choose the register to write to
  SPI.transfer(level); //Set the LED level (0-128)
  digitalWrite(SS, HIGH); //Set the given SS pin high again
}

void loop()
{
  for (int i=0; i<=128; i++)
  {
    setLed(SS1, REG0, i);
    setLed(SS1, REG1, i);
    delay(10);
  }

  delay(300);

  for (int i=128; i>=0; i--)
  {
    setLed(SS1, REG0, i);
    setLed(SS1, REG1, i);
    setLed(SS2, REG0, i);
    setLed(SS2, REG1, i);
    delay(10);
  }

  delay(300);
}
