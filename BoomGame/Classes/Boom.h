#ifndef _BOOM_H_
#define _BOOM_H_
#include "cocos2d.h"
USING_NS_CC;


//enum BoomType
//{
//	BOOM_TYPE_1,
//	BOOM_TYPE_2
//};
class Boom : public Sprite{
public :
	bool init();
	CREATE_FUNC(Boom);
	void setBoomProperty(int type);
private:
	int range;//��ը��Χ
	int weight;//ը������
	int type;//ը������
	int damage;
};
#endif