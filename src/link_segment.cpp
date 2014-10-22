#ifndef LINK_SEGMENT_CPP
#define LINK_SEGMENT_CPP

#include "link_segment.hpp"



void Link_segment::set_matrix(RotMatrix matrix){
	this->matrix = matrix;
}

RotMatrix Link_segment::get_matrix(){
	return matrix;
}



#endif