import numpy as np
from math import *

input = open("../sim/prediction.txt", 'r')
output = open("prediction.txt",'w')

def get_error_ellipse(covariance):
    eigenvals, eigenvects = np.linalg.eig(covariance[0:2,0:2])
    angle = atan2(eigenvects[1,0], eigenvects[0,0])
    return (angle, sqrt(eigenvals[0]), sqrt(eigenvals[1]))  

for line in input.readlines():
    char = line.split(" ")
    if char[0] == 'F':
        x = float(char[1])
        y = float(char[2])
        w = float(char[3])
        x = (x*1000) + 2000
        y = (y*1000) + 2000
        w = (w)
        print((x,y,w))
        output.write("F " + str(x) + " " + str(y) + " " + str(w) + "\r\n")
    elif char[0] == 'E':
        cov = char[1:]
        cov = [float(c)*10**5 for c in cov]
        cov = np.array([cov[:3],cov[3:6],cov[6:]])
        elipse = get_error_ellipse(cov)
        print(elipse)
        output.write("E " + str(elipse[0]) + " " + str(elipse[1]) + " " + str(elipse[2]) +  " " + str(cov[2][2]) + "\r\n")
