#define MOTOR_PIN 3
#define POT_PIN A0
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  value = analogRead(POT_PIN);
  value = map(value, 0, 1023, 0, 255);
  analogWrite(MOTOR_PIN, value);
  Serial.println(value);
  delay(10);
}

