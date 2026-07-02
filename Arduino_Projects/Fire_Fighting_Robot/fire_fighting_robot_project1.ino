#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
Servo servo1;

// Pins
const int echoPin = 7;
const int trigPin = 6;
const int lm1 = 2;
const int lm2 = 3;
const int rm1 = 4;
const int rm2 = 5;
const int sensor = A0;
const int sensorThresh = 200;

long cm, duration;

void setup() {
  servo1.attach(A2);
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sensor, INPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("System Initializing");
  delay(2000);  // Display the initialization message for 2 seconds
}

void loop() {
  // Ultrasonic sensor - average reading for more stable distance measurement
  int numReadings = 5;
  long totalDistance = 0;

  for (int i = 0; i < numReadings; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    cm = duration * 0.034 / 2;
    totalDistance += cm;
  }

  cm = totalDistance / numReadings;

  // Obstacle Avoidance Logic
  if (cm < 20 ) {
    stopBot();
    delay(2000);
    goBackward();
    delay(2000);
    stopAgain();
    delay(1000);
    goLeft();
    delay(1000);
  } else {
    goStraight();
    delay(1000);
  }

  // Fire detection logic
  int analogValue = analogRead(sensor);
  Serial.print("Fire Sensor Value: ");
  Serial.println(analogValue);

  if (analogValue > sensorThresh) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fire Detected!");
    lcd.setCursor(0, 1);
    lcd.print("Taking Action...");
    delay(1000);
    
    // Rotate the servo from 0 to 180 degrees
    for (int angle = 0; angle <= 180; angle++) {
      servo1.write(angle);
      delay(15);
    }

    // Rotate the servo back from 180 to 0 degrees
    for (int angle = 180; angle >= 0; angle--) {
      servo1.write(angle);
      delay(15);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Action Complete");
    delay(1000);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Normal");
    lcd.setCursor(0, 1);
    lcd.print("No Fire Detected");
    servo1.write(90);  // Ensure servo is at default position
    delay(1000);
  }

  // Serial Monitor output for distance
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");
}

// Functions for robot movement
void goStraight() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Path Clear");
  lcd.setCursor(0, 1);
  lcd.print("Moving Forward");

  analogWrite(lm1, 255);
  analogWrite(lm2, 0);
  analogWrite(rm1, 255);
  analogWrite(rm2, 0);
}

void goBackward() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Obstacle Detected");
  lcd.setCursor(0, 1);
  lcd.print("Going Backward");

  analogWrite(lm2, 255);
  analogWrite(lm1, 0);
  analogWrite(rm2, 255);
  analogWrite(rm1, 0);
}

void stopBot() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Obstacle Ahead");
  lcd.setCursor(0, 1);
  lcd.print("Stopping");

  analogWrite(lm1, 0);
  analogWrite(lm2, 0);
  analogWrite(rm1, 0);
  analogWrite(rm2, 0);
}

void stopAgain() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pausing for Turn");

  analogWrite(lm1, 0);
  analogWrite(lm2, 0);
  analogWrite(rm1, 0);
  analogWrite(rm2, 0);
}

void goLeft() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turning Left");
  lcd.setCursor(0, 1);
  lcd.print("Path Clear");

  analogWrite(lm1, 0);
  analogWrite(lm2, 0);
  analogWrite(rm1, 255);
  analogWrite(rm2, 0);
}
