import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *
import statistics

DATASET_FOLDER = "calib_mag/"
raw = np.load(DATASET_FOLDER + 'raw.npy')
mx,my,mz = raw[:,6], raw[:,7], raw[:,8]

# mxb, mxs = statistics.mean(mx), statistics.stdev(mx)
# myb, mys = statistics.mean(my), statistics.stdev(my)
# mzb, mzs = statistics.mean(mz), statistics.stdev(mz)

mxb = (max(mx) + min(mx))/2.0
mxs = (max(mx) - min(mx))/2.0
myb = (max(my) + min(my))/2.0
mys = (max(my) - min(my))/2.0
mzb = (max(mz) + min(mz))/2.0
mzs = (max(mz) - min(mz))/2.0

calib_mag = np.array([[mxb, mxs], [myb, mys], [mzb, mzs]])

STABLE_FOLDER = "imu_data_stable/"
raw = np.load(STABLE_FOLDER + '/raw.npy')
g, a, m = raw[:,0:3], raw[:,3:6], raw[:,6:9]
mag = np.array([[(r[0] - calib_mag[0][0])/calib_mag[0][1], (r[1] - calib_mag[1][0])/calib_mag[1][1], (r[2] - calib_mag[2][0])/calib_mag[2][1]] for r in m])

# m_axis_north = sqrt(mag[0,0]**2 + mag[0,1]**2)
# m_axis_down = mag[0,2]
m_axis_north = np.mean([sqrt(m[0]**2 + m[1]**2) for m in mag])
m_axis_down = np.mean(mag[:,2])

calib_mag = np.r_[calib_mag, [[m_axis_north,m_axis_down]]]
print(calib_mag)
np.save(DATASET_FOLDER + 'calib_mag.npy', calib_mag)

x = np.linspace(0, len(mx), len(mx))

fig, (ax0)  = plt.subplots(1)
ax0.plot(mx,my,'ro',label='mxy',zorder=1)
ax0.plot(mx,mz,'go',label='mxz',zorder=1)
ax0.set_aspect('equal')
ax0.legend()

fig, (ax1,ax2,ax3)  = plt.subplots(3)
ax1.plot(x, mx, label='mx')
ax2.plot(x, my, label='my')
ax3.plot(x, mz, label='mz')

mx = [(m - mxb)/mxs for m in mx]
print((mxb,mxs))

my = [(m - myb)/mys for m in my]
print((myb,mys))

mz = [(m - mzb)/mzs for m in mz]
print((mzb,mzs))

cir = plt.Circle((mxb,myb), mxs,fill=False)
ax0.add_artist(cir)
cir = plt.Circle((mxb,myb), mys,fill=False)
ax0.add_artist(cir)

cir = plt.Circle((mxb,mzb), mxs,fill=False)
ax0.add_artist(cir)
cir = plt.Circle((mxb,mzb), mzs,fill=False)
ax0.add_artist(cir)

ax1.plot(x, [mxb]*len(x), label='mean_mx')
ax2.plot(x, [myb]*len(x), label='mean_my')
ax3.plot(x, [mzb]*len(x), label='mean_mz')

ax1.legend()
ax2.legend()
ax3.legend()

fig, (ax0)  = plt.subplots(1)
ax0.plot(mx,my,'ro',label='mxy')
ax0.plot(mx,mz,'go',label='mxz')
ax0.set_aspect('equal')
ax0.legend()

plt.show()
