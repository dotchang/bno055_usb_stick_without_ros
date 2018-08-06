# bno055_usb_stick_without_ros
This is a fork of https://github.com/yoshito-n-students/bno055_usb_stick
, without ROS. Tested on Windows10 64bit MSVC environment.

## Device
Bosch BNO055 USB Stick http://www.mouser.jp/new/bosch/bosch-bno055-usb-stick/

## Dependencies
bno055_usb_stick_msgs https://github.com/dotchang/bno055_usb_stick_msgs

## Published Topics
No ROS topics.

## Parameters
~publish_tf (bool, default: false)

~fixed_frame_id (string, default: "fixed")

~frame_id (string, default: "bno055")

~port (string, default: "COM3")

~timeout (float, default: 1.0)
* timeout on serial port communication in seconds

~mode (string, default: "ndof")
* "nodf": estimate absolute orientation with an accelerometer, gyroscope, and magnetometer
* "imu": estimate relative orientation with an accelerometer and gyroscope

## Troubleshooting
`[ERROR] []: start: open: Permission denied`
* give permission to the current user by `sudo usermod -aG dialout $USER`. This command is for ubuntu 16.04 and may vary for other environments.
