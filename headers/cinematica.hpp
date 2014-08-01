#ifndef CINEMATICA_H
#define CINEMATICA_H

#include <cmath>
#include <armadillo>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace arma;

/**
\brief rotx(double x) Es una matriz de rotacion en el eje x que puede ser estudiada bajo el tópico matrices de rotacion.

	1		0 			0 			0 
	0 		cos(x) 		-sin(x) 	0 
	0 		sin(x) 		cos(x) 		0 
	0 		0 			0 			1 


\param x es el ángulo con que se va a rotar.
*/
mat 			rotx(double x);
/**
\brief roty(double x) Es una matriz de rotacion en el eje y que puede ser estudiada bajo el tópico matrices de rotacion.

		cos(x) 	0 		sin(x) 		0 		
		0 		1 		0 			0 		
		-sin(x)	0 		cos(x) 		0 		
		 0 		0 		0 			1	 	

\param x es el ángulo con que se va a rotar.
*/
mat 			roty(double x);
/**
\brief rotx(double x) Es una matriz de rotacion en el eje z que puede ser estudiada bajo el tópico matrices de rotacion.

		cos(x) 	-sin(x) 	0 		0 		
		sin(x) 	cos(x) 		0 		0 		
		0 		0 			1 		0 		
		0 		0 			0 		1		

\param x es el ángulo con que se va a rotar.
*/
mat 			rotz(double x);
/**
\brief traslacion(double x,double y,double z) Es una matriz de traslación estudiada bajo el tópico de matrices de rotación.
		1 0 0 x 
		0 1 0 y 
		0 0 1 z 
		0 0 0 1 

\param  (double x,double y,double z) corresponden a las componentes del vector de traslación.

*/
mat 			traslacion(double x,double y,double z);
/**
\brief traslacion(vector <double> xyz) Es una matriz de traslación estudiada bajo el tópico de matrices de rotación.
		1 0 0 xyz.at(0) 
		0 1 0 xyz.at(1) 
		0 0 1 xyz.at(2) 
		0 0 0 1 

\param  (vector <double> xyz) corresponde al vector de traslación.
*/
mat 			traslacion(vector <double> xyz);
/**
\brief traslacionx(double x) Es una matriz de traslación sólo en el eje x estudiada bajo el tópico de matrices de rotación.
		1 0 0 x 
		0 1 0 0 
		0 0 1 0 
		0 0 0 1 

\param  (double x) corresponden la componente x de la traslacion.
*/
mat 			traslacionx(double x);
/**
\brief traslacionx(double y) Es una matriz de traslación sólo en el eje y estudiada bajo el tópico de matrices de rotación.
		1 0 0 y 
		0 1 0 0 
		0 0 1 0 
		0 0 0 1 

\param  (double y) corresponden la componente y de la traslacion.
*/
mat 			traslaciony(double y);
/**
\brief traslacionx(double z) Es una matriz de traslación sólo en el eje z estudiada bajo el tópico de matrices de rotación.
		1 0 0 z 
		0 1 0 0 
		0 0 1 0 
		0 0 0 1 

\param  (double z) corresponden la componente z de la traslacion.
*/
mat 			traslacionz(double z);

/**
	\brief Calcula de distancia entre dos vectores en R^3
*/
double 			distancia(vector <double> xyz_ini, vector <double> xyz_fin);
/**
	\brief Calcula el vector unitario que uno el punto inicial con el punto final.

	\param xyz_ini: punto inicial  xyz_fin:punto final.
*/
vector <double> vector_pendiente(vector <double> xyz_ini, vector <double> xyz_fin);

/**
	\brief transforma el angulo al intervalo [0 , 2Pi]
*/
double 			acondicionar_angulos(double angulo);



#endif
