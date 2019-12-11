#include "ESP8266WiFi.h"

const char* ssid = "vee";
const char* password = "valentyne";
const uint16_t port = 12324;
WiFiServer server(port);

void setup() {
  Serial.begin( 115200 );
  WiFi.begin( ssid, password );
  server.begin();

  while ( WiFi.status() != WL_CONNECTED ) {
    delay( 500 );
    Serial.println( "..." );
  }

  Serial.print( "WiFi connected with IP: " );
  Serial.println( WiFi.localIP() );
}

void loop() {

  WiFiClient client = server.available();

  if (client) {

    while (client.connected()) {

      while (client.available()>0) {
        char c = client.read();
        Serial.write(c);
      }

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}

