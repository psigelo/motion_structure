#include <armadillo>
#include <iostream>
#include "cinematica.hpp"

using namespace arma;
using namespace std;

enum MotorType{
	ROTX,
	ROTY,
	ROTZ,
	TRASX,
	TRASY,
	TRASZ
};

class Motor{
	private:
		int 		id;
		double 		angle;
		mat 		current_matrix; // Rotational matrix 4x4
		bool		direction;
		mat 		(*rotational_function)(double); 		
	public:
		Motor(int id, bool direction, double angle, MotorType type);
		int 	get_id						();
		void 	set_id 						(int id);
		double 	get_angle 					();
		void 	set_angle 					(double angle);
		bool	get_direction 				();
		void 	set_direction 				(bool dir);
		void 	calculate_current_matrix 	();
		mat 	get_current_matrix 			();
		mat 	calculate_matrix 			(double angle);
};