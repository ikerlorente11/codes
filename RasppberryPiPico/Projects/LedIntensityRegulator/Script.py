from machine import Pin, Timer, ADC, PWM
import utime

# Set potentiometer pin
potentiometer = ADC(26)

# Set led pin
led = PWM(Pin(16))
# Set led frequency
led.freq(5000)

while True:
    # Update led intensity
    led.duty_u16(potentiometer.read_u16())