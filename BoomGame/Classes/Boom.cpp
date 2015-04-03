#include "Boom.h"

bool Boom::init(){
	if (!Sprite::init()){
		return false;
	}
	return true;
}