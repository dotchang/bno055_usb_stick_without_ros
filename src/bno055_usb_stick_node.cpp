#include <string>

#include "bno055_usb_stick/bno055_usb_stick.hpp"
#include "bno055_usb_stick/decoder.hpp"
#include "bno055_usb_stick_msgs/Output.h"

#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

namespace bus = bno055_usb_stick;

void publish(const bno055_usb_stick_msgs::Output &output, const std::string &fixed_frame_id) {
	std::cout << "time: "
	   		  << output.header.stamp << std::endl;
	std::cout << "Acc: "
			  << output.acceleration.x << " "
			  << output.acceleration.y << " " 
			  << output.acceleration.z << std::endl;
	std::cout << "Mag: "
			  << output.magnetometer.x << " "
			  << output.magnetometer.y << " "
			  << output.magnetometer.z << std::endl;
	std::cout << "Gyr: "
			  << output.gyroscope.x << " "
			  << output.gyroscope.y << " " 
			  << output.gyroscope.z << std::endl;
	std::cout << "Eur: "
			  << output.euler_angles.x << " "
			  << output.euler_angles.y << " "
			  << output.euler_angles.z << std::endl;
	std::cout << "Qua: "
			  << output.quaternion.x() << " "
			  << output.quaternion.y() << " "
			  << output.quaternion.z() << " "
			  << output.quaternion.w() << std::endl;
	std::cout << "Lia: "
			  << output.linear_acceleration.x << " "
			  << output.linear_acceleration.y << " "
			  << output.linear_acceleration.z << std::endl;
	std::cout << "Grv: "
			  << output.gravity_vector.x << " "
			  << output.gravity_vector.y << " " 
			  << output.gravity_vector.z << std::endl;
	std::cout << "Temp: "
			  << output.temperature << std::endl;
	std::cout << "CalibStat: "
			  << output.calibration_status.w << " "
			  << output.calibration_status.x << " "
			  << output.calibration_status.y << " "
			  << output.calibration_status.z << std::endl;
}

int main(int argc, char *argv[]) {
  // load parameters
  const std::string fixed_frame_id("fixed");
  
  // construct the worker
  boost::asio::io_service asio_service;
  bus::BNO055USBStick device(asio_service, boost::bind(publish, _1, fixed_frame_id));

  // run the worker
  while (1) {
    asio_service.run_one();
  }

  return 0;
}
