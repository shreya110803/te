import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

GPIO.setup(21,GPIO.IN)
GPIO.setup(2,GPIO.OUT)

while True:
    a=GPIO.input(21)
    if (a==1):
        print("IR sensor Detected")
        GPIO.output(2,True)
        time.sleep(0.2)
    else:
        print("Not Detected")
        GPIO.output(2,False)
        