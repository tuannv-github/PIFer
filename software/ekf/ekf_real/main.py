from numpy import *
from math import *
from ekf import *
from utils import *

pule_per_revolution = 780
wheel_diameter = 0.065

file_control_measurement = open("control_measurement.txt")
file_prediction = open("prediction.txt", "w")

ranges = []
x = []
yaw = 0
for line in file_control_measurement.readlines():
    cm = line.split(" ")
    if cm[0] == 'M':
        x = float(cm[1])
        y = float(cm[2])
        z = 3.0
        r = float(cm[4])
        yaw = float(cm[5])*pi/180
        ranges.append((x,y,z,r))
    if(len(ranges)>=3):
        P = trilaterate(ranges)
        x = P[1]
        break
print((x,yaw))

initial_state = array([x[0], x[1], yaw])
initial_covariance = diag([0.1**2, 0.1**2, (50.0 / 180.0 * pi) ** 2])
robot_width = 0.24
scanner_displacement = 0.05

control_motion_factor = 0.001
control_turn_factor = 0.001
measurement_distance_stddev = 0.05
measurement_angle_stddev = 10.0 / 180.0 * pi

ekf = ExtendedKalmanFilter(initial_state, initial_covariance)
ekf.set_control_params(robot_width, control_motion_factor, control_turn_factor)
ekf.set_measurement_params(scanner_displacement, measurement_distance_stddev, measurement_angle_stddev)

file_control_measurement = open("control_measurement.txt")
tmp = open("tmp.txt", 'w')
cnt = 0
for line in file_control_measurement.readlines():
    cm = line.split(" ")
    if cm[0] == 'C':
        c0 = -(float(cm[1])/pule_per_revolution)*(pi*wheel_diameter)
        c1 = -(float(cm[2])/pule_per_revolution)*(pi*wheel_diameter)

        ekf.predict((c0,c1))
        # file_prediction.write("F %f %f %f\n" % (ekf.state[0]*300+500, ekf.state[1]*300+1000, ekf.state[2]))
        # file_prediction.write("F %f %f %f\n" % (ekf.state[0], ekf.state[1], ekf.state[2]))

    elif cm[0] == 'M':
        x = float(cm[1])
        y = float(cm[2])
        z = float(cm[3])
        r = float(cm[4])
        if x==0 and y==0:
            continue
        yaw = float(cm[5])*pi/180
        r = r**2-3**2
        if r > 0:
            r = sqrt(r)
            m = (r,yaw)
            l = (x,y)
            tmp.write(str((m,l)) + '\r')
            ekf.correct(m, l)
            file_prediction.write("F %f %f %f\n" % (ekf.state[0]*300+500, ekf.state[1]*300+1000, ekf.state[2]))

            e = ExtendedKalmanFilter.get_error_ellipse(ekf.covariance)
            e[1]*=3*10**4
            e[2]*=3*10**4
            e.append(sqrt(ekf.covariance[2,2]))
            file_prediction.write("E %f %f %f %f\n" % tuple(e))