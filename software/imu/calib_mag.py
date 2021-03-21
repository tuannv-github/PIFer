import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *

DATASET_FOLDER = "imu_data/"

mx = np.load(DATASET_FOLDER + 'mx.npy')
my = np.load(DATASET_FOLDER + 'my.npy')
mz = np.load(DATASET_FOLDER + 'mz.npy')

mxs = (max(mx) - min(mx))/2
mxb = (max(mx) + min(mx))/2
mx = [(m - mxb)/mxs for m in mx]
print((mxb,mxs))

mys = (max(my) - min(my))/2
myb = (max(my) + min(my))/2
my = [(m - myb)/mys for m in my]
print((myb,mys))

mzs = (max(mz) - min(mz))/2
mzb = (max(mz) + min(mz))/2
mz = [(m - mzb)/mzs for m in mz]
print((mzb,mzs))

plt.plot(mx,my,'ro')
plt.plot(mx,mz,'go')
plt.gca().set_aspect('equal')

plt.show()
