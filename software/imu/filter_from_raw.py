import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *
from ahrs.filters.complementary import Complementary
from ahrs.filters.madgwick import Madgwick
from ahrs.filters.mahony import Mahony
# from ahrs.filters.ekf import EKF
from ahrs.filters.ekf_custom import EKF

import argparse

GYRO_FOLDER = "calib_gyro/"
MAG_FOLDER = "calib_mag/"
DATASET_FOLDER = "imu_data/"

parser = argparse.ArgumentParser(description='Filter from raw')
parser.add_argument('-i', '--input', metavar='IN', help='Input folder', default=DATASET_FOLDER)
args = parser.parse_args()
print(args)

raw = np.load(args.input + '/raw.npy')
g, a, m = raw[:,0:3], raw[:,3:6], raw[:,6:9]

cal = np.load(GYRO_FOLDER + '/calib_gyro.npy')
g = np.array([[(r[0] - cal[0][0])*pi/180, (r[1] - cal[1][0])*pi/180, (r[2] - cal[2][0])*pi/180] for r in g])

cal_mag = np.load(MAG_FOLDER + '/calib_mag.npy')
m = np.array([[(r[0] - cal_mag[0][0])/cal_mag[0][1], (r[1] - cal_mag[1][0])/cal_mag[1][1], (r[2] - cal_mag[2][0])/cal_mag[2][1]] for r in m])
# m = np.array([[(r[1] - cal[1][0])/cal[1][1], (r[0] - cal[0][0])/cal[0][1], -(r[2] - cal[2][0])/cal[2][1]] for r in m])

# ahrs = Complementary(gyr=g, acc=a, mag=m, frame='ENU', gain=0.98, frequency=1000/45)
# ahrs = Madgwick(gyr=g, acc=a, mag=m, frame='ENU', frequency=1000/45)
# ahrs = Madgwick(gyr=g, acc=a, mag=m, frequency=1000/45)
# ahrs = Mahony(gyr=g, acc=a, mag=m, frequency=1000/45)
ahrs = EKF(gyr=g, acc=a, mag=m, frame='ENU', magnetic_ref=[0, cal_mag[3,0], -cal_mag[3,1]], frequency=1000/45)
# ahrs = EKF(gyr=g, acc=a, mag=m, frame='ENU', frequency=1000/45)
# ahrs = EKF(gyr=g, acc=a, frame='ENU', frequency=1000/45)

# print(ahrs.Q)

roll = []
pitch = []
yaw = []
for q in ahrs.Q:
    r,p,y = quaternion_to_euler(q[1],q[2],q[3],q[0])
    roll.append(r*180/pi)
    pitch.append(p*180/pi)
    yaw.append(y*180/pi)

x = np.linspace(0, len(g), len(g))

fig, (ax0,ax1,ax2)  = plt.subplots(3)
ax0.plot(x, g[:,0], label='gx')
ax0.plot(x, g[:,1], label='gy')
ax0.plot(x, g[:,2], label='gz')
ax0.legend()

ax1.plot(x, a[:,0], label='ax')
ax1.plot(x, a[:,1], label='ay')
ax1.plot(x, a[:,2], label='az')
ax1.legend()

ax2.plot(x, m[:,0], label='mx')
ax2.plot(x, m[:,1], label='my')
ax2.plot(x, m[:,2], label='mz')
ax2.legend()

fig, (ax0,ax1,ax2)  = plt.subplots(3)
ax0.plot(x, roll, label='roll')
ax0.set_ylim([-190, 190])
ax0.legend()

ax1.plot(x, pitch, label='pitch')
ax1.set_ylim([-190, 190])
ax1.legend()

ax2.plot(x, yaw, label='yaw')
ax2.set_ylim([-190, 190])
ax2.legend()

plt.show()