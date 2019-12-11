#include "ESP8266WiFi.h"

const char* ssid = "vee";
const char* password = "valentyne";
const uint16_t port = 12324;
WiFiServer server(port);

typedef struct Position_vector {
   int x;
   int y;
} Position;

Position pos;

void setup() {
  Serial.begin( 9600 );
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
        pos = getPosition(client);
        Serial.print("x = ");
        Serial.println(pos.x);
        
        Serial.print("y = ");
        Serial.println(pos.y);
      }

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}

Position getPosition(WiFiClient client){
  String dataX;
  String dataY;
  Position pos;
  boolean grabbingX = true;

  while(true){
    if(client.available()){
      char c = client.read();

      switch (c){
        case ' ':
          grabbingX = false;
          break;
        case ',':
          grabbingX = false;
          break;
        case '\n':
          pos.x = dataX.toInt();
          pos.y = dataY.toInt();
          return pos;
          break;
        default:
          if(grabbingX){
            dataX.concat(c);
          }else{
            dataY.concat(c);
          }
          
          break;
      }
    }
  }

  return pos;
}
