
#include "vector"
#include "motion_structure.hpp"
#include "dynamixelAX12Utils.hpp"
#include  <unistd.h>

extern "C" {
    #include "serial.h"
}


#define GRA (M_PI/180.0)


int main(){
	char ruta[] = "/dev/ttyUSB0";
	int fd = serial_open(ruta, AX_DEF_BAUDRATE);

	
	vector <double> xyz;
	xyz.push_back(0); 
	xyz.push_back(0); 
	xyz.push_back(0); 
	Motion_structure estructura(1);
	estructura.add_rotational_dynamixelAx12_z(1, -1, 0,fd);
	xyz.at(0)=54;
	xyz.at(1)=0;
	xyz.at(2)=0;
	estructura.add_translation_structure(xyz);
	estructura.add_rotational_dynamixelAx12_y(2, -1, 0,fd);
	xyz.at(0) = 64;
	xyz.at(1) = 0;
	xyz.at(2) =-15;
	estructura.add_translation_structure(xyz);
	estructura.add_rotational_dynamixelAx12_y(3, 1, 0,fd);
	xyz.at(0) = +100;
	xyz.at(1) = 0;
	xyz.at(2) = -115;
	estructura.add_translation_structure(xyz);
	
	xyz.at(0) = 1.0;
	xyz.at(1) = 0.0;
	xyz.at(2) = 0.0;
	Movement movimiento = estructura.move_delta_xyz_position(xyz,40.0);


	//movimiento.print_all();

	int tiempo_entre_puntos = movimiento.get_time_between_tw0_points_millisecons();
	cout << tiempo_entre_puntos << endl;
	for (int i = 0; i < movimiento.get_length_position(); ++i)
	{
		movimiento.really_move_to_position_from_list(i);
		usleep(1000*tiempo_entre_puntos);
	}
	
	
	/*
	dynamixelAX12 *  motorDyn = new dynamixelAX12(1, 1, 2.3, ROTX , fd);
	motorDyn->move(2.2,2.2);
	Motor * motorN;
	motorN = motorDyn;
	motorN->move(2.2,2.2);
	*/

}