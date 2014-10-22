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
	lksg.set_matrix(traslation(xyz));
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

RotMatrix Motion_structure::calculate_position(vector <double> angles){
	int motors_counter(0);
	int segment_counter(0);
	double identity[16] = {1.0,0.0,0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0};
	RotMatrix result(identity);
	for (int i = 0; i < (int)order.size(); ++i)
	{;
		if(order[i] == 0){
			result = result*( link_segment.at(segment_counter++).get_matrix() ); 
		}
		else if(order[i] == 1){
			result = result*(motors.at(motors_counter).calculateMatrix(angles.at(motors_counter)));
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
	double identity[16] = {1.0,0.0,0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0};
	RotMatrix result(identity);
	for (int i = 0; i < (int)order.size(); ++i)
	{
		if(order[i] == 0){
			result = result*( link_segment.at(segment_counter++).get_matrix() ); 
		}
		else if(order[i] == 1){
			result = result*(motors.at(motors_counter).calculateMatrix(angles.at(motors_counter)));
			motors_counter++;
		}
		else{
			cerr << "In function Motion_structure::calculate_position ::: order[i] have a inposible number" << endl;
			exit(1);
		}
	}
	current_position_matrix = result;
	double * xyz = current_position_matrix.get_xyz();
	current_xyz_position.at(0) = xyz[0];
	current_xyz_position.at(1) = xyz[1];
	current_xyz_position.at(2) = xyz[2]; 
}

RotMatrix Motion_structure::get_current_matrix			(){
	return current_position_matrix;
}

void Motion_structure::move_to_xyz_position	(vector <double> xyz_position, double velocity, Movement * _movement){
	cerr << "1" << endl;
	vector <double> angulos_movement(motors_amount);
	vector <double> velocity_movement(motors_amount);

	double jacobiano[3*motors_amount];

	double angulosProximos[motors_amount];
	double * pendiente;
	double velocidad[3];
	double deltaXYZ[3];
	double velocidadMotores[motors_amount];
	double distance;
	distance		= distancia 		(current_xyz_position, xyz_position);
	pendiente 		= vector_pendiente 	(current_xyz_position, xyz_position);
	velocidad[0] = pendiente[0]*velocity;
	velocidad[1] = pendiente[1]*velocity;
	velocidad[2] = pendiente[2]*velocity;
	deltaXYZ[0]  = pendiente[0]*motion_resolution;
	deltaXYZ[1]  = pendiente[1]*motion_resolution;
	deltaXYZ[2]  = pendiente[2]*motion_resolution;

	cerr << "2" << endl;
	for(int i=0; i< motors_amount; i++)
		angulosProximos[i] = current_angles.at(i);
	
	cerr << "3" << endl;
	double i=0.0;
	while(i < distance){ 
		cerr << "3.1" << endl;
		jacobiano_motores(jacobiano);
		cerr << "3.2" << endl;
		choleskySolver(motors_amount, jacobiano, deltaXYZ, angulosProximos, velocidad, velocidadMotores ) ; // juntar los dos calculos en una sola expresion
		cerr << "3.3" << endl;
		for(int j=0; j < motors_amount; j++){
		    angulos_movement.at(j)  = acondicionar_angulos(angulosProximos[j]);
		    velocity_movement.at(j) = fabs(velocidadMotores[j]);
		}
		cerr << "3.4" << endl;
		_movement->add_to_list_motor_angle_positions(angulos_movement);
		_movement->add_to_list_motor_velocities(velocity_movement);
		current_angles 			= angulos_movement;
		calculate_position_set_values(current_angles);
		i = i + motion_resolution; 
		cerr << "3.5" << endl;
	}	
		
	_movement->set_time_between_two_points_millisecons( (distance/velocity)*1000.0 ); 
}
void Motion_structure::move_delta_xyz_position	(vector <double> delta_xyz_position, double velocity, Movement * _movement){
	vector < double > real_position;
	real_position.push_back(current_xyz_position.at(0) +  delta_xyz_position.at(0));
	real_position.push_back(current_xyz_position.at(1) +  delta_xyz_position.at(1));
	real_position.push_back(current_xyz_position.at(2) +  delta_xyz_position.at(2));
	return move_to_xyz_position	(real_position, velocity, _movement);
}


/*
	Ver si la idea de back propagation de redes neuronales puede ser usada aca para hacer menos calculos 

	IDEA a implementar: para calcular la derivada de la ultimo motor solo se requiere variar el ultimo motor luego 
	la mayor parte del calculo ya esta hecho .... (es imitar backpropagation ... tomara tiempo
	programarlo pero puede ser mucho mas optimo)
*/
void Motion_structure::jacobiano_motores(double jacobiano[]){
	double * punta_result_dt;
	for(int i = 0; i < motors_amount; i++){
		current_angles.at(i) += DELTA_DERIVATIVE_FOR_JACOBIAN;
		punta_result_dt 		= calculate_position(current_angles).get_xyz();
		current_angles.at(i) -= DELTA_DERIVATIVE_FOR_JACOBIAN;
		jacobiano[i] = (punta_result_dt[0] - current_xyz_position.at(0))/DELTA_DERIVATIVE_FOR_JACOBIAN;
		jacobiano[motors_amount + i] = (punta_result_dt[1] - current_xyz_position.at(1))/DELTA_DERIVATIVE_FOR_JACOBIAN;
		jacobiano[2*motors_amount + i] = (punta_result_dt[2] - current_xyz_position.at(2))/DELTA_DERIVATIVE_FOR_JACOBIAN;
	}
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
#endif