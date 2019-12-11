#include "ESP8266WiFi.h"

const char* ssid = "vee";
const char* password = "valentyne";
const uint16_t port = 12324;
WiFiServer server(port);
int direction = 0;
String s_dir = "";
int PWMA=5;//Right side 
int PWMB=4;//Left side 
int DA=0;//Right reverse 
int DB=2;//Left reverse 

void setup() {
  pinMode(PWMA, OUTPUT); 
  pinMode(PWMB, OUTPUT); 
  pinMode(DA, OUTPUT); 
  pinMode(DB, OUTPUT); 
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
        s_dir = readLine(client);
        Serial.println(s_dir);
        direction = s_dir.toInt();

        switch (direction){
          case 0:
            s();
            break;
          case 1:
            b();
            break;
          case 2:
            f();
            break;
          case 3:
            tr();
            break;
          case 4:
            tl();
            break;
          case 13:
            br();
            break;
          case 14:
            bl();
            break;
          case 23:
            fr();
            break;
          case 24:
            fl();
            break;
           default:
            break;
        }
      }

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}

String readLine(WiFiClient client) {
  String data;
  boolean lineEnd = false;

  while (!lineEnd) {
    if (client.available()) {
      char c = client.read();

      if (c != '\n' && c != '\r') {
        data.concat(c);
      }

      if (c == '\n') {
        lineEnd = true;
      }
    }
  }

  return data;
}

void fr(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW);
}

void br(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
}

void fl(){
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
    
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, LOW);
}

void b(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, HIGH); 
     
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, HIGH);
}

void f(){
  digitalWrite(PWMA, HIGH); 
  digitalWrite(DA, LOW); 
    
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, LOW); 
}

void s(){
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, LOW); 
  digitalWrite(DB, LOW); 
}


void bl(){
  digitalWrite(PWMA, LOW); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, HIGH); 
  digitalWrite(DB, HIGH); 
}

void tl(){
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, HIGH); 
  
  digitalWrite(PWMB, 450); 
  digitalWrite(DB, LOW);
}

void tr(){
  digitalWrite(PWMA, 450); 
  digitalWrite(DA, LOW); 
     
  digitalWrite(PWMB, 450); 
  digitalWrite(DB, HIGH);
}
