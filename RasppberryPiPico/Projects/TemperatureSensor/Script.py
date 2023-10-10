from machine import Pin, Timer, ADC
import utime

# Set temperature sensor pin
sensor_temp = ADC(4)
# Set conversion factor
conversion_factor = 3.3 / (65535)

while True:
    # Read value from sensor
    reading = sensor_temp.read_u16() * conversion_factor
    
    # Convert to degrees
    temperature = 27 - (reading - 0.706) / 0.001721
    # Show temperature
    print(temperature)
    utime.sleep(2)