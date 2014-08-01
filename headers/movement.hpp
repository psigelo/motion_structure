#include <vector>


using namespace std;

class Movement{
	public:
		/**
			\brief Se setean valores por defecto.
		*/
		Movement();
		/**
			\brief Se obtiene la cantidad de posiciones que el objeto tiene guardadas por el ultimo movimiento realizado.
		*/
		int 				get_length_position					(										);
		/**
			\brief Se obtiene la cantidad de velocidades que el objeto tiene guardadas por el ultimo movimiento realizado.
		*/
		int 				get_length_velocity					(										);
		/**
			\brief Se agrega una posición a la lista de posiciones.
			\param angle_position_data es el vector de posiciones de todos los motores de la estructura.
		*/
		void			 	add_to_list_motor_angle_positions	( 	vector <double> angle_position_data	);
		/**
			\brief Se obtiene la posición de los motores de la lista de posiciones.
			\param position es la posición en la lista de posiciones.
		*/
		vector <double>		get_from_list_motor_angle_position	( 	int position						);
		/**
			\brief Se agrega vector de velocidades de los motores a la lista de velocidades.
		*/
		void			 	add_to_list_motor_velocities		( 	vector <double> velocity_data		);
		/**
			\brief Se obtiene la velocidad de los motores de la lista de velocidades.
			\param position es la velocidad en la lista de velocidades.
		*/
		vector <double>		get_from_list_motor_velocities		( 	int position						);
		/**
			\brief Se borran todos los datos del movimiento
		*/
		void 				clear_movement						(										);
		/**
			\brief Se setea el tiempo entre dos puntos de un mismo moviemiento.
		*/
		void 				set_time_between_two_points_millisecons(		double tbtpm 				);
		/**
			\brief Se obtiene el tiempo entre dos puntos de un mismo movimiento
		*/
		int 				get_time_between_tw0_points_millisecons(									);


	
	private:
		int 						length_position;
		int 						length_velocity;
		vector < vector <double> > 	list_motor_angle_positions;
		vector < vector <double> > 	list_motor_velocities;
		double 						time_between_two_points_millisecons;
};