from serial import Serial
import argparse
import numpy as np
import signal
import time
import sys
import os

from mavlink import *

class TAG:
    def __init__(self,  port, baud, out):
        self.port = port
        self.baud = baud
        self.data_folder = out

        self.stop = False
        self.raw = []
        self.cal = []
        self.ref = []
        try:
            os.mkdir(self.data_folder)
        except:
            pass

    def run(self):
        while not self.stop:
            try:
                serial = Serial(self.port, self.baud)
                mav = MAVLink(serial)
                self.mav = mav
                break
            except:
                time.sleep(1)
        ok = False
        while not ok and not self.stop:
            counter = 0
            print("mode MODE_IMU")
            self.mav.cmd_change_mode_send(MODE_IMU)
            while not self.stop:
                try:
                    byte = serial.read()
                    msg = mav.parse_char(byte)
                    if msg is not None:
                        if msg.id == MAVLINK_MSG_ID_RESPOND and msg.respond == RESPOND_OK:
                            print(msg.to_json())
                            ok = True
                            break
                        else:
                            counter+=1
                            if counter > 10:
                                break
                except:
                    pass
        
        while not self.stop:
            try:
                byte = serial.read()
                msg = mav.parse_char(byte)
                if msg is not None:
                    print(msg.to_json())
                    if msg.id == MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED:
                        self.cal.append([msg.gx, msg.gy, msg.gz, msg.ax, msg.ay, msg.az, msg.mx, msg.my, msg.mz])
                    if msg.id == MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_RAW:
                        self.raw.append([msg.gx, msg.gy, msg.gz, msg.ax, msg.ay, msg.az, msg.mx, msg.my, msg.mz])
                    elif msg.id == MAVLINK_MSG_ID_EVT_RPY:
                        self.ref.append([msg.roll, msg.pitch, msg.yaw])
            except:
                pass

    def stop_now(self):
        raw = np.array(self.raw)
        cal = np.array(self.cal)
        ref = np.array(self.ref)
        np.save(self.data_folder + '/raw.npy', raw)
        np.save(self.data_folder + '/cal.npy', cal)
        np.save(self.data_folder + '/ref.npy', ref)

        self.stop = True

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='IMU data logger')
    parser.add_argument('-p', '--port',metavar='PORT', help='port name', default="/dev/ttyUSB0")
    parser.add_argument('-b', '--baud', metavar='BAUD', type=int, help='baudrate', default=57600)
    parser.add_argument('-o', '--out', metavar='OUT', help='Output folder', default="./imu")
    args = parser.parse_args()
    print(args)

    tag = TAG(port=args.port, baud=args.baud, out=args.out)
    def signal_int(sig, frame):
        tag.stop_now()
        print(" Ctrl+C ---> Stop")
        sys.exit(0)
    signal.signal(signal.SIGINT, signal_int)
    tag.run()