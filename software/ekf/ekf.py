from numpy import *
from math import *

class ExtendedKalmanFilter:
    def __init__(self, state, covariance,
                 robot_width, scanner_displacement,
                 control_motion_factor, control_turn_factor,
                 measurement_distance_stddev, measurement_angle_stddev):
        # The state. This is the core data of the Kalman filter.
        self.state = state
        self.covariance = covariance

        # Some constants.
        self.robot_width = robot_width

        self.scanner_displacement = scanner_displacement
        self.control_motion_factor = control_motion_factor
        self.control_turn_factor = control_turn_factor
        self.measurement_distance_stddev = measurement_distance_stddev
        self.measurement_angle_stddev = measurement_angle_stddev

    @staticmethod
    def g(state, control, w):
        x, y, theta = state
        l, r = control
        if r != l:
            alpha = (r - l) / w
            rad = l/alpha
            g1 = x + (rad + w/2.)*(sin(theta+alpha) - sin(theta))
            g2 = y + (rad + w/2.)*(-cos(theta+alpha) + cos(theta))
            g3 = (theta + alpha + pi) % (2*pi) - pi
        else:
            g1 = x + l * cos(theta)
            g2 = y + l * sin(theta)
            g3 = theta

        return array([g1, g2, g3])

    @staticmethod
    def dg_dstate(state, control, w):
        theta = state[2]
        l, r = control
        if r != l:
            alpha = (r-l)/w
            R = l/alpha
            g00 = 1
            g01 = 0
            g02 = (R + w/2)*(cos(theta+alpha)-cos(theta))
            g10 = 0
            g11 = 1
            g12 = (R + w/2)*(sin(theta+alpha)-sin(theta))
            g20 = 0
            g21 = 0
            g22 = 1
            m = array([[g00, g01, g02], [g10, g11, g12], [g20, g21, g22]])
        else:
            g00 = 1
            g01 = 0
            g02 = -l*sin(theta)
            g10 = 0
            g11 = 1
            g12 = l*cos(theta)
            g20 = 0
            g21 = 0
            g22 = 1
            m = array([[g00, g01, g02], [g10, g11, g12], [g20, g21, g22]])
        return m

    @staticmethod
    def dg_dcontrol(state, control, w):
        theta = state[2]
        l, r = tuple(control)
        if r != l:
            alpha = (r - l) / w
            g00 = (w*r/(r-l)**2)*(sin(theta+alpha)-sin(theta))  - ((r+l)/(2*(r-l)))*cos(theta+alpha)
            g01 = (-w*l/(r-l)**2)*(sin(theta+alpha)-sin(theta)) + ((r+l)/(2*(r-l)))*cos(theta+alpha)
            g10 = (w*r/(r-l)**2)*(-cos(theta+alpha)+cos(theta)) - ((r+l)/(2*(r-l)))*sin(theta+alpha)
            g11 = (-w*l/(r-l)**2)*(-cos(theta+alpha)+cos(theta)) + ((r+l)/(2*(r-l)))*sin(theta+alpha)
            g20 = -1/w
            g21 = 1/w
            m = array([[g00, g01], [g10, g11], [g20, g21]]) 
        else:   
            g00 = (1/2)*(cos(theta)+(l/w)*sin(theta))
            g01 = (1/2)*(cos(theta)-(l/w)*sin(theta))
            g10 = (1/2)*(sin(theta)-(l/w)*cos(theta))
            g11 = (1/2)*(sin(theta)+(l/w)*cos(theta))
            g20 = 0
            g21 = 0
            m = array([[g00, g01], [g10, g11], [g20, g21]])     
        return m

    @staticmethod
    def get_error_ellipse(covariance):
        eigenvals, eigenvects = linalg.eig(covariance[0:2,0:2])
        angle = atan2(eigenvects[1,0], eigenvects[0,0])
        return (angle, sqrt(eigenvals[0]), sqrt(eigenvals[1]))        

    def predict(self, control):

        left, right = control
        sigma_l_square = (self.control_motion_factor*left)**2 + (self.control_turn_factor*(left-right))**2
        sigma_r_square = (self.control_motion_factor*right)**2 + (self.control_turn_factor*(right-left))**2
        self.control_covariance = diag([sigma_l_square, sigma_r_square])

        G = self.dg_dstate(self.state, control, self.robot_width)
        V = self.dg_dcontrol(self.state, control, self.robot_width)

        self.state = self.g(self.state, control, self.robot_width)
        self.covariance = dot(dot(G,self.covariance), G.T) + dot(dot(V,self.control_covariance),V.T)

    @staticmethod
    def h(state, landmark, scanner_displacement):

        dx = landmark[0] - (state[0] + scanner_displacement * cos(state[2]))
        dy = landmark[1] - (state[1] + scanner_displacement * sin(state[2]))
        r = sqrt(dx * dx + dy * dy)
        alpha = (atan2(dy, dx) - state[2] + pi) % (2*pi) - pi

        return array([r, alpha])

    @staticmethod
    def dh_dstate(state, landmark, scanner_displacement):
        x, y, theta = state
        x_m, y_m = landmark
        x_l = x + scanner_displacement*cos(theta)
        y_l = y + scanner_displacement*sin(theta)
        delta_x = x_m - x_l
        delta_y = y_m - y_l
        q = delta_x**2 + delta_y**2
        sqrt_q = sqrt(q)

        h00 = -delta_x/sqrt_q
        h01 = -delta_y/sqrt_q
        h02 = scanner_displacement*(delta_x*sin(theta) - delta_y*cos(theta))/sqrt_q

        return array([[h00, h01, h02]])

    def correct(self, measurement, landmark):
        H = self.dh_dstate(self.state, landmark, self.scanner_displacement)
        Q = array([[self.measurement_distance_stddev**2]])
        
        innovation = array(measurement) - self.h(self.state, landmark, self.scanner_displacement)
        innovation = array([innovation[0]])

        K = dot(self.covariance,dot(H.T, linalg.inv(dot(H, dot(self.covariance,H.T))+Q)))
        self.state = self.state + dot(K, innovation)
        self.covariance = dot(eye(3) - dot(K,H), self.covariance)