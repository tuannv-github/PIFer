import numpy as np

def trilaterate(ranges):
    p0=np.array(ranges[0][:3])
    p1=np.array(ranges[1][:3])
    p2=np.array(ranges[2][:3])

    d0=ranges[0][-1]
    d1=ranges[1][-1]
    d2=ranges[2][-1]

    pt0 = [0,0,0]
    pt1 = p1 - p0
    pt2 = p2 - p0

    U = np.linalg.norm(pt1)
    e_x = pt1/U
    Vx = np.dot(pt2, e_x)
    pt2y = (pt2 - Vx*e_x)
    Vy  = np.linalg.norm(pt2y)
    e_y = pt2y / Vy
    e_z = np.cross(e_x, e_y)

    x  = (d0**2 - d1**2 + U**2) / (2*U)
    y  = (d0**2 - d2**2 + Vx**2 + Vy**2 - 2*Vx*x)/(2*Vy)
    z0 = np.sqrt(d0**2 - x**2 - y**2)
    z1 = -z0

    PA=p0+(x*e_x)+(y*e_y)+(z0*e_z)
    PB=p0+(x*e_x)+(y*e_y)+(z1*e_z)

    return [PA, PB]
