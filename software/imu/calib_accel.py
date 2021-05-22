import numpy as np
from matplotlib import pyplot as plt
from math import *

from utils import *
import statistics

DATASET_FOLDER = "calib_accel/"

raw = np.load(DATASET_FOLDER + 'raw.npy')
ax,ay,az = raw[:,3], raw[:,4], raw[:,5]

f = open(DATASET_FOLDER + "calib_accel.txt", 'w')

axb, axs = statistics.mean(ax), statistics.stdev(ax)
ayb, ays = statistics.mean(ay), statistics.stdev(ay)
azb, azs = statistics.mean(az), statistics.stdev(az)

f.write(str(axb) + " " + str(axs)+ "\n")
f.write(str(ayb) + " " + str(ayb)+ "\n")
f.write(str(azb) + " " + str(azb)+ "\n")

print([axb, axs])
print([ayb, ays])
print([azb, azs])
