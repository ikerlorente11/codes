from machine import Pin, Timer
import utime

# Set led pin to onboard led
led = Pin("LED", Pin.OUT)
# Set in pin to 15
button = Pin(15, Pin.IN, Pin.PULL_DOWN)
# Set time opbject
tim = Timer()

# Callback function
def tick(timer):
    # Set variables as global
    global led
    global button
    
    # If there is energy in 15 pin led on
    if button():
        led.on()
        print("on")
    # Else led off
    else:
        led.off()
        print("off")

# Create periodic procedure, ONE_SHOT instead of PERIODIC to execute once
tim.init(freq=2, mode=Timer.PERIODIC, callback=tick)