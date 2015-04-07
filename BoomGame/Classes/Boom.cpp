#include "Boom.h"

bool Boom::init(){
	if (!Sprite::init()){
		return false;
	}
	return true;
}

void Boom::setBoomProperty(int type){
	switch (type)
	{
	case 0:
		this->range = 50;
		this->weight = 100;
		this->damage = 100;
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}

}