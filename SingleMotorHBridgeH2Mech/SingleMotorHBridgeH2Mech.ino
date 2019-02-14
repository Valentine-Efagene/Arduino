/*  Arduino DC Motor Control - PWM | H-Bridge | L298N

    by Valentine Edesiri Efagene (VEE)
*/

#define ENA 9
#define IN1 6
#define IN2 7
#define INT_BUTTON 2

volatile bool in1Motion = false;
volatile bool in2Motion = true;

void changeDirection();

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Set initial rotation direction
  digitalWrite(IN1, in1Motion);
  digitalWrite(IN2, in2Motion);
  attachInterrupt(digitalPinToInterrupt(INT_BUTTON), changeDirection, RISING);
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  analogWrite(ENA, pwmOutput); // Send PWM signal to L298N Enable pin

  // If button is pressed - change rotation direction
  digitalWrite(IN1, in1Motion);
  digitalWrite(IN2, in2Motion);
  delay(20);
  
  Serial.println(in1Motion);
}

void changeDirection() {
   // Read button - Debounce
   in1Motion = !in1Motion;
   in2Motion = !in2Motion;
}

