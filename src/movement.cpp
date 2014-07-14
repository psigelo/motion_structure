#include "movement.hpp"

Movement::Movement(){
	length_position = 0;
	length_velocity = 0;
}

int Movement::get_length_position(){
	return length_position;
}

int Movement::get_length_velocity(){
	return length_velocity;
}

void Movement::add_to_list_motor_angle_positions( 	vector <double> angle_position_data	){
	list_motor_angle_positions.push_back(angle_position_data);
	length_position++;
}

vector <double>	Movement::get_from_list_motor_angle_position( int position){
	return list_motor_angle_positions.at(position);
	
}

void Movement::add_to_list_motor_velocities( 	vector <double> velocity_data	){
	list_motor_velocities.push_back(velocity_data);
	length_velocity++;
}

vector <double>	Movement::get_from_list_motor_velocities( int position){
	return list_motor_velocities.at(position);
}

void Movement::clear_movement(){
	list_motor_velocities.clear();
	list_motor_angle_positions.clear();
}

void Movement::set_time_between_two_points_millisecons(double tiempo_total_del_movimiento){
	time_between_two_points_millisecons = tiempo_total_del_movimiento / (double)list_motor_velocities.size();
}



int Movement::get_time_between_tw0_points_millisecons(){
	return (int)time_between_two_points_millisecons;
}
