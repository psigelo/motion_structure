#ifndef ROTMATRIX_CPP
#define ROTMATRIX_CPP

#include "RotMatrix.hpp"

RotMatrix::RotMatrix(){}

RotMatrix::RotMatrix(double _values[16]){
	for (int i = 0; i < 16; ++i)
	{
		values[i] = _values[i];
	}
		
}
/*
	Los valores de x,y,z  están en posiciones específicas de la matriz de rotación.

	OBS: esto se conserva aún haciendo operaciones de multiplicación.
*/
double * RotMatrix::get_xyz(){ // Se devuelve un puntero a un doble de tamaño 3 y en el heap de la memoria.
	double  * xyz = (double *)malloc(sizeof(double) * 3); // Cantidad de dimensiones.
	xyz[0] = values[3];
	xyz[1] = values[7];
	xyz[2] = values[11];
	return xyz;
}

double RotMatrix::get(int row, int col){
	return values[ row * 4 + col ];
}

/*
	Se debe implementar la siguiente matriz de rotación.

	1		0 			0 			0 
	0 		cos(x) 		-sin(x) 	0 
	0 		sin(x) 		cos(x) 		0 
	0 		0 			0 			1 
*/

RotMatrix & rotx(double angle){
	double _values[16];
	_values[0]=1.0;
	_values[1]=0.0;
	_values[2]=0.0;
	_values[3]=0.0;
	_values[4]=0.0;
	_values[5]=cos(angle);
	_values[6]=-sin(angle);
	_values[7]=0.0;
	_values[8]=0.0;
	_values[9]=sin(angle);
	_values[10]=cos(angle);
	_values[11]=0.0;
	_values[12]=0.0;
	_values[13]=0.0;
	_values[14]=0.0;
	_values[15]=1.0;
	RotMatrix * matrix = new RotMatrix(_values);
	return *matrix;
}
/*
	Se debe implementar la siguiente matriz de rotación.

	cos(x) 	0 		sin(x) 		0 		
	0 		1 		0 			0 		
	-sin(x)	0 		cos(x) 		0 		
	 0 		0 		0 			1	 	

*/
RotMatrix & roty(double angle){
	double _values[16];
	_values[0]=cos(angle);
	_values[1]=0.0;
	_values[2]=sin(angle);
	_values[3]=0.0;
	_values[4]=0.0;
	_values[5]=1.0;
	_values[6]=0.0;
	_values[7]=0.0;
	_values[8]=-sin(angle);
	_values[9]=0.0;
	_values[10]=cos(angle);
	_values[11]=0.0;
	_values[12]=0.0;
	_values[13]=0.0;
	_values[14]=0.0;
	_values[15]=1.0;
	RotMatrix * matrix = new RotMatrix(_values);
	return *matrix;
}

/*

	Se debe implementar la siguiente matriz de rotación.

		cos(x) 	-sin(x) 	0 		0 		
		sin(x) 	cos(x) 		0 		0 		
		0 		0 			1 		0 		
		0 		0 			0 		1	


*/

RotMatrix & rotz(double angle){
	double _values[16];
	_values[0]=cos(angle);
	_values[1]=-sin(angle);
	_values[2]=0.0;
	_values[3]=0.0;
	_values[4]=sin(angle);
	_values[5]=cos(angle);
	_values[6]=0.0;
	_values[7]=0.0;
	_values[8]=0.0;
	_values[9]=0.0;
	_values[10]=1.0;
	_values[11]=0.0;
	_values[12]=0.0;
	_values[13]=0.0;
	_values[14]=0.0;
	_values[15]=1.0;
	RotMatrix * matrix = new RotMatrix(_values);
	return *matrix;
}

/*
	Se debe implementar la siguiente matriz de rotación.
		1 0 0 x 
		0 1 0 y 
		0 0 1 z 
		0 0 0 1 

*/
RotMatrix & traslation(double * xyz){
	double _values[16];
	_values[0]=1.0;
	_values[1]=0.0;
	_values[2]=0.0;
	_values[3]=xyz[0];
	_values[4]=0.0;
	_values[5]=1.0;
	_values[6]=0.0;
	_values[7]=xyz[1];
	_values[8]=0.0;
	_values[9]=0.0;
	_values[10]=1.0;
	_values[11]=xyz[2];
	_values[12]=0.0;
	_values[13]=0.0;
	_values[14]=0.0;
	_values[15]=1.0;
	RotMatrix * matrix = new RotMatrix(_values);
	return *matrix;
}


RotMatrix & traslation(vector <double> xyz){
	double _values[16];
	_values[0]=1.0;
	_values[1]=0.0;
	_values[2]=0.0;
	_values[3]=xyz[0];
	_values[4]=0.0;
	_values[5]=1.0;
	_values[6]=0.0;
	_values[7]=xyz[1];
	_values[8]=0.0;
	_values[9]=0.0;
	_values[10]=1.0;
	_values[11]=xyz[2];
	_values[12]=0.0;
	_values[13]=0.0;
	_values[14]=0.0;
	_values[15]=1.0;
	RotMatrix * matrix = new RotMatrix(_values);
	return *matrix;
}


