#include "mathematicTools.hpp"

#include <iostream>

double 	distancia(vector <double> xyz_ini, vector <double> xyz_fin){
	return sqrt(pow(xyz_ini.at(0) - xyz_fin.at(0),2) + pow(xyz_ini.at(1) - xyz_fin.at(1),2) + pow(xyz_ini.at(2) - xyz_fin.at(2),2));
}




double * vector_pendiente(vector <double> xyz_ini, vector <double> xyz_fin){
	double * pendiente = (double *)malloc(sizeof(double)*3);
	double distance = distancia(xyz_ini, xyz_fin);
	pendiente[0] = (xyz_fin.at(0) - xyz_ini.at(0)) / distance ;	
	pendiente[1] = (xyz_fin.at(1) - xyz_ini.at(1)) / distance ;
	pendiente[2] = (xyz_fin.at(2) - xyz_ini.at(2)) / distance ;	
	return pendiente;
}




double acondicionar_angulos(double angulo){

	cerr << "angulo entrante " << angulo << endl;
	while(angulo<0.0) 		angulo	+= 2.0*M_PI;
	while(angulo>2.0*M_PI) 	angulo 	-= 2.0*M_PI;
	return angulo;
}
