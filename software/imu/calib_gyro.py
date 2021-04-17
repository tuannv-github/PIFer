import numpy as np
from math import *

from utils import *
import statistics

DATASET_FOLDER = "calib_gyro/"

raw = np.load(DATASET_FOLDER + 'raw.npy')
gx,gy,gz = raw[:,0], raw[:,1], raw[:,2]

gxb, gxs = statistics.mean(gx), statistics.stdev(gx)
gyb, gys = statistics.mean(gy), statistics.stdev(gy)
gzb, gzs = statistics.mean(gz), statistics.stdev(gz)

calib_gyro = np.array([[gxb, gxs], [gyb, gys], [gzb, gzs]])

np.save(DATASET_FOLDER + 'calib_gyro.npy', calib_gyro)

print([gxb, gxs])
print([gyb, gys])
print([gzb, gzs])
