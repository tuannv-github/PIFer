from numpy import *
from math import *
from ekf import *

initial_state = array([1.5, 5.5, 0.0 / 180.0 * pi])
initial_covariance = diag([100.0**2, 100.0**2, (10.0 / 180.0 * pi) ** 2])
robot_width = 0.24
scanner_displacement = 0

control_motion_factor = 0.0  # Error in motor control.
control_turn_factor = 0.0  # Additional error due to slip when turning.
measurement_distance_stddev = 200.0  # Distance measurement error of cylinders.
measurement_angle_stddev = 15.0 / 180.0 * pi  # Angle measurement error.

ekf = ExtendedKalmanFilter(initial_state, initial_covariance, 
                                robot_width, scanner_displacement,
                                control_motion_factor, control_turn_factor,
                                measurement_distance_stddev, measurement_angle_stddev)

pule_per_revolution = 780
wheel_diameter = 0.065

file_control_measurement = open("control_measurement.txt")
file_prediction = open("prediction.txt", "w")

for line in file_control_measurement.readlines():
    cm = line.split(" ")
    if cm[0] == 'C':
        c0 = -(float(cm[1])/pule_per_revolution)*(pi*wheel_diameter)
        c1 = -(float(cm[2])/pule_per_revolution)*(pi*wheel_diameter)
        print((c0,c1))
        ekf.predict((c0,c1))

        file_prediction.write("F %f %f %f\n" % (ekf.state[0]*300, ekf.state[1]*300, ekf.state[2]))
        # Convert covariance matrix to angle stddev1 stddev2 stddev-heading form
        # e = ExtendedKalmanFilter.get_error_ellipse(covariances[i])
        # f.write("E %f %f %f %f\r\n" % (e + (sqrt(covariances[i][2,2]),)))