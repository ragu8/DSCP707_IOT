#include <DHT_U.h>
#include <DHT.h>

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
#include <Wire.h>
#include "DHT.h"
#define DHTPIN 2
// Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
const int buzzer = 8;
const int light = 7;
const int light1 = 6;
const int light2 = 5;
void setup() {
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(light, OUTPUT);
pinMode(light1, OUTPUT);
pinMode(light2, OUTPUT);
Serial.println("Tempearture & Humidity Reading Program "); // print some text in Serial Monitor
Serial.println("Tempearture & Humidity Reading Program");
Serial.println(F("DHT11 test!"));
dht.begin();
}
void loop() {
digitalWrite(light, LOW);
// Wait a few seconds between measurements.
delay(2000);
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity(); // Read temperature as Celsius (the default)
float t = dht.readTemperature(); // Read temperature as Fahrenheit (isFahrenheit = true)
float f = dht.readTemperature(true); // Check if any reads failed and exit early (to try again).
if (isnan(h) || isnan(t) || isnan(f)) {
Serial.println(F("Failed to read from DHT sensor!"));
digitalWrite(light, HIGH);
return; }
float hif = dht.computeHeatIndex(f, h); // Compute heat index in Fahrenheit (the default)
float hic = dht.computeHeatIndex(t, h, false); // Compute heat index in Celsius (isFahreheit = false)
Serial.print(F(" Humidity: "));
Serial.print(h);
Serial.print(F("% Temperature: "));
Serial.print(t);
Serial.print(F("C "));
Serial.print(f);
Serial.print(F("F Heat index: "));
Serial.print(hic);
Serial.print(F("C "));
Serial.print(hif);
Serial.println(F("F"));
if (t>29)
{ tone(buzzer, 1000); // Send 1KHz sound signal...
delay(1000);
// ...for 1 sec
digitalWrite(light1, HIGH);
digitalWrite(light2, LOW);
tone(buzzer, 500);
noTone(buzzer);
// Stop sound...
Serial.println("Alert: HIGH Temperture"); }
else{
Serial.println("Alert: Low Temperture");
digitalWrite(light2, HIGH);
}
delay(2000);
digitalWrite(light1,LOW);
}
