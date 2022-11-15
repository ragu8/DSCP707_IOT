#include <Wire.h>
#define echoPin 3
#define trigPin 2
long duration;
int distance;
const int buzzer = 8;
const int light = 13;
const int light2 = 12;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(light, OUTPUT);
Serial.println("HELLO RAGU "); // print some text in Serial Monitor
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
digitalWrite(light, LOW);
digitalWrite(light2, LOW);
if (distance <= 10)
{
Serial.println("Very Close");
digitalWrite(light, HIGH);
tone(buzzer, 1000); // Send 1KHz sound signal...
delay(1000);
// ...for 1 sec
digitalWrite(light2, LOW);
tone(buzzer, 500);
noTone(buzzer);
// Stop sound...
}
else if (distance >=11 && distance <=50)
{
Serial.println("Near Range");
digitalWrite(light2, HIGH);
digitalWrite(light, LOW);
delay(1000);
}
else
{
Serial.println("Far Range");
}}
