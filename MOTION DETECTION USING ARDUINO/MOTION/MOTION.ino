
int sensor = A3;void setup() {

  pinMode(sensor, INPUT);
  Serial.begin(9600);
}void loop() {
  int sensorval = analogRead(sensor);
  Serial.println(sensorval);
  
  if (sensorval > 234) {

    Serial.println(" Some Motion");
    Serial.println(sensorval);
  }
  else {
 
   Serial.println("NO Motion");
   Serial.println(sensorval);
  }
}
