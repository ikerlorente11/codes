from machine import Pin
import utime

# Set led pin to 28
led = Pin(28, Pin.OUT)

# Set led pin to onboard led
led = Pin("LED", Pin.OUT)

# Loop
while True:
    # Toggle led
    led.toggle()
    print("toggle")
    
    # Wait 1 second
    utime.sleep(1)