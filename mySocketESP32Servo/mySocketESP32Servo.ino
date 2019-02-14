#include <WiFi.h>
#include <ESP32Servo.h> 

Servo myservo;
int servoPin = 4;
const char* ssid = "vee";
const char* password = "valentyne";
const uint16_t port = 12324;
//const char *host = "192.168.43.214";
int value = 0;
String c;
int pos = 0;
int old_value = 0;
int ADC_Max = 4096;
WiFiServer server(port);

void setup() {
  Serial.begin( 115200 );
  
  myservo.setPeriodHertz(50);// Standard 50hz servo
  myservo.attach(servoPin);
  
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
    Serial.println("Client connected");
    
    while (client.connected()) {

      while (client.available()>0) {
        //char c = client.read();
        c = readLine(client);
        c.trim();
        value = c.toInt();
        pos = map(value, 0, 360, 0, 180);
        myservo.write(pos);
        
        delay(10);
        Serial.println(value);
      }

      delay(100);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}

String readLine(WiFiClient client) {
  String data;
  boolean lineEnd = false;

  while(!lineEnd){
    if(client.available()){
      char c = client.read();

      if(c != '\n' && c != '\r') {
        data.concat(c);
      }

      if(c == '\n'){
        lineEnd = true;
      }
    }
  }

  return data;
}

