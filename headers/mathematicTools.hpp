#ifndef MATHEMATIC_TOOLS_HPP
#define MATHEMATIC_TOOLS_HPP

#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

/**
	\brief Calcula de distancia entre dos vectores en R^3
*/
double 			distancia(vector <double> xyz_ini, vector <double> xyz_fin);
/**
	\brief Calcula el vector unitario que uno el punto inicial con el punto final.

	\param xyz_ini: punto inicial  xyz_fin:punto final.
*/
double * vector_pendiente(vector <double> xyz_ini, vector <double> xyz_fin);

/**
	\brief transforma el angulo al intervalo [0 , 2Pi]
*/
double 			acondicionar_angulos(double angulo);



#endif