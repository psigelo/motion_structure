#ifndef MOTION_STRUCTURE_CPP
#define MOTION_STRUCTURE_CPP


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

Motion_structure::Motion_structure(char * path, double motion_resolution){
	this->motion_resolution = motion_resolution;
	current_xyz_position.push_back(0);
	current_xyz_position.push_back(0); 
	current_xyz_position.push_back(0);

	load(path);
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
	Motor * motor = new Motor(motor_id, direction, initial_angle, ROTX);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_motor_y(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	Motor * motor = new Motor(motor_id, direction, initial_angle, ROTY);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_motor_z(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	Motor * motor = new Motor(motor_id, direction, initial_angle, ROTZ);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_traslational_motor_x(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	Motor * motor = new Motor(motor_id, direction, initial_angle, TRASX);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_traslational_motor_y(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	Motor * motor = new Motor(motor_id, direction, initial_angle, TRASY);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_traslational_motor_z(int motor_id, bool direction, double initial_angle){
	order.push_back(MOTOR);
	Motor * motor = new Motor(motor_id, direction, initial_angle, TRASZ);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	current_position_matrix = calculate_position(current_angles);
}










/*

	POR TEMA DE APUROS SE REPLICARAN LAS MISMAS FUNCIONES DE ARRIBA PERO PARA DYNAMIXEL-
	LA IDEA ES LOGGRAR UN MEJOR ENFOQUE EN OTRA VERSIÓN.

*/

void Motion_structure::add_rotational_dynamixelAx12_x(int motor_id, bool direction, double initial_angle, int fd){
	order.push_back(MOTOR);
	dynamixelAX12 * motor = new dynamixelAX12(motor_id, direction, initial_angle, ROTX,fd);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_dynamixelAx12_y(int motor_id, bool direction, double initial_angle, int fd){
	order.push_back(MOTOR);
	dynamixelAX12 * motor = new dynamixelAX12(motor_id, direction, initial_angle, ROTY,fd);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
}
void Motion_structure::add_rotational_dynamixelAx12_z(int motor_id, bool direction, double initial_angle, int fd){
	order.push_back(MOTOR);
	dynamixelAX12 * motor = new dynamixelAX12(motor_id, direction, initial_angle, ROTZ,fd);
	motors.push_back(motor);
	motors_amount++;
	initial_angles.push_back(initial_angle);
	current_angles.push_back(initial_angle);
	calculate_position_set_values(current_angles);
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
			result = result*(motors.at(motors_counter)->calculate_matrix(motors.at(motors_counter)->get_direction_value()*angles.at(motors_counter)));
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
			result = result*(motors.at(motors_counter)->calculate_matrix(angles.at(motors_counter)));
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

	result.set_time_between_two_points_millisecons( (distance/velocity)*1000.0 );
	result.set_reference_to_motors( getReferenceToMotors() );
	
    return result;
}

Movement Motion_structure::move_delta_xyz_position	(vector <double> delta_xyz_position, double velocity){
	vector < double > real_position;
	real_position.push_back(current_xyz_position.at(0) +  delta_xyz_position.at(0));
	real_position.push_back(current_xyz_position.at(1) +  delta_xyz_position.at(1));
	real_position.push_back(current_xyz_position.at(2) +  delta_xyz_position.at(2));
	return move_to_xyz_position	(real_position, velocity);
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


void Motion_structure::print_current_xyz_position(){
	cerr << "current position: ( " << current_xyz_position.at(0) << " , " << current_xyz_position.at(1) << " , " << current_xyz_position.at(2) << ")" << endl;
}


void Motion_structure::load(char * path){
	int id = 1;

	FILE * fle = fopen(path, "r");
	int amount_of_elements;
	if(fscanf(fle, "%d \n", &amount_of_elements)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}

	for (int i = 0; i < amount_of_elements; ++i)
	{
		int type; // 1: motor rotacional   2:conector rotacional    3: Motor traslacional     4:conector traslacional
		if(fscanf(fle,"%d", &type)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}

		if(type == 1 || type == 3){ //Motor 
			int direction; // Positive or Negative
			if(fscanf(fle,"%d", &direction)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}

			int axis; // 1: X   2: Y  3: Z
			if(fscanf(fle,"%d", &axis)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}

			double initial_pos;
			if(fscanf(fle,"%lf", &initial_pos)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}


			if(type == 1){ // Rotational Motor
				if(axis == 1){ // axis: X
					add_rotational_motor_x(id++, direction, initial_pos);
				}
				else if(axis == 2){// axis: Y
					add_rotational_motor_y(id++, direction, initial_pos);
				}
				else if(axis == 3){// axis: Z
					add_rotational_motor_z(id++, direction, initial_pos);
				}
				else{
					cerr << "Motion_structure::load::error al cargar estructura" << endl;
					exit(1);
				}
			}

			else if(type == 3){ // Traslational Motor
				if(axis == 1){ // axis: X
					add_traslational_motor_x(id++, direction, initial_pos);
				}
				else if(axis == 2){// axis: Y
					add_traslational_motor_y(id++, direction, initial_pos);
				}
				else if(axis == 3){// axis: Z
					add_traslational_motor_z(id++, direction, initial_pos);
				}
				else{
					cerr << "Motion_structure::load::error al cargar estructura" << endl;
					exit(1);
				}
			}
		}
		else if(type == 2){
			int axis; // 1: X   2: Y  3: Z
			if(fscanf(fle,"%d", &axis)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}

			double position;
			if(fscanf(fle,"%lf", &position)  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}

			if(axis == 1){ // axis: X
				add_rotation_x(position);
			}
			else if(axis == 2){// axis: Y
				add_rotation_y(position);
			}
			else if(axis == 3){// axis: Z
				add_rotation_z(position);
			}
			else{
				cerr << "Motion_structure::load::error al cargar estructura" << endl;
				exit(1);
			}
			
		}
		else if(type == 4){
			vector <double> position;
			position.push_back(0);
			position.push_back(0);
			position.push_back(0);
			if(fscanf(fle,"%lf %lf %lf", &position.at(0), &position.at(1), &position.at(2))  == EOF){cerr << "Motion_structure::load::error al cargar estructura" << endl;exit(1);}
			
			add_translation_structure	(position);
		}
		else{
			cerr << "Motion_structure::load::error al cargar estructura" << endl;
			exit(1);
		}

	}
}



int * Motion_structure::getCorrespondMotorIds(){
	unsigned int motorsAmount = motors.size();
	int * resultado = (int *)malloc(sizeof(int)*motorsAmount);
	for (unsigned int i = 0; i < motorsAmount; ++i)
	{
		resultado[i] = motors.at(i)->getMotorId();
	}
	return resultado;
}

vector < Motor * > & Motion_structure::getReferenceToMotors(){
	return motors;
}




#endif