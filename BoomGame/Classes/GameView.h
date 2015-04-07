#ifndef _GAMEVIEW_H_
#define _GAMEVIEW_H_
#include "cocos2d.h"
#include "Boom.h"
USING_NS_CC;

class GameView :public Layer{
public:
	bool init();
	CREATE_FUNC(GameView);
	bool onTouchBegan(Touch *touch, Event  *event);
	void onTouchMoved(Touch *touch, Event  *event);
	void onTouchEnded(Touch *touch, Event  *event);
	float getDegreeByPoint(Point sp,Point ep);
	float getForceByDistance(float distance);
	void update(float dt);
private :
	Boom* createBoom(int id);//产生一个炸弹
	Boom* curBoom;
	Point touchlocation;
	float degree;//发射角度
	float force;
	float speed_x;
	float speed_y;
	void initData();
	boolean shoting;
};



#endif