/*
	Se debe implementar la siguiente matriz de rotación.
		1 0 0 x 
		0 1 0 y 
		0 0 1 z 
		0 0 0 1 

*/
RotMatrix & traslation(double  x, double y, double z){
	double _values[16];
	_values[0]=1.0;
	_values[1]=0.0;
	_values[2]=0.0;
	_values[3]=x;
	_values[4]=0.0;
	_values[5]=1.0;
	_values[6]=0.0;
	_values[7]=y;
	_values[8]=0.0;
	_values[9]=0.0;
	_values[10]=1.0;
	_values[11]=z;
	_values[12]=0.0;
	_values[13]=0.0;
	_values[14]=0.0;
	_values[15]=1.0;
	RotMatrix * matrix = new RotMatrix(_values);
	return *matrix;
}


RotMatrix & traslationx(double  x){
	return traslation(x,0,0);
}


RotMatrix & traslationy(double  y){
	return traslation(0,y,0);
}

RotMatrix & traslationz(double  z){
	return traslation(0,0,z);
}


/*
	Como la multiplicación de matrices no es conmutativa se debe hacer correctamente según el orden de los operadores.

	Observar que las multiplicaciones son echar sin for y se usan los valores directos aun siendo privados, esto es para maximizar la eficiencia del código.
*/
RotMatrix & operator * ( RotMatrix rotM1, RotMatrix rotM2){
	//double * _values = (double *) malloc(16*sizeof(double));
	double _values[16];
	//Fila 0:
	_values[0] = rotM1.values[0]*rotM2.values[0] + rotM1.values[1]*rotM2.values[4] + rotM1.values[2]*rotM2.values[8] + rotM1.values[3]*rotM2.values[12];
	_values[1] = rotM1.values[0]*rotM2.values[1] + rotM1.values[1]*rotM2.values[5] + rotM1.values[2]*rotM2.values[9] + rotM1.values[3]*rotM2.values[13];
	_values[2] = rotM1.values[0]*rotM2.values[2] + rotM1.values[1]*rotM2.values[6] + rotM1.values[2]*rotM2.values[10] + rotM1.values[3]*rotM2.values[14];
	_values[3] = rotM1.values[0]*rotM2.values[3] + rotM1.values[1]*rotM2.values[7] + rotM1.values[2]*rotM2.values[11] + rotM1.values[3]*rotM2.values[15];

	//Fila 1:
	_values[4] = rotM1.values[4]*rotM2.values[0] + rotM1.values[5]*rotM2.values[4] + rotM1.values[6]*rotM2.values[8] + rotM1.values[7]*rotM2.values[12];
	_values[5] = rotM1.values[4]*rotM2.values[1] + rotM1.values[5]*rotM2.values[5] + rotM1.values[6]*rotM2.values[9] + rotM1.values[7]*rotM2.values[13];
	_values[6] = rotM1.values[4]*rotM2.values[2] + rotM1.values[5]*rotM2.values[6] + rotM1.values[6]*rotM2.values[10] + rotM1.values[7]*rotM2.values[14];
	_values[7] = rotM1.values[4]*rotM2.values[3] + rotM1.values[5]*rotM2.values[7] + rotM1.values[6]*rotM2.values[11] + rotM1.values[7]*rotM2.values[15];

	//Fila 2:
	_values[8] = rotM1.values[8]*rotM2.values[0] + rotM1.values[9]*rotM2.values[4] + rotM1.values[10]*rotM2.values[8] + rotM1.values[11]*rotM2.values[12];
	_values[9] = rotM1.values[8]*rotM2.values[1] + rotM1.values[9]*rotM2.values[5] + rotM1.values[10]*rotM2.values[9] + rotM1.values[11]*rotM2.values[13];
	_values[10] = rotM1.values[8]*rotM2.values[2] + rotM1.values[9]*rotM2.values[6] + rotM1.values[10]*rotM2.values[10] + rotM1.values[11]*rotM2.values[14];
	_values[11] = rotM1.values[8]*rotM2.values[3] + rotM1.values[9]*rotM2.values[7] + rotM1.values[10]*rotM2.values[11] + rotM1.values[11]*rotM2.values[15];

	//Fila 3:
	_values[12] = rotM1.values[12]*rotM2.values[0] + rotM1.values[13]*rotM2.values[4] + rotM1.values[14]*rotM2.values[8] + rotM1.values[15]*rotM2.values[12];
	_values[13] = rotM1.values[12]*rotM2.values[1] + rotM1.values[13]*rotM2.values[5] + rotM1.values[14]*rotM2.values[9] + rotM1.values[15]*rotM2.values[13];
	_values[14] = rotM1.values[12]*rotM2.values[2] + rotM1.values[13]*rotM2.values[6] + rotM1.values[14]*rotM2.values[10] + rotM1.values[15]*rotM2.values[14];
	_values[15] = rotM1.values[12]*rotM2.values[3] + rotM1.values[13]*rotM2.values[7] + rotM1.values[14]*rotM2.values[11] + rotM1.values[15]*rotM2.values[15];

	RotMatrix * resultMatrix = new RotMatrix( _values );

	return *resultMatrix;
}

/*
	Se imprime la matriz
*/	
ostream & operator << (ostream &os, RotMatrix &rotM){
   for (int row = 0; row < 4; ++row)
   {
   		os << "|\t";
   		for (int  col = 0; col < 4; ++col)
   		{
   			os  << rotM.values[row*4 + col] << "\t";
   		}
   		os << "|" << endl;
   }
   //os << rotM.values[7];
   return os;
}

RotMatrix::~RotMatrix(){

}

#endif