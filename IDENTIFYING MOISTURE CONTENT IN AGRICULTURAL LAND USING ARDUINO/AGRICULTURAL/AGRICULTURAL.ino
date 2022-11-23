#include<Wire.h>
 void setup()
 {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  Serial.println("Soil Moisture : ");
 }

 void loop()
 {
  int value = analogRead(A0);
  Serial.println(value);
  if (value >1000){
    Serial.print("Not Connected ");
    delay(1000);
  }
  else if (value <=600 && value >300){
    Serial.print("little  Moisture");
    delay(1000);
  }
  else if (value <= 300 && value >=0){
    Serial.print("full  Moisture");
    delay(1000);
  }
 }
