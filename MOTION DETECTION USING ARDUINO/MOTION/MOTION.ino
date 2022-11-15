#include <Wire.h>
const int buzzer = 11;
const int light = 13;
int sensor = 2;// the pin that the sensor is atteched to
int state = LOW;// by default, no motion detected
int val = 0;
// variable to store the sensor status (value)
void setup() {
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(light, OUTPUT);
pinMode(sensor, INPUT); // initialize sensor as an input
Serial.println("HELLO RAGU "); // print some text in Serial Monitor
Serial.println("Home Automation Program");
}
void loop() {
val = digitalRead(sensor); // read sensor value
if (val == HIGH) {
delay(100);
// check if the sensor is HIGH
// delay 100 milliseconds
if (state == LOW) {
Serial.println("Motion Detected");
Serial.println("");
digitalWrite(light, HIGH);
tone(buzzer, 1000); // Send 1KHz sound signal...
delay(500);
// ...for 1 sec
tone(buzzer, 500);
noTone(buzzer);// Stop sound...
state = HIGH;// update variable state to HIGH
}
}
else {
delay(100);
// delay 200 milliseconds
if (state == HIGH){
Serial.println("Motion stopped!");
digitalWrite(light, LOW);
state = LOW;
// update variable state to LOW
}
}
}
