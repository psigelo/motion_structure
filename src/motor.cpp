#ifndef MOTOR_CPP
#define MOTOR_CPP

#include "motor.hpp"


Motor::Motor(int id, bool direction, double angle, MotorType motor_type){
	this->id = id;
	this->angle = angle;
	this->direction = direction;

	if(motor_type == ROTX)
		rotational_function = rotx;
	else if (motor_type == ROTY)
		rotational_function = roty;
	else if (motor_type == ROTZ)
		rotational_function = rotz;
	else if(motor_type == TRASX)
		rotational_function = traslacionx;
	else if (motor_type == TRASY)
		rotational_function = traslaciony;
	else if (motor_type == TRASZ)
		rotational_function = traslacionz;
	else{
		cerr << "In function Motor::Motor :::: the type of the motor is incorrect" << endl;
		exit(1);
	}
}


mat Motor::calculate_matrix(double angle){
	return (*rotational_function)(angle);
}


double Motor::get_direction_value(){
	return (direction)?1.0:-1.0;
}
#endif