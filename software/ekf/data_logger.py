from serial import Serial
import numpy as np
import signal
import time
import sys
import os

from mavlink import *

PORT = "/dev/ttyUSB1"
# PORT = "COM9"

BAUD = 57600
# BAUD = 115200

class TAG:
    def __init__(self):
        self.stop = False

    def run(self):
        while not self.stop:
            try:
                serial = Serial(PORT, BAUD)
                mav = MAVLink(serial)
                self.mav = mav
                break
            except:
                time.sleep(1)
        
        while not self.stop:
            try:
                byte = serial.read()
                msg = mav.parse_char(byte)
                if msg is not None:
                    if msg.id == MAVLINK_MSG_ID_DISTANCE or msg.id == MAVLINK_MSG_ID_EVT_RPY:
                        print(msg.to_json())
            except:
                pass

    def stop_now(self):
        self.stop = True

if __name__ == "__main__":
    tag = TAG()
    def signal_int(sig, frame):
        tag.stop_now()
        print(" Ctrl+C ---> Stop")
        sys.exit(0)
    signal.signal(signal.SIGINT, signal_int)
    tag.run()

