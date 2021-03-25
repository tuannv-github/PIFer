from math import *

A = [[0, 0, 3],
    [13.2, 0, 3],
    [0, 3.6, 3],
    [13.2, 3.6, 3]]

x = 0.0
y = 0.6
z = 0
for a in A:
    d = sqrt((x-a[0])**2 + (y-a[1])**2 + (z-a[2])**2)
    print(d)