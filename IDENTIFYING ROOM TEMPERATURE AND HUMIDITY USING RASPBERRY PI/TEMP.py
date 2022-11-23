import Adafruit_DHT
SENSOR = Adafruit_DHT.DTH11
PIN = 4
while True:
     humidity , temperature = Adafruit_DHT.read(SENSOR,PIN)
     if humidity is not None and temperature is not None:
        print("humidity : " ,humidity)
        print("temperature : "temperature,)

