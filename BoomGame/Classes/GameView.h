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
	float getSpeedByDistance(float distance);
	void update(float dt);
	void updateTest(float dt);
	std::vector <Point> calculateSubLine(Point sp,float speed, float degree);//计算辅助线
private :
	Boom* createBoom(int id);//产生一个炸弹
	Boom* curBoom;
	Point touchlocation;
	float degree;//发射角度
	float speed;//物体初速度
	void initData();
	boolean shoting;
	std::vector <Point> subline;//辅助线
};
#endif