#include <Wire.h>
#define echoPin 3
#define trigPin 2
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
Serial.println("HELLO RAGU "); 
Serial.println("Distance Measure Program");
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

if (distance <= 10)
{
Serial.println("Very Close");
delay(1000);
}
else if (distance >=11 && distance <=50)
{
Serial.println("Near Range");
delay(10000);
}
else
{
Serial.println("Far Range");
}}
