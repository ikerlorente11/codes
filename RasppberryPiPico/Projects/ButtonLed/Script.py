from machine import Pin
import utime

# Set led pin to onboard led
led = Pin("LED", Pin.OUT)
# Set in pin to 15
button = Pin(15, Pin.IN, Pin.PULL_DOWN)

# Loop
while True:
    # If there is energy in 15 pin led on
    if button():
        led.on()
        print("on")
    # Else led off
    else:
        led.off()
        print("off")