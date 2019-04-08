// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       FinalYearProjectDemo1.ino
    Created:	4/8/2019 4:09:39 PM
    Author:     GHOST\valentyne
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

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
	Serial.begin(115200);

	myservo.setPeriodHertz(50);// Standard 50hz servo
	myservo.attach(servoPin);

	WiFi.begin(ssid, password);
	server.begin();

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.println("...");
	}

	Serial.print("WiFi connected with IP: ");
	Serial.println(WiFi.localIP());
}

void loop() {

	WiFiClient client = server.available();

	if (client) {
		Serial.println("Client connected");

		while (client.connected()) {

			while (client.available() > 0) {
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

int getWidth(char a[])
{
	int c, offset = 0, n = 0;

	for (c = offset; a[c] >= '0' && a[c] <= '9'; c++)
	{
		n = n * 10 + a[c] - '0';
	}

	return n;
}

int getHeight(char a[])
{
	int c, offset = 0, i = 0, n = 0;

	while (a[i] != ' ') {
		offset = i + 2;
		i++;
	}

	for (c = offset; a[c] >= '0' && a[c] <= '9'; c++)
	{
		n = n * 10 + a[c] - '0';
	}

	return n;
}
