import numpy as np
from matplotlib import pyplot as plt
from math import *

DATASET_FOLDER = "imu_data/"

def variance(data):
    # Number of observations
    n = len(data)
    # Mean of the data
    mean = sum(data) / n
    # Square deviations
    deviations = [(x - mean) ** 2 for x in data]
    # Variance
    variance = sum(deviations) / n
    return mean, variance

gx = np.load(DATASET_FOLDER + 'gx.npy')
gy = np.load(DATASET_FOLDER + 'gy.npy')
gz = np.load(DATASET_FOLDER + 'gz.npy')

print(variance(gx))
print(variance(gy))
print(variance(gz))
