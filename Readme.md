# PIFWRobot

<p align="center">
  <img src="imgs/piflogo.png" width="100" title="PIF Logo">
</p>

PIFWRobot is an open source project for two-wheeled self-balancing robot.

## Demo
Without any velocity command, the robot is trying to stabilize its self. 
<p align="center">
  <img src="imgs/demo.gif" width="500" title="PIF Logo">
</p>

## Repository Contents
* **firmware**: 
  * **balancing-robot**: The entire firmware for STM32F103C8T6 MCU
  * **esp8266_arduino**: ESP8266 Arduino based TCP server firmware
* **software**:
  * **GCSQt**: A Qt based ground control station for remote controlling, calibration and PID tunning
  * **mavlink**: Mavlink message definitions and code generation tools
* **hardware**:
  * **board**: Altium Designed based schematic and PCB source for the main board
  * **frame**: SolidWorks based frame source for the robot

## Hardware
*  1 STM32F103C8T6
*  1 MPU6050/9250
*  2 DC Motors with Encoder
*  1 ESP8266 for remote control, calibration and PID tunning
*  1 L298 DC Motor Driver
*  1 12V Li-po battery 

## PID algorithm
Cascade PID:
* Inner loop: tilt controller
  * Input: 
    * Tilt set point from outer loop
    * Feed back tilt from sensor (MPU6050/9250)
  * Out put:
    * PWM duty circle for both motors
* Outer loop: velocity controller
  * Input:
    * Velocity command from remote controller
    * Feed back velocity from encoder
  * Output:
    * Tilt for inner loop

## License & copyright
@ Van Tuan Ngo, Ho Chi Minh City University of Technology

Licensed under the [MIT license](LICENSE)