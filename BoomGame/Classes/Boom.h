#ifndef _BOOM_H_
#define _BOOM_H_
#include "cocos2d.h"
USING_NS_CC;

class Boom : public Node{
public :
	bool init();
	CREATE_FUNC(Boom);
	void setBoomProperty(int id);
private :
	Sprite* myBoom;
	int range;
	int damage;
	int weight;
};
#endif