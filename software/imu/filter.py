import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *
from ahrs.filters.complementary import Complementary
from ahrs.filters.madgwick import Madgwick
from ahrs.filters.mahony import Mahony

DATASET_FOLDER = "imu_data/"

gx_bias = (-0.9616763967158748, 0.01716347107127141)
gy_bias = (0.6969435718363407, 0.02303707571665565)
gz_bias = (-0.732405328727236, 0.023635633242456173)

(mxb,mxs) = (4.873015403747559, 33.21147632598877)
(myb,mys) = (31.487179204821587, 31.936996057629585)
(mzb,mzs) = (-96.86056137084961, 30.287670135498047)

ax_bias = -0.04373004872311828
ay_bias = -0.014944331437211982
az_bias = -0.016872704853110654

r_roll = np.load(DATASET_FOLDER + 'roll.npy')
r_pitch = np.load(DATASET_FOLDER + 'pitch.npy')
r_yaw = np.load(DATASET_FOLDER + 'yaw.npy')

gx = np.load(DATASET_FOLDER + 'gx.npy')
gy = np.load(DATASET_FOLDER + 'gy.npy')
gz = np.load(DATASET_FOLDER + 'gz.npy')
gx = [(g-gx_bias[0])/180.0*pi for g in  gx]
gy = [(g-gy_bias[0])/180.0*pi for g in  gy]
gz = [(g-gz_bias[0])/180.0*pi for g in  gz]

ax = np.load(DATASET_FOLDER + 'ax.npy')
ay = np.load(DATASET_FOLDER + 'ay.npy')
az = np.load(DATASET_FOLDER + 'az.npy')
ax = [a-ax_bias for a in  ax]
ay = [a-ay_bias for a in  ay]
az = [a-az_bias for a in  az]

mx = np.load(DATASET_FOLDER + 'mx.npy')
my = np.load(DATASET_FOLDER + 'my.npy')
mz = np.load(DATASET_FOLDER + 'mz.npy')
mx = [(m - mxb)/mxs for m in mx]
my = [(m - myb)/mys for m in my]
mz = [(m - mzb)/mzs for m in mz]

g = np.array([gx, gy, gz]).T
a = np.array([ax, ay, az]).T
m = np.array([mx, my, mz]).T

# ahrs = Complementary(gyr=g, acc=a, mag=m, gain=0.02, frequency=1000/45)
ahrs = Madgwick(gyr=g, acc=a, mag=m, frequency=1000/45)
# ahrs = Mahony(gyr=g, acc=a, mag=m, frequency=1000/45)

print(ahrs.Q)

roll = []
pitch = []
yaw = []
for q in ahrs.Q:
    r,p,y = quaternion_to_euler(q[1],q[2],q[3],q[0])
    roll.append(r*180/pi)
    pitch.append(p*180/pi)
    yaw.append(y*180/pi)

x = np.linspace(0, len(gx), len(gx))
rx = np.linspace(0, len(r_roll), len(r_roll))

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
ax0.plot(rx, r_roll, label='reference roll')
ax0.plot(x, roll, label='roll')
# ax0.set_ylim([-pi-0.1, pi+0.1])
ax0.set_ylim([-190, 190])
ax0.legend()

ax1.plot(rx, r_pitch, label='reference pitch')
ax1.plot(x, pitch, label='pitch')
# ax1.set_ylim([-pi-0.1, pi+0.1])
ax1.set_ylim([-190, 190])
ax1.legend()

ax2.plot(rx, r_yaw, label='reference yaw')
ax2.plot(x, yaw, label='yaw')
# ax2.set_ylim([-pi-0.1, pi+0.1])
ax2.set_ylim([-190, 190])
ax2.legend()

plt.show()