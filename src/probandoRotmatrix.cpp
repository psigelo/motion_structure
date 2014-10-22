
#include "RotMatrix.hpp"
#include "solverLinear.hpp"

#include <iostream>

int main(){
/*
	RotMatrix rot,tras;

	tras.traslation(0.1,0.0,0.0);
	rot.rotz(M_PI/2.0);
	cout << tras*rot << endl;
	cout << rot*tras << endl;

*/

	RotMatrix rot;
	rot = rotx(0.1);
	cerr << rot << endl;

	double A [4];
	A[0]=1.0;
	A[1]=3.0;
	A[2]=3.0;
	A[3]=10.0;

	double b[2];
	b[0] = 2;
	b[1] = 5;

	
	double * x;
	x = choleskySolver(2,A,b);

	cerr << x[0] << "\t"<< x[1]  << endl;

	return 0;

}
