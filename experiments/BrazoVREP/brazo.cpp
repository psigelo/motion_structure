
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include <motionstructure> // Librería del proyecto.
//#include <motionstructure_headers/motion_structure.hpp>

extern "C" {
    #include "extApi.h"
}


using namespace std;
int main(int argc,char* argv[])
{

	
	
	int portNb=19997;
	int error;
	vector <double> xyz;
	int clientID = simxStart((simxChar*)"127.0.0.1",portNb,true,true,2000,5);
	cerr << clientID << endl;


	//===================================================================
	Motion_structure * estructura = new Motion_structure(argv[1], 0.001);
	//===================================================================

	xyz.push_back(0);
	xyz.push_back(0);
	xyz.push_back(0);
	simxStartSimulation(clientID, simx_opmode_oneshot_wait);

	if (clientID!=-1)
	{
		
		
		int handle[6];
		error = simxGetObjectHandle(clientID, "redundantRob_joint1", &handle[0], simx_opmode_oneshot_wait);
		if (error != 0) cerr << error << endl;
		error = simxGetObjectHandle(clientID, "redundantRob_joint2", &handle[1], simx_opmode_oneshot_wait);
		if (error != 0) cerr << error << endl;
		error = simxGetObjectHandle(clientID, "redundantRob_joint3", &handle[2], simx_opmode_oneshot_wait);
		if (error != 0) cerr << error << endl;
		error = simxGetObjectHandle(clientID, "redundantRob_joint4", &handle[3], simx_opmode_oneshot_wait);
		if (error != 0) cerr << error << endl;
		error = simxGetObjectHandle(clientID, "redundantRob_joint5", &handle[4], simx_opmode_oneshot_wait);
		if (error != 0) cerr << error << endl;
		error = simxGetObjectHandle(clientID, "redundantRob_joint6", &handle[5], simx_opmode_oneshot_wait);
		if (error != 0) cerr << error << endl;

		int tiempo_entre_puntos;
		double velocidad;

		while (simxGetConnectionId(clientID)!=-1)
		{
			char quit;
			cout << "Si desea mover el brazo aprete enter, si desea salir aprete q" << endl;
			cin >> quit;
			if(quit == 'q')break;

			cout << "\nIngrese la variacion de la position X" << endl;
			cin >> xyz.at(0);
			cout << "\nusted ingreso " << xyz.at(0) << endl;
			cout << "\nIngrese la variacion de la position Y" << endl;
			cin >> xyz.at(1);
			cout << "\nusted ingreso " << xyz.at(1) << endl;
			cout << "\nIngrese la variacion de la position Z" << endl;
			cin >> xyz.at(2);
			cout << "\nusted ingreso " << xyz.at(2) << endl;
			cout << "\ningrese la velocidad del movimiento " << endl;
			cin >> velocidad;


			//========================================================================
			Movement movimiento;
			movimiento = estructura->move_delta_xyz_position(xyz,velocidad);
			tiempo_entre_puntos = movimiento.get_time_between_tw0_points_millisecons();
			//=========================================================================

			for (int i = 0; i < movimiento.get_length_position(); ++i)
			{
				//=========================================================================
				vector <double> posicion = movimiento.get_from_list_motor_angle_position(i);
				vector <double> velocidad = movimiento.get_from_list_motor_velocities(i);
				//=========================================================================


				simxPauseCommunication(clientID, 1);
				for (int j = 0; j < (int)posicion.size(); ++j)
				{
					error = simxSetJointTargetPosition(clientID, handle[j], posicion.at(j), simx_opmode_oneshot);
					error = simxSetJointTargetVelocity(clientID, handle[j], velocidad.at(j), simx_opmode_oneshot);
				}
				simxPauseCommunication(clientID, 0);
				extApi_sleepMs( tiempo_entre_puntos );

			}

		}
		
	}

	simxStopSimulation(clientID, simx_opmode_oneshot_wait);
	simxFinish(clientID);


	
	return(0);
}

