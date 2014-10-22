#ifndef ROTMATRIX_HPP
#define ROTMATRIX_HPP

#include <cmath>
#include <ostream>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class RotMatrix{
	public:
		/**
			\brief no se inicializa nada, posteriormente se debe usar algún método que le dé valores como {rotx,roty,rotz,traslation}
		*/
		RotMatrix();
		/**
			\brief inicializa la matriz de rotación directamente con los valores que se les de en el arreglo de entrada
			\param _valiues debe estar en el heap de la memoria y ser de tamaño 16.
		*/
		RotMatrix(double _values[16]);
		
		/**
			\brief Obtiene las coordenadas cartesianas de la matriz de rotación.
		*/
		double * get_xyz();

		/**
			\brief obtiene directamente un valor de la matriz.
		*/
		double get(int row, int col);

		/**
			\brief Multiplicación de matrices 4x4
		*/
		friend RotMatrix & operator * (RotMatrix rotM1, RotMatrix);

		/**
			\brief impresión por pantalla de las matrices de rotación.
		*/
		friend ostream & operator << (ostream &os, RotMatrix &rm);
		/**
			\brief Solucionador del problema lineal Ax=b a través de decomposición de Cholesky.
		*/
		~RotMatrix();

	private:
		double values[16];
};

/**
\brief Setea la matriz rotacional como una matriz de rotación en eje x:

	1		0 			0 			0 
	0 		cos(x) 		-sin(x) 	0 
	0 		sin(x) 		cos(x) 		0 
	0 		0 			0 			1 


\param es el ángulo con que se va a rotar.
*/
RotMatrix &  rotx(double angle);
/**
\brief Setea la matriz rotacional como una matriz de rotación en eje y:

	cos(x) 	0 		sin(x) 		0 		
	0 		1 		0 			0 		
	-sin(x)	0 		cos(x) 		0 		
	 0 		0 		0 			1	 	


\param es el ángulo con que se va a rotar.
*/
RotMatrix &  roty(double angle);
/**
\brief Setea la matriz rotacional como una matriz de rotación en eje z:

	cos(x) 	-sin(x) 	0 		0 		
	sin(x) 	cos(x) 		0 		0 		
	0 		0 			1 		0 		
	0 		0 			0 		1	


\param es el ángulo con que se va a rotar.
*/
RotMatrix & rotz(double angle);
/**
\brief Setea una matriz de traslación:

	1 0 0 x 
	0 1 0 y 
	0 0 1 z 
	0 0 0 1 


\param xyz debe poseer la traslación de los tres ejes.
*/
RotMatrix & traslation(double * xyz);

/**
\brief Setea una matriz de traslación:

	1 0 0 x 
	0 1 0 y 
	0 0 1 z 
	0 0 0 1

*/
RotMatrix & traslation(double x, double y, double z);
RotMatrix & traslationx(double x);
RotMatrix & traslationy(double y);
RotMatrix & traslationz(double z);
RotMatrix & traslation(vector <double> xyz);
#endif