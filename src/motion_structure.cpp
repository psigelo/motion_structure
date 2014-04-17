#include "motion_structure.hpp"

#define DELTA_DERIVATIVE_FOR_JACOBIAN 0.000001

Motion_structure::Motion_structure(){
	motion_resolution = 0.001;
	current_xyz_position.push_back(0);
	current_xyz_position.push_back(0); 
	current_xyz_position.push_back(0);
}

Motion_structure::Motion_structure(double motion_resolution){
	this->motion_resolution = motion_resolution;
	current_xyz_position.push_back(0);
	current_xyz_position.push_back(0); 
	current_xyz_position.push_back(0);
}
int Motion_structure::get_motors_amount(){
	return motors_amount;
}
void Motion_structure::add_translation_structure(vector <double> xyz){
	order.push_back(LINK_SEGMENT);
	Link_segment lksg;
	lksg.set_matrix(traslacion(xyz));
	link_segment.push_back(lksg);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotation_x(double angle){
	order.push_back(LINK_SEGMENT);
	Link_segment lksg;
	lksg.set_matrix(rotx(angle));
	link_segment.push_back(lksg);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotation_y(double angle){

	order.push_back(LINK_SEGMENT);
	Link_segment lksg;
	lksg.set_matrix(roty(angle));
	link_segment.push_back(lksg);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotation_z(double angle){
	order.push_back(LINK_SEGMENT);
	Link_segment lksg;
	lksg.set_matrix(rotz(angle));
	link_segment.push_back(lksg);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_motor_x(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	motors.push_back(Motor(motor_id, direction, initial_angle, ROTX));
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_motor_y(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	motors.push_back(Motor(motor_id, direction, initial_angle, ROTY));
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_motor_z(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	motors.push_back(Motor(motor_id, direction, initial_angle, ROTZ));
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_traslational_motor_x(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	motors.push_back(Motor(motor_id, direction, initial_angle, TRASX));
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_traslational_motor_y(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	motors.push_back(Motor(motor_id, direction, initial_angle, TRASY));
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_traslational_motor_z(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	motors.push_back(Motor(motor_id, direction, initial_angle, TRASZ));
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	current_position_matrix = calculate_position(current_angles);
}
mat Motion_structure::calculate_position(vector <double> angles){
	int motors_counter(0);
	int segment_counter(0);
	mat result = mat(4,4);
	result.eye(); // Result is an identity matrix 4x4.
	for (int i = 0; i < (int)order.size(); ++i)
	{;
		if(order[i] == 0){
			result = result*( link_segment.at(segment_counter++).get_matrix() ); 
		}
		else if(order[i] == 1){
			result = result*(motors.at(motors_counter).calculate_matrix(angles.at(motors_counter)));
			motors_counter++;
		}
		else{
			cerr << "In function Motion_structure::calculate_position ::: order[i] have a inposible number" << endl;
			exit(1);
		}
	}
	return result;
}
void Motion_structure::calculate_position_set_values(vector <double> angles){
	int motors_counter(0);
	int segment_counter(0);
	mat result = mat(4,4);
	result.eye(); // Result is an identity matrix 4x4.
	for (int i = 0; i < (int)order.size(); ++i)
	{
		if(order[i] == 0){
			result = result*( link_segment.at(segment_counter++).get_matrix() ); 
		}
		else if(order[i] == 1){
			result = result*(motors.at(motors_counter).calculate_matrix(angles.at(motors_counter)));
			motors_counter++;
		}
		else{
			cerr << "In function Motion_structure::calculate_position ::: order[i] have a inposible number" << endl;
			exit(1);
		}
	}
	current_position_matrix = result;
	current_xyz_position.at(0) = current_position_matrix(0,3);
	current_xyz_position.at(1) = current_position_matrix(1,3);
	current_xyz_position.at(2) = current_position_matrix(2,3); 
}
mat Motion_structure::get_current_matrix			(){
	return current_position_matrix;
}

Movement Motion_structure::move_to_xyz_position	(vector <double> xyz_position, double velocity){
	Movement result = Movement();
	vector <double> angulos_movement(motors_amount);
	vector <double> velocity_movement(motors_amount);
	mat M_angulos_proximos(motors_amount,1);
	mat M_velocidades_motores;
	mat M_jacobiano;
	mat M_velocidad;
	mat M_pendiente;
	vector <double> pendiente;
	double distance;
	distance		= distancia 		(current_xyz_position, xyz_position);
	pendiente 		= vector_pendiente 	(current_xyz_position, xyz_position);
	M_pendiente << pendiente.at(0) << endr
				<< pendiente.at(1) << endr
				<< pendiente.at(2) << endr;	
	M_velocidad << pendiente.at(0)*velocity << endr
				<< pendiente.at(1)*velocity << endr 
				<< pendiente.at(2)*velocity << endr;
	for(int i=0; i< motors_amount; i++){
		M_angulos_proximos.at(i) = current_angles.at(i);
	}

	double i=0.0;
	while(i < distance){ 
		M_jacobiano 			=  jacobiano_motores();
		M_angulos_proximos 		=  solve(M_jacobiano,(M_pendiente*motion_resolution)) + M_angulos_proximos;
		M_velocidades_motores 	=  solve(M_jacobiano,M_velocidad);
		for(int j=0; j < motors_amount; j++){
		    angulos_movement.at(j)  = acondicionar_angulos(M_angulos_proximos(j,0));
		    velocity_movement.at(j) = fabs(M_velocidades_motores(j,0));
		}
		result.add_to_list_motor_angle_positions(angulos_movement);
		result.add_to_list_motor_velocities(velocity_movement);
		current_angles 			= angulos_movement;
		current_position_matrix = calculate_position(current_angles);
		i = i + motion_resolution; 
	}	

    return result;
}




mat Motion_structure::jacobiano_motores(){
	mat punta_result_dt[ motors_amount ];
	mat d_punta_result_dt[ motors_amount ];
	mat jacobiano(3, motors_amount);
	for(int i = 0; i < (int)current_angles.size(); i++){

		current_angles.at(i) 	= current_angles.at(i) + DELTA_DERIVATIVE_FOR_JACOBIAN;
		punta_result_dt[i] 		= calculate_position(current_angles);
		d_punta_result_dt[i] 	= (punta_result_dt[i]- current_position_matrix)/DELTA_DERIVATIVE_FOR_JACOBIAN;
		current_angles.at(i) 	= current_angles.at(i) - DELTA_DERIVATIVE_FOR_JACOBIAN;
	}
	for(int i = 0; i < (int)current_angles.size(); i++){
		for(int j=0; j < 3; j++){
			jacobiano(j,i) = d_punta_result_dt[i](j,3);
		}
	}
	return jacobiano;
}

