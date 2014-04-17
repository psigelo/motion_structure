#include <vector>

using namespace std;

class Movement{
	public:
		Movement();
		int 				get_length_position					(										);
		int 				get_length_velocity					(										);
		void			 	add_to_list_motor_angle_positions	( 	vector <double> angle_position_data	);
		vector <double>		get_from_list_motor_angle_position	( 	int position						);
		void			 	add_to_list_motor_velocities		( 	vector <double> velocity_data		);
		vector <double>		get_from_list_motor_velocities		( 	int position						);
		void 				clear_movement						(										);
		
	
	private:
		int 						length_position;
		int 						length_velocity;
		vector < vector <double> > 	list_motor_angle_positions;
		vector < vector <double> > 	list_motor_velocities;
};