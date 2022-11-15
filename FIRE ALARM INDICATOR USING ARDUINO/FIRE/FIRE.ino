#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// lowest and highest sensor readings:
const int sensorMin = 0;
// sensor minimum
const int sensorMax = 1024; // sensor maximum
const int buzzer = 8;
const int light = 7;
const int light1 = 6;
const int light2 = 5;
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup() {
// lcd.begin(16,2);
// lcd.backlight();
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(light, OUTPUT);
pinMode(light1, OUTPUT);
pinMode(light2, OUTPUT);
Serial.println("FIRE"); // print some text in Serial Monitor
Serial.println("Fire Detection Program");
Serial.println(F("Fire detection test!"));
// lcd.clear();
// lcd.setCursor(0,0);
// lcd.print("Starting the");
// lcd.setCursor(0,1);
// lcd.print("Fire Sensor");
}
void loop() {
// read the sensor on analog A0:
int sensorReading = analogRead(A0);
// map the sensor range (four options):
// ex: 'long int map(long int, long int, long int, long int, long int)'
int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
// range value:
switch (range) {
case 0: // A fire closer than 1.5 feet away.
Serial.println("Close Fire");
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("***CLOSE***");
//lcd.setCursor(0,1);
//lcd.print("****FIRE****");
tone(buzzer, 1000); // Send 1KHz sound signal...
delay(1000);
digitalWrite(light, HIGH);
tone(buzzer, 500);
noTone(buzzer);
// Stop sound...
break;
case 1:
// A fire between 1-3 feet away.
Serial.println("** Distant Fire **");
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("***DISTANT***");
//lcd.setCursor(0,1);
//lcd.print("****FIRE****");
digitalWrite(light1, HIGH);
break;
case 2:
// No fire detected.
Serial.println("No Fire");
//lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("***NO***");
//lcd.setCursor(0,1);
//lcd.print("****FIRE****");
digitalWrite(light2, HIGH);
break;
delay(500); // delay between reads
digitalWrite(light, LOW);
digitalWrite(light1, LOW);
digitalWrite(light2, LOW);
}
}
