int led = 13;
int sensor = A3;void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}void loop() {
  int sensorval = analogRead(sensor);
  Serial.println(sensorval);
  
  if (sensorval > 234) {
    digitalWrite(led, HIGH);
    Serial.println(" Some Motion");
    Serial.println(sensorval);
  }
  else {
   digitalWrite(led, LOW);
   Serial.println("NO Motion");
   Serial.println(sensorval);
  }
}
