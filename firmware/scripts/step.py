import numpy as np
import math

stepperrevolution = 200

# def stepsperresolution(ratio)
#     return stepsperresolution / ratio

def step(d,ratio):
    P = d * 3.14
    stepperrev = stepperrevolution / ratio
    steppermetter = 1/P * stepperrev
    return steppermetter,P


# so xung/meter 5459.508644222019
# van toc truyen xuong m/s
# so xung /s =  5459.508644222019 * vantocdat
# 1/f * n_pulses = T




def pwm(f,vmax):
    pulsepersecond = 5459.508644222019 * vmax
    k = 1/pulsepersecond
    n = k * f
    return n 





if __name__ == '__main__':
    steps,p = step(0.07,1/6)
    print(steps)
    print(p)
    number = pwm(1000000,0.3)
    print(number)
