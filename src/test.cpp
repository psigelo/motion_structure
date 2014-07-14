#include "motion_structure.hpp"

#include <sys/time.h> // para ver los tiempos.


double getTimeSimulation(timeval final, timeval init)
{
	return (double)((final.tv_sec-init.tv_sec)*1000.0+(final.tv_usec-init.tv_usec)/1000.0)/1000.0;
}


int main(){

	timeval init;
	timeval final;

	gettimeofday(&init,NULL);
	gettimeofday(&final,NULL);



	Motion_structure * estructura = new Motion_structure();
	estructura->add_rotational_motor_z(1, true, 0.0);
	vector <double> xyz;
	xyz.push_back(1);
	xyz.push_back(0);
	xyz.push_back(0);
	estructura->add_translation_structure(xyz);
	estructura->add_rotational_motor_y(2, true, 0.0);
	xyz.at(2) = -1;
	estructura->add_translation_structure(xyz);
	estructura->add_rotational_motor_y(3, true, 0.0);
	estructura->add_translation_structure(xyz);

	gettimeofday(&final,NULL);

	cerr << getTimeSimulation(final,init) << endl;





	//cout << estructura->get_current_matrix() << endl;
	vector <double> motor_angles;
	motor_angles.push_back(M_PI/6);
	motor_angles.push_back(M_PI/6);
	motor_angles.push_back(M_PI/6);

	gettimeofday(&final,NULL);

	cerr << getTimeSimulation(final,init) << endl;

	//cout << estructura->calculate_position (motor_angles) << endl;
	Movement movimiento;
	xyz.at(0)	=	0.8660;
	xyz.at(1)	=	0.5000;
	xyz.at(2)	=	-2.7321;
	movimiento =  estructura->move_to_xyz_position(xyz, 1);

	gettimeofday(&final,NULL);

	cerr << getTimeSimulation(final,init) << endl;
	
	cout << movimiento.get_length_position() << endl;
	return 0;
}