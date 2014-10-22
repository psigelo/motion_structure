#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <iostream>
#include "RotMatrix.hpp"

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
		RotMatrix	matrix; // No es para usarse directamente.
		bool		direction;
		RotMatrix &	(*rotational_function)(double); 		
	public:
		/**

		*/
		Motor(int id, bool direction, double angle, MotorType type);
		/**
			\brief Obtiene la ID del motor.
		*/
		int 	getId						();
		/**
			\brief Setea la ID del motor.
		*/
		void 	setId 						(int id);
		/**
			\brief Obtiene el ángulo actual del motor
		*/
		double 	getAngle 					();
		/**
			\brief Setea el ángulo actual del Motor
		*/
		void 	setAngle 					(double angle);
		/**
			\brief obtiene la dirección del motor según regla de la mano derecha, true: sigue regla de la mano derecha.        false: otro caso.
		*/
		bool	getDirection 				();
		/**
			\brief Setea la dirección del motor, en caso de setearlo true entonces los angulos crecen según regla de la mano derecha.
		*/
		void 	setDirection 				(bool dir);
		/**
			\brief calcula la matriz de rotación acosiada a la posición del motor.
		*/
		void 	calculateCurrentMatrix 		();
		/**
			\brief Obtiene la matriz rotacional asociada al motor.
		*/
		RotMatrix &	getCurrentMatrix 		();
		/**
			\brief calcula y retorna la matriz rotacional del motor en el ángulo introducido.
			\param angle: el ángulo del motor.
		*/
		RotMatrix & calculateMatrix 		(double angle);
		/**
			\biref ontiene la dirección del motor en numeros: +1 si sigue regla de la mano derecha, -1 en caso contrario. 
		*/
		double	getDirectionValue			();
};

#endif