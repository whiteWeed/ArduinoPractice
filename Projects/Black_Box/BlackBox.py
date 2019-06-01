#!/usr/bin/python
import smbus
from picamera import PiCamera
import time
 
# Define some constants from the datasheet
DEVICE     = 0x23 # Default device I2C address
POWER_DOWN = 0x00 # No active state
POWER_ON   = 0x01 # Power on
RESET      = 0x07 # Reset data register value
 
# Start measurement at 4lx resolution. Time typically 16ms.
CONTINUOUS_LOW_RES_MODE = 0x13
# Start measurement at 1lx resolution. Time typically 120ms
CONTINUOUS_HIGH_RES_MODE_1 = 0x10
# Start measurement at 0.5lx resolution. Time typically 120ms
CONTINUOUS_HIGH_RES_MODE_2 = 0x11
# Start measurement at 1lx resolution. Time typically 120ms
# Device is automatically set to Power Down after measurement.
ONE_TIME_HIGH_RES_MODE_1 = 0x20
# Start measurement at 0.5lx resolution. Time typically 120ms
# Device is automatically set to Power Down after measurement.
ONE_TIME_HIGH_RES_MODE_2 = 0x21
# Start measurement at 1lx resolution. Time typically 120ms
# Device is automatically set to Power Down after measurement.
ONE_TIME_LOW_RES_MODE = 0x23
 
#bus = smbus.SMBus(0) # Rev 1 Pi uses 0
bus = smbus.SMBus(1)  # Rev 2 Pi uses 1
camera = PiCamera()
 
def convertToNumber(data):
  # Simple function to convert 2 bytes of data
  # into a decimal number
  return ((data[1] + (256 * data[0])) / 1.2)
 
def readLight(addr=DEVICE):
  data = bus.read_i2c_block_data(addr,ONE_TIME_HIGH_RES_MODE_1)
  return convertToNumber(data)
 
def main():
 
  while True:
    lightLevel = readLight()
    print 'Light Level : ' + str(lightLevel) + ' lux'
    if lightLevel <= 20:
        now = time.gmtime(time.time())
        filename = str(now.tm_year) + '_' + str(now.tm_mon) + '_' + str(now.tm_mday) + '_' + str(now.tm_hour) + '_' + str(now.tm_min) + '_' + str(now.tm_sec) + '.h264'
        camera.start_preview()
        camera.start_recording('/home/pi/' + filename)
        sleep(10)
        camera.stop_recording()
        camera.stop_preview()
    else:
        time.sleep(1)
   
if __name__=="__main__":
   main()