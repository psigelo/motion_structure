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
		/**
			\brief Devuelve la matriz asociada al segmento.
		*/
		mat 	get_matrix 	();
		/**
			\brief Se le asigna la matriz de rotación al segmento.
		*/
		void 	set_matrix 	(mat matrix);
};