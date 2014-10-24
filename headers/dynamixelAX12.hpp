#ifndef DYN_AX12_H
#define DYN_AX12_H

#include "dynamixelAX12Utils.hpp"
#include "motor.hpp"
#include <cmath>

class dynamixelAX12 : public Motor {
	public:
		dynamixelAX12(int _id, bool direction, double angle, MotorType type , int _fd);
		void move(double position, double velocity) override;
	private:
		int fd;
};

#endif