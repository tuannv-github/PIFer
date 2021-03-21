import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *

DATASET_FOLDER = "imu_data/"

ax = np.load(DATASET_FOLDER + 'ax.npy')
ay = np.load(DATASET_FOLDER + 'ay.npy')
az = np.load(DATASET_FOLDER + 'az.npy')

print(normal(ax))
print(normal(ay))
print(normal(az)[0]-1)
