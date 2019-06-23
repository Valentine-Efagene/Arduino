#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

// Green (Yellow/TX) goes to Digital 2
// White (Blue/RX) goes to Digital 3

void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  while( Serial.available() )
  {
    mySerial.write( Serial.read() );
  }

  while( mySerial.available() )
  {
    Serial.write( mySerial.read() );
  }
}
