#include <stdio.h>
#include <iostream>
#include <vector>
#include <armadillo> 
#include "cinematica.hpp"
#include "movement.hpp"
#include "link_segment.hpp"
#include "motor.hpp"
// if you want compile you need install armadillo library
// armadillo is easy to install, please see http://arma.sourceforge.net/
// After of the installation, in the Makefile you have to use -larmadillo flag to compile.




using namespace std;
using namespace arma;









class Motion_structure{
	public:
							Motion_structure			(); // motion_resolution = default
							Motion_structure			(double motion_resolution);
		vector <double> 	get_initial_angles			();
		void 				set_initial_angles			(vector <double> _initial_angles);
		vector <double> 	get_current_angles			();
		void				set_current_angles			(vector <double> _current_angles);
		int 				get_motors_amount			();
		double 				get_motion_resolution		();
		void				set_motion_resolution		(double _motion_resolution);
		vector <double>		get_xyz_current_position	();
		void 				add_translation_structure	(vector <double> xyz);
		void 				add_rotation_x				(double angle);
		void 				add_rotation_y				(double angle);
		void 				add_rotation_z				(double angle);
		void 				add_rotational_motor_x		(int motor_id, bool direction, double initial_angle); //true direction is positive
		void 				add_rotational_motor_y		(int motor_id, bool direction, double initial_angle);
		void 				add_rotational_motor_z		(int motor_id, bool direction, double initial_angle);
		void 				add_traslational_motor_x	(int motor_id, bool direction, double initial_large);
		void 				add_traslational_motor_y	(int motor_id, bool direction, double initial_large);
		void 				add_traslational_motor_z	(int motor_id, bool direction, double initial_large);
		void 				set_motors_angles			(vector <double> motor_angles);
		void 				set_angle_to_motor_id		(int id, double angle);		
		mat 				get_current_matrix			(); // Obtain the current matrix whitout calculate, from the memory.
		void 				calculate_current_position_matrix(); // Calculate and save in current_position_matrix;
		mat 				calculate_position 			(vector <double> angles);
		void 				calculate_position_set_values(vector <double> angles);
		Movement 			move_to_xyz_position		(vector <double> xyz_position, double velocity);
		Movement			move_delta_xyz_position		(vector <double> delta_xyz_position, double velocity);
		mat 				jacobiano_motores			();

	
	private:
		int						motors_amount;
		vector <double> 		initial_angles;
		vector <double> 		current_angles;
		double					motion_resolution;
		vector < Link_segment > link_segment;
		vector < Motor > 		motors;
		vector < double >		order;
		mat 					current_position_matrix; // Rotational matrix 4x4 
		mat 					matrix_initial_angles;
		vector <double>			current_xyz_position; 
};




