import RPi.GPIO as GPIO
PIR_input=29
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PIR_input,GPIO.IN)
while True:
    if(GPIO.input(PIR_input)):
      print("Motion detected")
    else:
      print("MOtion not detected")
