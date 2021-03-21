import pandas as pd
from matplotlib import pyplot as plt
import numpy as np
import os

from euler_vs_quaternion import *

DATASET_FOLDER = "imu_data/"
try:
    os.mkdir(DATASET_FOLDER)
except:
    pass

data = pd.read_csv("Sample9DoF_R_Session1_Shimmer_B663_Calibrated_SD.csv", sep='\t')

for column in data.columns: 
    print(column)

# reference = data[["Shimmer_B663_Quat_Madge_9DOF_W_LN_CAL", 
#                 "Shimmer_B663_Quat_Madge_9DOF_X_LN_CAL",
#                 "Shimmer_B663_Quat_Madge_9DOF_Y_LN_CAL",
#                 "Shimmer_B663_Quat_Madge_9DOF_Z_LN_CAL"]]

data = data.drop(data.index[0])

roll=[]
pitch=[]
yaw=[]

gx = []
gy = []
gz = []

ax = []
ay = []
az = []

mx = []
my = []
mz = []

for row in data.iterrows():
    x = float(row[1]["Shimmer_B663_Quat_Madge_9DOF_X_LN_CAL"])
    y = float(row[1]["Shimmer_B663_Quat_Madge_9DOF_Y_LN_CAL"])
    z = float(row[1]["Shimmer_B663_Quat_Madge_9DOF_Z_LN_CAL"])
    w = float(row[1]["Shimmer_B663_Quat_Madge_9DOF_W_LN_CAL"])
    r,p,y = quaternion_to_euler(x,y,z,w)
    roll.append(r)
    pitch.append(p)
    yaw.append(y)

    gx.append(float(row[1]["Shimmer_B663_Gyro_X_CAL"])/180*np.pi)
    gy.append(float(row[1]["Shimmer_B663_Gyro_Y_CAL"])/180*np.pi)
    gz.append(float(row[1]["Shimmer_B663_Gyro_Z_CAL"])/180*np.pi)

    ax.append(float(row[1]["Shimmer_B663_Accel_WR_X_CAL"]))
    ay.append(float(row[1]["Shimmer_B663_Accel_WR_Y_CAL"]))
    az.append(float(row[1]["Shimmer_B663_Accel_WR_Z_CAL"]))

    # ax.append(float(row[1]["Shimmer_B663_Accel_LN_X_CAL"]))
    # ay.append(float(row[1]["Shimmer_B663_Accel_LN_Y_CAL"]))
    # az.append(float(row[1]["Shimmer_B663_Accel_LN_Z_CAL"]))

    mx.append(float(row[1]["Shimmer_B663_Mag_X_CAL"]))
    my.append(float(row[1]["Shimmer_B663_Mag_Y_CAL"]))
    mz.append(float(row[1]["Shimmer_B663_Mag_Z_CAL"]))

roll = np.array(roll)
pitch = np.array(pitch)
yaw = np.array(yaw)
np.save(DATASET_FOLDER + 'roll.npy', roll)
np.save(DATASET_FOLDER + 'pitch.npy', pitch)
np.save(DATASET_FOLDER + 'yaw.npy', yaw)

gx = np.array(gx)
gy = np.array(gy)
gz = np.array(gz)
np.save(DATASET_FOLDER + 'gx.npy', gx)
np.save(DATASET_FOLDER + 'gy.npy', gy)
np.save(DATASET_FOLDER + 'gz.npy', gz)

ax = np.array(ax)
ay = np.array(ay)
az = np.array(az)
np.save(DATASET_FOLDER + 'ax.npy', ax)
np.save(DATASET_FOLDER + 'ay.npy', ay)
np.save(DATASET_FOLDER + 'az.npy', az)

mx = np.array(mx)
my = np.array(my)
mz = np.array(mz)
np.save(DATASET_FOLDER + 'mx.npy', mx)
np.save(DATASET_FOLDER + 'my.npy', my)
np.save(DATASET_FOLDER + 'mz.npy', mz)

x = np.linspace(0, len(roll), len(roll))

fig, (ax0,ax1,ax2,ax3)  = plt.subplots(4)
ax0.plot(x, roll, label='roll')
ax0.plot(x, pitch, label='pitch')
ax0.plot(x, yaw, label='yaw')
ax0.legend()

ax1.plot(x, gx, label='gx')
ax1.plot(x, gy, label='gy')
ax1.plot(x, gz, label='gz')
ax1.legend()

ax2.plot(x, ax, label='ax')
ax2.plot(x, ay, label='ay')
ax2.plot(x, az, label='az')
ax2.legend()

ax3.plot(x, mx, label='mx')
ax3.plot(x, my, label='my')
ax3.plot(x, mz, label='mz')
ax3.legend()

plt.show()