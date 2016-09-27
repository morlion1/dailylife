import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

print "LED1"

GPIO.setup(2, GPIO.OUT)
GPIO.output(2, False)
GPIO.setup(3, GPIO.OUT)
GPIO.output(3, False)

GPIO.setup(4, GPIO.OUT)
GPIO.output(4, False)

GPIO.cleanup()


