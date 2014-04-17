#include <armadillo>

using namespace arma;

enum SegmentType{
	LINK_SEGMENT,
	MOTOR
};


class Link_segment{ // lista de segmentos
	private:
		mat 	matrix;
	public:
		mat 	get_matrix 	();
		void 	set_matrix 	(mat matrix);
};