#ifndef LINK_SEGMENT_HPP
#define LINK_SEGMENT_HPP

#include "RotMatrix.hpp"

enum SegmentType{
	LINK_SEGMENT,
	MOTOR
};


class Link_segment{ // lista de segmentos
	private:
		RotMatrix 	matrix;
	public:
		/**
			\brief Devuelve la matriz asociada al segmento.
		*/
		RotMatrix 	get_matrix 	();
		/**
			\brief Se le asigna la matriz de rotación al segmento.
		*/
		void 	set_matrix 	(RotMatrix matrix);
};

#endif