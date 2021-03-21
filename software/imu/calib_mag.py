import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *
import statistics

DATASET_FOLDER = "imu_data/"

mx = np.load(DATASET_FOLDER + 'mx.npy')
my = np.load(DATASET_FOLDER + 'my.npy')
mz = np.load(DATASET_FOLDER + 'mz.npy')
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

# mxs = (max(mx) - min(mx))/2
# mxb = (max(mx) + min(mx))/2
mxs = statistics.stdev(mx)
mxb = statistics.mean(mx)
mx = [(m - mxb)/mxs for m in mx]
print((mxb,mxs))

# mys = (max(my) - min(my))/2
# myb = (max(my) + min(my))/2
mys = statistics.stdev(my)
myb = statistics.mean(my)
my = [(m - myb)/mys for m in my]
print((myb,mys))

# mzs = (max(mz) - min(mz))/2
# mzb = (max(mz) + min(mz))/2
mzs = statistics.stdev(mz)
mzb = statistics.mean(mz)
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
ax0.plot(mx,my,'ro')
ax0.plot(mx,mz,'go')
ax0.set_aspect('equal')

plt.show()
