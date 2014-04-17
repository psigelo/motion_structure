#ifndef CINEMATICA_CPP
#define CINEMATICA_CPP
#include "cinematica.hpp"


mat rotx(double x){
	mat A;
	A 	<< 1		<< 0 		<< 0 			<< 0 		<< endr
		<< 0 		<< cos(x) 	<< -sin(x) 		<< 0 		<< endr
		<< 0 		<< sin(x) 	<< cos(x) 		<< 0 		<< endr
		<< 0 		<< 0 		<< 0 			<< 1 		<< endr;
	return A;
}


mat roty(double x){
	mat A;
	A 	<< cos(x) 	<< 0 		<< sin(x) 		<< 0 		<< endr
		<< 0 		<< 1 		<< 0 			<< 0 		<< endr
		<< -sin(x)	<< 0 		<< cos(x) 		<< 0 		<< endr
		<< 0 		<< 0 		<< 0 			<< 1	 	<< endr;
	return A;
}

mat rotz(double x){
	mat A;
	A 	<< cos(x) 	<< -sin(x) 	<< 0 		<< 0 		<< endr
		<< sin(x) 	<< cos(x) 	<< 0 		<< 0 		<< endr
		<< 0 		<< 0 		<< 1 		<< 0 		<< endr
		<< 0 		<< 0 		<< 0 		<< 1		<< endr;
	return A;
}

mat traslacion(double x, double y, double z){
	mat A;
	A 	<< 1 << 0 << 0 << x << endr
		<< 0 << 1 << 0 << y << endr
		<< 0 << 0 << 1 << z << endr
		<< 0 << 0 << 0 << 1 << endr;
	return A;
}

mat traslacion(vector <double> xyz){
	mat A;
	A 	<< 1 << 0 << 0 << xyz.at(0) << endr
		<< 0 << 1 << 0 << xyz.at(1) << endr
		<< 0 << 0 << 1 << xyz.at(2) << endr
		<< 0 << 0 << 0 << 1 << endr;
	return A;
}

mat traslacionx(double x){
	mat A;
	A 	<< 1 << 0 << 0 << x << endr
		<< 0 << 1 << 0 << 0 << endr
		<< 0 << 0 << 1 << 0 << endr
		<< 0 << 0 << 0 << 1 << endr;
	return A;
}

mat traslaciony(double y){
	mat A;
	A 	<< 1 << 0 << 0 << 0 << endr
		<< 0 << 1 << 0 << y << endr
		<< 0 << 0 << 1 << 0 << endr
		<< 0 << 0 << 0 << 1 << endr;
	return A;
}

mat traslacionz(double z){
	mat A;
	A 	<< 1 << 0 << 0 << 0 << endr
		<< 0 << 1 << 0 << 0 << endr
		<< 0 << 0 << 1 << z << endr
		<< 0 << 0 << 0 << 1 << endr;
	return A;
}

double 	distancia(vector <double> xyz_ini, vector <double> xyz_fin){
	return sqrt(pow(xyz_ini.at(0) - xyz_fin.at(0),2) + pow(xyz_ini.at(1) - xyz_fin.at(1),2) + pow(xyz_ini.at(2) - xyz_fin.at(2),2));
}




vector <double> vector_pendiente(vector <double> xyz_ini, vector <double> xyz_fin){
	vector <double> pendiente;
	double distance = distancia(xyz_ini, xyz_fin);
	pendiente.push_back( (xyz_fin.at(0) - xyz_ini.at(0)) / distance );	
	pendiente.push_back( (xyz_fin.at(1) - xyz_ini.at(1)) / distance );
	pendiente.push_back( (xyz_fin.at(2) - xyz_ini.at(2)) / distance );	
	return pendiente;
}




double acondicionar_angulos(double angulo){
	while(angulo<0.0) 		angulo	+= 2.0*M_PI;
	while(angulo>2.0*M_PI) 	angulo 	-= 2.0*M_PI;
	return angulo;
}



#endif
