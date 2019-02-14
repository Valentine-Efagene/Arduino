#include <WiFi.h>

const char* ssid = "vee";
const char* password = "valentyne";
const uint16_t port = 12324;
const char *host = "192.168.43.214";

void setup() {
  Serial.begin( 115200 );
  WiFi.begin( ssid, password );

  while ( WiFi.status() != WL_CONNECTED ) {
    delay( 500 );
    Serial.println( "..." );
  }

  Serial.print( "WiFi connected with IP: " );
  Serial.println( WiFi.localIP() );
}

void loop() {
  WiFiClient client;

  if( !client.connect( host, port ) ) {
    Serial.println( "Connection to host failed" );
    delay( 1000 );
    return;
  }

  client.print( "Hello from ESP32!" );
  client.stop();
}

