#ifndef MOTION_STRUCTURE_HPP
#define MOTION_STRUCTURE_HPP

#include <stdio.h>
#include <iostream>
#include <vector>
#include <armadillo> 
#include "cinematica.hpp"
#include "movement.hpp"
#include "link_segment.hpp"
#include "motor.hpp"
#include "dynamixelAX12.hpp"
// if you want compile you need install armadillo library
// armadillo is easy to install, please see http://arma.sourceforge.net/
// After of the installation, in the Makefile you have to use -larmadillo flag to compile.

using namespace std;
using namespace arma;


class Motion_structure{
	public:
		/**
			\brief Setea los valores por defecto de una estructura: Posición inicial (0,0,0) y resolucion de movimiento 0.001.
		*/
							Motion_structure			(); // motion_resolution = default 
		/**
			\brief Setea el valor de la resolución de movimiento y pone la posición inicial en (0,0,0).
		*/
							Motion_structure			(double motion_resolution);
		/**
			\brief Se carga la configuración previamente realizada en la GUI desde la ruta especificada y se setea la resolución del movimiento.
		*/
							Motion_structure			(char * path, double motion_resolution);
		/**
			\brief Devuelve los ángulos iniciales que tuvo la estructura en su inicio.
		*/
		vector <double> 	get_initial_angles			();
		/**
			\brief se setean los angulos iniciales de cada motor dentro de la estructura.
			\param 	_initial_angles vector con los angulos iniciales de todos los motores. (debe tener el mismo largo que la cantidad de motores).
		*/
		void 				set_initial_angles			(vector <double> _initial_angles);
		/**
			\brief Obtiene los angulos actuales de los motores.
		*/
		vector <double> 	get_current_angles			();
		/**
			\brief Se setean los angulos de los motores.
			\param _current_angles angulos que deben tener los motores.
		*/
		void				set_current_angles			(vector <double> _current_angles);
		/**
			\brief Obtiene la cantidad de motores de la estructura.
		*/
		int 				get_motors_amount			();
		/**
			\brief Obtiene la resolución del movimiento.
		*/
		double 				get_motion_resolution		();
		/**
			\brief Setea la resolución del movimiento.
		*/
		void				set_motion_resolution		(double _motion_resolution);
		/**
			\brief Obtiene la posición en coordenadas cartecianas.
		*/
		vector <double>		get_xyz_current_position	();
		/**
			\brief Agrega una estructura de tipo traslación.
		*/
		void 				add_translation_structure	(vector <double> xyz);
		/**
			\brief agrega una rotación en x a la estructura.
		*/
		void 				add_rotation_x				(double angle);
		/**
			\brief agrega una rotación en x a la estructura.
		*/
		void 				add_rotation_y				(double angle);
		/**
		\brief agrega una rotación en x a la estructura.
		*/
		void 				add_rotation_z				(double angle);
		/**
			\brief Agrega un motor rotacional
		*/
		void 				add_rotational_motor_x		(int motor_id, bool direction, double initial_angle); //true direction is positive
		/**
			\brief Agrega un motor rotacional
		*/
		void 				add_rotational_motor_y		(int motor_id, bool direction, double initial_angle);
		/**
			\brief Agrega un motor rotacional
		*/
		void 				add_rotational_motor_z		(int motor_id, bool direction, double initial_angle);
		/**
			\brief agrega un motor traslacional
		*/
		void 				add_traslational_motor_x	(int motor_id, bool direction, double initial_large);
		/**
			\brief agrega un motor traslacional
		*/
		void 				add_traslational_motor_y	(int motor_id, bool direction, double initial_large);
		/**
			\brief agrega un motor traslacional
		*/
		void 				add_traslational_motor_z	(int motor_id, bool direction, double initial_large);
		/**
			\brief Se setean los angulos de los motores de la estructura.
		*/
		void 				set_motors_angles			(vector <double> motor_angles);
		/**
			\brief Se setea el ángulo del motor con id específica.
		*/
		void 				set_angle_to_motor_id		(int id, double angle);		
		/**
			\brief Obtiene la matriz rotcacional final después de el calculo.
		*/
		mat 				get_current_matrix			(); // Obtain the current matrix whitout calculate, from the memory.
		/**
			\brief calcula la matriz de rotación según los angulos que tengan seteados en el momento cada motor.
		*/
		void 				calculate_current_position_matrix(); // Calculate and save in current_position_matrix;
		/**
			\brief obtiene la matriz de rotación según los angulos que tengan seteados en el momento cada motor.
		*/
		mat 				calculate_position 			(vector <double> angles);
		/**
			\brief calcula la posición y guarda el estado en variables internas.
		*/
		void 				calculate_position_set_values(vector <double> angles);
		/**
			\brief Obtiene todos los movimientos necesarios para mover la estructura a la posición xyz deseada.
		*/
		Movement 			move_to_xyz_position		(vector <double> xyz_position, double velocity);
		/**
			\brief Obtiene todos los movimientos necesarios para mover la estructura en xyz desde la posición actual.
		*/
		Movement			move_delta_xyz_position		(vector <double> delta_xyz_position, double velocity);
		
		mat 				jacobiano_motores			();
		/**
			\brief imprime la posición actual en coordenadas cartesianas.
		*/
		void				print_current_xyz_position	();
		/**
			\brief carga una estructura hecha en la GUI desde la ruta deseada.
			\param la ruta del archivo con la estructura.
		*/
		void				load						(char * path);


		int 				* getCorrespondMotorIds		(	);
		vector < Motor * > & 	getReferenceToMotors		(	);


		void add_rotational_dynamixelAx12_x(int motor_id, bool direction, double initial_angle, int fd);
		void add_rotational_dynamixelAx12_y(int motor_id, bool direction, double initial_angle, int fd);
		void add_rotational_dynamixelAx12_z(int motor_id, bool direction, double initial_angle, int fd);


	
	private:
		int						motors_amount;
		vector <double> 		initial_angles;
		vector <double> 		current_angles;
		double					motion_resolution;
		vector < Link_segment > link_segment;
		vector < Motor * > 		motors;
		vector < double >		order;
		mat 					current_position_matrix; // Rotational matrix 4x4 
		mat 					matrix_initial_angles;
		vector <double>			current_xyz_position;
};




#endif