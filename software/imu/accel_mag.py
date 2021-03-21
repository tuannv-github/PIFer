import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *

DATASET_FOLDER = "imu_data/"

# r_roll = np.load(DATASET_FOLDER + 'roll.npy')
# r_pitch = np.load(DATASET_FOLDER + 'pitch.npy')
# r_yaw = np.load(DATASET_FOLDER + 'yaw.npy')

# gx_bias = (-0.9616763967158748, 0.01716347107127141)
# gy_bias = (0.6969435718363407, 0.02303707571665565)
# gz_bias = (-0.732405328727236, 0.023635633242456173)

gx = np.load(DATASET_FOLDER + 'gx.npy')
gy = np.load(DATASET_FOLDER + 'gy.npy')
gz = np.load(DATASET_FOLDER + 'gz.npy')

# gx = [(g-gx_bias[0])/180.0*pi for g in  gx]
# gy = [(g-gy_bias[0])/180.0*pi for g in  gy]
# gz = [(g-gz_bias[0])/180.0*pi for g in  gz]

ax = np.load(DATASET_FOLDER + 'ax.npy')
ay = np.load(DATASET_FOLDER + 'ay.npy')
az = np.load(DATASET_FOLDER + 'az.npy')

mx = np.load(DATASET_FOLDER + 'mx.npy')
my = np.load(DATASET_FOLDER + 'my.npy')
mz = np.load(DATASET_FOLDER + 'mz.npy')

roll = []
pitch = []
yaw = []

for i in range(0, len(ay)):
    r = atan2(ay[i], az[i])
    p = atan2(-ax[i], sqrt(ay[i]**2 + az[i]**2))

    by = my[i]*cos(p) - mz[i]*sin(p)
    bx = mx[i]*cos(r) + my[i]*sin(r)*sin(p) + mz[i]*sin(r)*cos(p)
    print((-by,bx))
    y = atan2(-by, bx)

    roll.append(r*180/pi)
    pitch.append(p*180/pi)
    yaw.append(y*180/pi)

x = np.linspace(0, len(gx), len(gx))

fig, (ax0,ax1,ax2)  = plt.subplots(3)
# ax0.plot(x, r_roll, label='reference roll')
ax0.plot(x, roll, label='roll')
ax0.legend()

# ax1.plot(x, r_pitch, label='reference pitch')
ax1.plot(x, pitch, label='pitch')
ax1.legend()

# ax2.plot(x, r_yaw, label='reference yaw')
ax2.plot(x, yaw, label='yaw')
ax2.legend()

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

plt.show()