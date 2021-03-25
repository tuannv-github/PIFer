from math import *
from numpy import array, dot, eye, zeros, linalg, size, diag

class ExtendedKalmanFilter:

    def __init__(self, state, covariance):
        self.state = state
        self.covariance = covariance

    def set_control_params(self, robot_width, control_motion_factor, control_turn_factor):
        self.robot_width = robot_width
        self.control_motion_factor = control_motion_factor
        self.control_turn_factor = control_turn_factor

    def set_measurement_params(self, scanner_displacement, measurement_distance_stddev, measurement_angle_stddev):
        self.scanner_displacement = scanner_displacement
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
            theta_ = theta + alpha
            rpw2 = l/alpha + w/2.0
            m = array([[1.0, 0.0, rpw2*(cos(theta_) - cos(theta))],
                       [0.0, 1.0, rpw2*(sin(theta_) - sin(theta))],
                       [0.0, 0.0, 1.0]])
        else:
            m = array([[1.0, 0.0, -l*sin(theta)],
                       [0.0, 1.0,  l*cos(theta)],
                       [0.0, 0.0,  1.0]])
        return m

    @staticmethod
    def dg_dcontrol(state, control, w):
        theta = state[2]
        l, r = tuple(control)
        if r != l:
            rml = r - l
            rml2 = rml * rml
            theta_ = theta + rml/w
            dg1dl = w*r/rml2*(sin(theta_)-sin(theta))  - (r+l)/(2*rml)*cos(theta_)
            dg2dl = w*r/rml2*(-cos(theta_)+cos(theta)) - (r+l)/(2*rml)*sin(theta_)
            dg1dr = (-w*l)/rml2*(sin(theta_)-sin(theta)) + (r+l)/(2*rml)*cos(theta_)
            dg2dr = (-w*l)/rml2*(-cos(theta_)+cos(theta)) + (r+l)/(2*rml)*sin(theta_)
            
        else:
            dg1dl = 0.5*(cos(theta) + l/w*sin(theta))
            dg2dl = 0.5*(sin(theta) - l/w*cos(theta))
            dg1dr = 0.5*(-l/w*sin(theta) + cos(theta))
            dg2dr = 0.5*(l/w*cos(theta) + sin(theta))

        dg3dl = -1.0/w
        dg3dr = 1.0/w
        m = array([[dg1dl, dg1dr], [dg2dl, dg2dr], [dg3dl, dg3dr]])

        return m

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
        alpha = state[2]

        return array([r, alpha])

    @staticmethod
    def dh_dstate(state, landmark, scanner_displacement):
        theta = state[2]
        cos_t, sin_t = cos(theta), sin(theta)
        dx = landmark[0] - (state[0] + scanner_displacement * cos_t)
        dy = landmark[1] - (state[1] + scanner_displacement * sin_t)
        q = dx * dx + dy * dy
        sqrt_q = sqrt(q)
        dr_dx = -dx / sqrt_q
        dr_dy = -dy / sqrt_q
        dr_dtheta = (dx * sin_t - dy * cos_t) * scanner_displacement / sqrt_q

        return array([[dr_dx, dr_dy, dr_dtheta], [0,0,1]])

    def correct(self, measurement, landmark):
        H = self.dh_dstate(self.state, landmark, self.scanner_displacement)
        Q = array([[self.measurement_distance_stddev**2,0],[0,self.measurement_angle_stddev**2]])
        
        innovation = array(measurement) - self.h(self.state, landmark, self.scanner_displacement)
        innovation[1] = (innovation[1] + pi) % (2*pi) - pi

        # print(self.state)
        # print(landmark)
        # print(measurement)
        # print(self.h(self.state, landmark, self.scanner_displacement))
        # print(innovation)

        K = dot(self.covariance,dot(H.T, linalg.inv(dot(H, dot(self.covariance,H.T))+Q)))
        self.state = self.state + dot(K, innovation)
        self.covariance = dot(eye(3) - dot(K,H), self.covariance)

        # print(self.state)
        # print("-------")

    def get_state(self):
        return self.state[0:3]

    def get_state_covariance(self):
        return self.covariance[0:3, 0:3]

    @staticmethod
    def get_error_ellipse(covariance):
        """Return the position covariance (which is the upper 2x2 submatrix)
           as a triple: (main_axis_angle, stddev_1, stddev_2), where
           main_axis_angle is the angle (pointing direction) of the main axis,
           along which the standard deviation is stddev_1, and stddev_2 is the
           standard deviation along the other (orthogonal) axis."""
        eigenvals, eigenvects = linalg.eig(covariance[0:2,0:2])
        angle = atan2(eigenvects[1,0], eigenvects[0,0])
        return [angle, sqrt(eigenvals[0]), sqrt(eigenvals[1])]
