from picamera import PiCamera
from time import sleep

camera=PiCamera()

camera.rotation=0
camera.start_preview()
for i in range(2):
    camera.capture('/home/pi/Desktop/new%s.jpg'%i)
camera.stop_preview()

