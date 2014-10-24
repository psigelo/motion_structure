#include "dynamixelAX12.hpp"


/*

 Como sabemos que la posición y la velocidad están en [radianes] y en [radianes/seg]
Entonces hay que pasarlos al formato digital correcto.

*/
dynamixelAX12::dynamixelAX12(int _id, bool direction, double angle, MotorType type , int _fd):
	Motor(_id, direction, angle, type)
{
	fd = _fd;
}

void dynamixelAX12::move(double position, double velocity){
	//POR LO PRONTO NO SE PONDRÁN LAS VELOCIDADES, MÁS QUE NADA POR TEMAS DE TIEMPO!! PERO DESPUÉS SE REALIZARA
	//RECORDAR ESTO!!!!!!
	int dynPos = (int)  (position * 1024) *(180.0/M_PI)/300.0;
	//cout << "pos" << dynPos << endl;
	ax_set_position (fd, id, dynPos);
	
	//cerr << "dynamicel" << endl;
}