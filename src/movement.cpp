#ifndef MOVEMENT_CPP
#define MOVEMENT_CPP

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

void Movement::really_move_to_position_from_list( int positionInList ){
	int motorsAmount = referenceToMotors.size();

	vector <double> motorsVelocities = list_motor_velocities.at(positionInList);
	vector <double> motorsPositions = list_motor_angle_positions.at(positionInList);

	/* 
		Con el fin de hacer más rápida la comunicación pudiera ser necesario
		alguna implementación acá para que el controlador del robot sea avisado 
		de que se moverán sus motores para que éste almacene todas las posiciones y 
		velocidades de todos los motores que va a mover para moverlos todos juntos después.
	*/
	for (int i = 0; i < motorsAmount; ++i)
	{
		//cerr << i << endl;
		referenceToMotors.at(i)->move( motorsPositions.at(i), motorsVelocities.at(i) );
	}
	/* 
		Con el fin de hacer más rápida la comunicación pudiera ser necesario
		alguna implementación acá para que el controlador del robot sea avisado 
		de que se moverán sus motores para que éste almacene todas las posiciones y 
		velocidades de todos los motores que va a mover para moverlos todos juntos después.

		->ACÁ se debería avisar que ya fueron setiadas las posiciones y las velocidades y que se puede mover el robot.
	*/
}

void Movement::set_correspond_motors_ids(int * _motorIds){
	motorIds = _motorIds;
}

void Movement::set_reference_to_motors( vector <Motor *>  & _referenceToMotors ){
	referenceToMotors = _referenceToMotors;
}

/*
	Imprime las cosas escenciales del movimiento, no todos los datos.
	
	-lista de ids
	-cantidad de posiciones
	-tiempo entre dos puntos

*/
void Movement::print_stats (){
	cout << "Printing a movement stats: \nMotor list Ids: " ;
	int motorsAmount = referenceToMotors.size();
	for (int i = 0; i < motorsAmount; ++i)
	{
		cout << referenceToMotors.at(i)->getMotorId() << "\t";
	}
	cout << "\nAmount Of positions and velocities: " << length_position << "\ntime between two points millisecons: " << time_between_two_points_millisecons << endl;  
}

/*
	Se imprimen los todos los datos. notar que posiciones son en [radianes] y velocidad [radianes/seg]
*/

void Movement::print_all (){
	cout << "Printing a movement stats: \nMotor list Ids: " ;
	int motorsAmount = referenceToMotors.size();
	for (int i = 0; i < motorsAmount; ++i)
	{
		cout << referenceToMotors.at(i)->getMotorId() << "\t";
	}
	cout << "\nAmount Of positions and velocities: " << length_position << "\ntime between two points millisecons: " << time_between_two_points_millisecons << endl;  

	for (int j = 0; j < length_position; ++j)
	{
		cout << "position" << j << ": {";
		for (int i = 0; i < motorsAmount; ++i)
		{
			cout << list_motor_angle_positions.at(j).at(i) << ((i + 1 < motorsAmount) ?  ", " : ""); 
		}
		cout << "}\n";
	}

}


#endif