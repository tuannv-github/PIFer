Protocol generator
```
cd mavlink
python -m pymavlink.tools.mavgen --lang=C --wire-protocol=1.0 --output=../../../firmware/PIFWRobot/Core/Src/application/mav/mavlink   ../protocol.xml
python -m pymavlink.tools.mavgen --lang=C --wire-protocol=1.0 --output=../../../software/GCSQt/MAV   ../protocol.xml
python -m pymavlink.tools.mavgen --lang=Java --wire-protocol=1.0 --output=../../../software/android/app/src/main/java/com/MAVLink ../protocol.xml
python -m pymavlink.tools.mavgen --lang=Python --wire-protocol=1.0 --output=../../../software/imu/mavlink ../protocol.xml
python -m pymavlink.tools.mavgen --lang=Python --wire-protocol=1.0 --output=../../../software/ekf/mavlink ../protocol.xml
```
