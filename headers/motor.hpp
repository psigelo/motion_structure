#ifndef MOTOR_HPP
#define MOTOR_HPP

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
	protected:
		int 		id;
		bool		direction;
		double 		angle;
	private:
		mat 		current_matrix; // Rotational matrix 4x4
		mat 		(*rotational_function)(double); 		
	public:
		/**

		*/
		Motor(int id, bool direction, double angle, MotorType type);
		Motor();
		/**
			\brief Obtiene la ID del motor.
		*/
		int 	get_id						();
		/**
			\brief Setea la ID del motor.
		*/
		void 	set_id 						(int id);
		/**
			\brief Obtiene el ángulo actual del motor
		*/
		double 	get_angle 					();
		/**
			\brief Setea el ángulo actual del Motor
		*/
		void 	set_angle 					(double angle);
		/**
			\brief obtiene la dirección del motor según regla de la mano derecha, true: sigue regla de la mano derecha.        false: otro caso.
		*/
		bool	get_direction 				();
		/**
			\brief Setea la dirección del motor, en caso de setearlo true entonces los angulos crecen según regla de la mano derecha.
		*/
		void 	set_direction 				(bool dir);
		/**
			\brief calcula la matriz de rotación acosiada a la posición del motor.
		*/
		void 	calculate_current_matrix 	();
		/**
			\brief Obtiene la matriz rotacional asociada al motor.
		*/
		mat 	get_current_matrix 			();
		/**
			\brief calcula y retorna la matriz rotacional del motor en el ángulo introducido.
			\param angle: el ángulo del motor.
		*/
		mat 	calculate_matrix 			(double angle);
		/**
			\biref ontiene la dirección del motor en numeros: +1 si sigue regla de la mano derecha, -1 en caso contrario. 
		*/
		double	get_direction_value			();

		virtual void move( double position, double velocidad );

		int getMotorId();
};

#endif