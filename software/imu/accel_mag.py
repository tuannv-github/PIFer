import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *

import argparse

GYRO_FOLDER = "calib_gyro/"
MAG_FOLDER = "calib_mag/"
DATASET_FOLDER = "imu_data_roll/"

parser = argparse.ArgumentParser(description='Filter from raw')
parser.add_argument('-i', '--input', metavar='IN', help='Input folder', default=DATASET_FOLDER)
args = parser.parse_args()
print(args)

raw = np.load(args.input + '/raw.npy')
g, a, m = raw[:,0:3], raw[:,3:6], raw[:,6:9]

cal = np.load(GYRO_FOLDER + '/calib_gyro.npy')
g = np.array([[(r[0] - cal[0][0])*pi/180, (r[1] - cal[1][0])*pi/180, (r[2] - cal[2][0])*pi/180] for r in g])

cal = np.load(MAG_FOLDER + '/calib_mag.npy')
m = np.array([[(r[0] - cal[0][0])/cal[0][1], (r[1] - cal[1][0])/cal[1][1], (r[2] - cal[2][0])/cal[2][1]] for r in m])
# m = np.array([[(r[1] - cal[1][0])/cal[1][1], (r[0] - cal[0][0])/cal[0][1], -(r[2] - cal[2][0])/cal[2][1]] for r in m])

roll = []
pitch = []
yaw = []
for i in range(0, len(a)):
    r = atan2(a[i,1], a[i,2])
    p = atan2(-a[i][0], sqrt(a[i,1]**2 + a[i,2]**2))

    by = m[i,1]*cos(p) - m[i,2]*sin(p)
    bx = m[i,0]*cos(r) + m[i,1]*sin(r)*sin(p) + m[i,2]*sin(r)*cos(p)
    y = atan2(-by, bx)

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