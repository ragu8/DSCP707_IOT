from time import sleep
import RPi.GPIO as GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11,GPIO.IN)
GPIO.setup(3,GPIO.OUT)
while True:
     if(GPIO.input(11)== True):
        GPIO.output(3,False)
        print("NO sound");
        sleep(1)
     if(GPIO.input(11)== False):
        GPIO.output(3,True)
        print("sound");
        sleep(1)
