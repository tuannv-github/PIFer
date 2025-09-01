# PIFWRobot

<p align="center">
  <img src="imgs/piflogo.png" width="100" title="PIF Logo">
</p>

PIFWRobot is an open source project for a two-wheeled self-balancing robot.

## Demo

Youtube:
* https://www.youtube.com/watch?v=qJoEQ5KJzxM&t=71s&pp=ygUjdHdvIHdoZWVsIHNlbGYgYmFsYW5jaW5nIHJvYm90IHR1YW4%3D
* https://www.youtube.com/watch?v=bJMFOIG7K60&t=61s

Without any velocity command, the robot is trying to stabilize itself. 
<p align="center">
  <img src="imgs/demo.gif" width="500" title="PIF Logo">
</p>

## Repository Contents
* **firmware**: 
  * **balancing-robot**: The entire firmware for STM32F103C8T6 MCU
  * **esp8266_arduino**: ESP8266 Arduino based TCP server firmware
* **software**:
  * **GCSQt**: A Qt-based ground control station for remote controlling, calibration, and PID tuning
  * **mavlink**: Mavlink message definitions and code generation tools
* **hardware**:
  * **board**: Altium-designed schematic and PCB source for the main board
  * **frame**: SolidWorks-based frame source for the robot

## Hardware
*  1 STM32F103C8T6
*  1 MPU6050/9250
*  2 DC Motors with Encoder
*  1 ESP8266 for remote control, calibration, and PID tuning
*  1 L298 DC Motor Driver
*  1 12V Li-po battery 

## PID algorithm
Cascade PID:
* Inner loop: tilt controller
  * Input: 
    * Tilt set point from outer loop
    * Feed back tilt from sensor (MPU6050/9250)
  * Output:
    * PWM duty cycle for both motors
* Outer loop: velocity controller
  * Input:
    * Velocity command from rthe emote controller
    * Feed back velocity from encoder
  * Output:
    * Tilt for inner loop

## License & copyright
@ Van Tuan Ngo, Ho Chi Minh City University of Technology

Licensed under the [MIT license](LICENSE)
