from serial import Serial
import numpy as np
import signal
import time
import sys
import os

from mavlink import *

PORT = "/dev/ttyUSB0"
BAUD = 57600

class TAG:
    def __init__(self):
        self.DATASET_FOLDER = "imu_data/"
        self.stop = False
        self.gx=[]
        self.gy=[]
        self.gz=[]
        self.ax=[]
        self.ay=[]
        self.az=[]
        self.mx=[]
        self.my=[]
        self.mz=[]
        self.roll=[]
        self.pitch=[]
        self.yaw=[]
        try:
            os.mkdir(self.DATASET_FOLDER)
        except:
            pass


    def run(self):
        retry_count = 0
        while not self.stop:
            try:
                serial = Serial(PORT, BAUD)
                mav = MAVLink(serial)
                self.mav = mav
                break
            except:
                time.sleep(1)
        ok = False
        while not ok and not self.stop:
            counter = 0
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
                    if msg.id == MAVLINK_MSG_ID_EVT_GYRO_ACCEL_MAG_CALIBRATED:
                        self.gx.append(msg.gx)
                        self.gy.append(msg.gy)
                        self.gz.append(msg.gz)
                        self.ax.append(msg.ax)
                        self.ay.append(msg.ay)
                        self.az.append(msg.az)
                        self.mx.append(msg.mx)
                        self.my.append(msg.my)
                        self.mz.append(msg.mz)
                        print(msg.to_json())
                    elif msg.id == MAVLINK_MSG_ID_EVT_RPY:
                        self.roll.append(msg.roll)
                        self.pitch.append(msg.pitch)
                        self.yaw.append(msg.yaw)
                        print(msg.to_json())
            except:
                pass

    def stop_now(self):
        gx = np.array(self.gx)
        gy = np.array(self.gy)
        gz = np.array(self.gz)
        np.save(self.DATASET_FOLDER + 'gx.npy', gx)
        np.save(self.DATASET_FOLDER + 'gy.npy', gy)
        np.save(self.DATASET_FOLDER + 'gz.npy', gz)

        ax = np.array(self.ax)
        ay = np.array(self.ay)
        az = np.array(self.az)
        np.save(self.DATASET_FOLDER + 'ax.npy', ax)
        np.save(self.DATASET_FOLDER + 'ay.npy', ay)
        np.save(self.DATASET_FOLDER + 'az.npy', az)

        mx = np.array(self.mx)
        my = np.array(self.my)
        mz = np.array(self.mz)
        np.save(self.DATASET_FOLDER + 'mx.npy', mx)
        np.save(self.DATASET_FOLDER + 'my.npy', my)
        np.save(self.DATASET_FOLDER + 'mz.npy', mz)

        roll = np.array(self.roll)
        pitch = np.array(self.pitch)
        yaw = np.array(self.yaw)
        np.save(self.DATASET_FOLDER + 'roll.npy', roll)
        np.save(self.DATASET_FOLDER + 'pitch.npy', pitch)
        np.save(self.DATASET_FOLDER + 'yaw.npy', yaw)

        self.stop = True

if __name__ == "__main__":
    tag = TAG()
    def signal_int(sig, frame):
        tag.stop_now()
        print(" Ctrl+C ---> Stop")
        sys.exit(0)
    signal.signal(signal.SIGINT, signal_int)
    tag.run()

