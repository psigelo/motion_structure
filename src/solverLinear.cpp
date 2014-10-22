#include "solverLinear.hpp"
#include <iomanip>

/*
	Se busca resolver el problema lineal A x = b 

	Dado que la matriz A puede no ser cuadrada primero se tiene que hacer un trabajo matematico

	Ax=b

	A^T A x = A^T b

	luego sea C = A^T A   y d = A^T b

	la idea es calcular

	C x = d  
	
	donde se resolvera a traves de la descomposicion de cholesky C =  L L^T

	Luego se resuelve el problema L L^T x = d   a traves del sistema de ecuaciones dado por
		1) L z = d
		2) L^T x = z

	Se aprovecha que esos sistemas son facilmente resolvibles. 
	La materia usada aca es vista en el ramo analisis numerico de cualquier escuela de ingenieria.

	Observar: lo que se busca es no usar la inversion de matrices por su excesivo costo computacional
*/


	/*
		Observar que este metodo estara hecho especificamente para el problema de invertir motores, por eso la cantidad de entradas es muy grande.
	*/

// al llamarlo en el codigo se usa:
// choleskySolver(motors_amount, jacobiano, pendiente*motion_resolution, angulosProximos, velocidad, velocidadMotores ) ;
void choleskySolver(int size, double A[], double b[], double angulosProximos[], double velocidad[], double velocidadMotores[] ){
	cerr << "entro" << endl;
	// Se sabe previamente que A es una matriz 3xN  donde N es el numero de motores

	double C [size*size];


	/*for (int i = 0; i < size; ++i)
	{
		for(int j = i; j < size; ++j){
			C[ i*size + j ] = C[j*size + i] = (A[i+size] * A[j+size]) + (A[i+2*size]*A[j+2*size]) + (A[i+3*size]*A[j+3*size]); 
		}
	}
	*/
	for (int i = 0; i < size; ++i)
	{
		for(int j = i; j < size; ++j){
			C[ i*size + j ] = C[j*size + i] = (A[i] * A[j] )+(A[1*size + i] * A[1*size+j] )+(A[2*size + i] * A[2*size+j] ); 
		}
	}

	int contador(0);
 	cerr << "A" << endl;
 	cerr << "{" ;
 	for (int i = 0; i < 3; ++i)
 	{
 		cerr << "{";
 		for (int j = 0; j < size; ++j)
 		{
 			cerr<< A [contador++]  << ",";
 		}
 		cerr << "}"<< endl;
 	}
 	cerr << "}" << endl;
 	contador = 0;
 	cerr << "C" << endl;
 	cerr << "{" ;
 	for (int i = 0; i < size; ++i)
 	{
 		cerr << "{" ;
 		for (int j = 0; j < size; ++j)
 		{
 			cerr  <<  C [contador++] << "," ;
 		}
 		cerr << "}"<< endl;
 	}
 	cerr << "}"<< endl;


	int row(size);

	// Las variables de cholesky corresponden a la matriz L  (matriz triangular inferior), por ejemplo:
	//      | c0  0  0 |
	// L =  | c1 c2  0 |
	//      | c3 c4 c5 |
	// donde la notacion es tal que c0 es choleskyVariables[0].
	// Cuidado: No confundir con C que corresponde a una matriz cuadrada explicada en el comentario anterior.

	double choleskyVariables[size*(size+1)/2];

	try{
		for (int _row = 0; _row < row; ++_row) // Se comienza en la segunda fila.
		{
			for (int _col = 0; _col < _row; ++_col)
			{
				choleskyVariables[_row*(_row+1)/2 + _col ] = 0.0;

				for (int k = 0; k < _col; ++k)
					choleskyVariables[_row*(_row+1)/2 + _col] -= choleskyVariables[ _col*(_col+1)/2 + k]*choleskyVariables[ _row*(_row+1)/2 +k];
				choleskyVariables[_row*(_row+1)/2 + _col ] = ( choleskyVariables[_row*(_row+1)/2 + _col ] + C[_row * size + _col ]) / choleskyVariables[ _col*(_col+1)/2 + _col  ];
				
			}
			// _col == _row :::> en la diagonal se calcula direnete:
			choleskyVariables[ _row*(_row+1)/2 + _row ] = 0.0;
			for (int k = 0; k < _row; ++k)
				choleskyVariables[_row*(_row+1)/2 + _row] -= choleskyVariables[ _row*(_row+1)/2 + k]*choleskyVariables[ _row*(_row+1)/2 +k];
			choleskyVariables[ _row*(_row+1)/2 + _row ] = sqrt(choleskyVariables[ _row*(_row+1)/2 + _row ] + C[_row*size + _row]);
		}	
	}
	catch(...){
		cerr << "solverLinear::choleskySolver::ERROR::No se puede descomponer a traves de cholesky" << endl;
		exit(1);
	}



	// Resolviendo Cx = d a traves de C = L L^T <=> L L^T x = d 
	// Lo que se transforma en un sistema de ecuaciones
	// 1) L z = d
	// 2) L^T x = z 

	// calculamos d = A^T b
	double d[3];
	for (int i = 0; i < 3; ++i)
	{
		d[i]=0;
		for (int j = 0; j < size; ++j)
			d[i] += A[i*size+j]*b[j];
		
	}


	// Entonces primero se comienza con L z = b donde encontraremos las variables z.
	double z[3];
	for (int i = 0; i < 3; ++i)
	{
		z[i] = 0;
		for (int j = 0; j < i; ++j)
			z[i] -= z[j]*choleskyVariables[i*(i+1)/2 + j];
		z[i] = (d[i] + z[i])/choleskyVariables[i*(i+1)/2 + i];	
	}

	// Ya estan calculados todos los z ahora se procede a calcular el vector x
	for (int i = 3-1; i > -1; --i)
	{
		double temp = angulosProximos[i];
		angulosProximos[i]=0;
		for (int j = 2; j > i; --j)
			angulosProximos[i] -= angulosProximos[j]*choleskyVariables[j*(j+1)/2 + i];
		angulosProximos[i] = (z[i] + angulosProximos[i] )/choleskyVariables[i*(i+1)/2 + i] + temp;
	}





	// Resolviendo Cx = d a traves de C = L L^T <=> L L^T x = d 
	// Lo que se transforma en un sistema de ecuaciones
	// 1) L z = d
	// 2) L^T x = z 

	
	for (int i = 0; i < 3; ++i)
	{
		d[i]=0;
		for (int j = 0; j < size; ++j)
			d[i] += A[i*size+j]*velocidad[j];
		
	}



	// Entonces primero se comienza con L z = b donde encontraremos las variables z.
	


	for (int i = 0; i < 3; ++i)
	{
		z[i] = 0;
		for (int j = 0; j < i; ++j)
			z[i] -= z[j]*choleskyVariables[i*(i+1)/2 + j];
		z[i] = (d[i] + z[i])/choleskyVariables[i*(i+1)/2 + i];	
	}

	// Ya estan calculados todos los z ahora se procede a calcular el vector x
	for (int i = 3-1; i > -1; --i)
	{
		velocidadMotores[i]=0;
		for (int j = 2; j > i; --j)
			velocidadMotores[i] -= velocidadMotores[j]*choleskyVariables[j*(j+1)/2 + i];
		velocidadMotores[i] = (z[i] + velocidadMotores[i])/choleskyVariables[i*(i+1)/2 + i];
	}
	cerr << "salio" << endl;
}