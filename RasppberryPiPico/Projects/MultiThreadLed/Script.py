from machine import Pin
import utime
import _thread

# Create core for second thread
def nucleo_2():
    while True:
        # Each 50ms toggel yellow led
        utime.sleep_ms(50)
        led_amarillo.toggle()

# Set leds pins
led_rojo = Pin(16,Pin.OUT)
led_amarillo = Pin(17,Pin.OUT)

# Start thread with specific function
_thread.start_new_thread(nucleo_2, ())

while True:
    # Each 1500ms toggel yellow led
    utime.sleep_ms(1500)
    led_rojo.toggle()