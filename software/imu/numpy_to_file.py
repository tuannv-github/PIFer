import numpy as np

DATASET_FOLDER = "imu_data/"

r_roll = np.load(DATASET_FOLDER + 'roll.npy')
r_pitch = np.load(DATASET_FOLDER + 'pitch.npy')
r_yaw = np.load(DATASET_FOLDER + 'yaw.npy')

gx = np.load(DATASET_FOLDER + 'gx.npy')
gy = np.load(DATASET_FOLDER + 'gy.npy')
gz = np.load(DATASET_FOLDER + 'gz.npy')
f = open(DATASET_FOLDER + "g.txt", 'w')
for i in range(0, len(gx)):
    f.write("%f %f %f\n" % (gx[i], gy[i], gz[i]))

ax = np.load(DATASET_FOLDER + 'ax.npy')
ay = np.load(DATASET_FOLDER + 'ay.npy')
az = np.load(DATASET_FOLDER + 'az.npy')
f = open(DATASET_FOLDER + "a.txt", 'w')
for i in range(0, len(ax)):
    f.write("%f %f %f\n" % (ax[i], ay[i], az[i]))

mx = np.load(DATASET_FOLDER + 'mx.npy')
my = np.load(DATASET_FOLDER + 'my.npy')
mz = np.load(DATASET_FOLDER + 'mz.npy')
f = open(DATASET_FOLDER + "m.txt", 'w')
for i in range(0, len(mx)):
    f.write("%f %f %f\n" % (mx[i], my[i], mz[i]))
