from machine import Pin, I2C
import utime

# Set i2c pins aand fecuency
i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=200000)

# Get i2c direction
direction = hex(i2c.scan()[0])

# Print direction
print('La direccion I2C es ', direction)