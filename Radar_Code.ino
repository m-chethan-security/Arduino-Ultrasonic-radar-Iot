#include <Servo.h>

Servo myServo;

const int servoPin = 11;
const int trigPin = 8;
const int echoPin = 9;

void setup() {
  myServo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  for (int angle = 0; angle <= 180; angle++) {

    myServo.write(angle);

    long duration = getEcho();

    int distance = duration / 58;

    Serial.print("Angle: ");
    Serial.print(angle);

    Serial.print(" Distance: ");
    Serial.print(distance);

    Serial.println(" cm");

    delay(15);
  }
}

long getEcho() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  return pulseIn(echoPin, HIGH);
}
