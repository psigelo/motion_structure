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


mat 			rotx(double x);
mat 			roty(double x);
mat 			rotz(double x);
mat 			traslacion(double x,double y,double z);
mat 			traslacion(vector <double> xyz);
mat 			traslacionx(double x);
mat 			traslaciony(double y);
mat 			traslacionz(double z);
double 			distancia(vector <double> xyz_ini, vector <double> xyz_fin);
vector <double> vector_pendiente(vector <double> xyz_ini, vector <double> xyz_fin);
double 			acondicionar_angulos(double angulo);



#endif
