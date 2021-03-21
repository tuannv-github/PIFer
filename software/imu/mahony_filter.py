import numpy as np
from matplotlib import pyplot as plt
from math import *

from euler_vs_quaternion import *
from ahrs.filters.mahony import Mahony
DATASET_FOLDER = "imu_data/"

r_roll = np.load(DATASET_FOLDER + 'roll.npy')
r_pitch = np.load(DATASET_FOLDER + 'pitch.npy')
r_yaw = np.load(DATASET_FOLDER + 'yaw.npy')

gx = np.load(DATASET_FOLDER + 'gx.npy')
gy = np.load(DATASET_FOLDER + 'gy.npy')
gz = np.load(DATASET_FOLDER + 'gz.npy')

ax = np.load(DATASET_FOLDER + 'ax.npy')
ay = np.load(DATASET_FOLDER + 'ay.npy')
az = np.load(DATASET_FOLDER + 'az.npy')

mx = np.load(DATASET_FOLDER + 'mx.npy')
my = np.load(DATASET_FOLDER + 'my.npy')
mz = np.load(DATASET_FOLDER + 'mz.npy')

g = np.array([gx, gy, gz]).T
a = np.array([ax, ay, az]).T
m = np.array([mx, my, mz]).T


ahrs = Mahony(gyr=g, acc=a, mag=m)
print(ahrs.Q)

roll = []
pitch = []
yaw = []
for q in ahrs.Q:
    r,p,y = quaternion_to_euler(q[0],q[1],q[2],q[3])
    roll.append(r)
    pitch.append(p)
    yaw.append(y)

x = np.linspace(0, len(r_roll), len(r_roll))

fig, (ax0,ax1,ax2)  = plt.subplots(3)
ax0.plot(x, gx, label='gx')
ax0.plot(x, gy, label='gy')
ax0.plot(x, gz, label='gz')
ax0.legend()

ax1.plot(x, ax, label='ax')
ax1.plot(x, ay, label='ay')
ax1.plot(x, az, label='az')
ax1.legend()

ax2.plot(x, mx, label='mx')
ax2.plot(x, my, label='my')
ax2.plot(x, mz, label='mz')
ax2.legend()

fig, (ax0,ax1,ax2)  = plt.subplots(3)
ax0.plot(x, r_roll, label='reference roll')
ax0.plot(x, roll, label='roll')
ax0.legend()

ax1.plot(x, r_pitch, label='reference pitch')
ax1.plot(x, pitch, label='pitch')
ax1.legend()

ax2.plot(x, r_yaw, label='reference yaw')
ax2.plot(x, yaw, label='yaw')
ax2.legend()

plt.show()