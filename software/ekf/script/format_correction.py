import numpy as np
from math import *

input = open("../sim/correction.txt", 'r')
output = open("correction.txt",'w')

def get_error_ellipse(covariance):
    eigenvals, eigenvects = np.linalg.eig(covariance[0:2,0:2])
    angle = atan2(eigenvects[1,0], eigenvects[0,0])
    return [angle, sqrt(abs(eigenvals[0])), sqrt(abs(eigenvals[1]))]

counter = 0
for line in input.readlines():
    print(counter)
    counter+=1
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
        cov = [float(c) for c in cov]
        cov = np.array([cov[:3],cov[3:6],cov[6:]])
        ellipse = get_error_ellipse(cov)
        ellipse[1] *= 50000
        ellipse[2] *= 50000
        print(ellipse)
        output.write("E " + str(ellipse[0]) + " " + str(ellipse[1]) + " " + str(ellipse[2]) +  " " + str(cov[2][2]) + "\r\n")

output.close()