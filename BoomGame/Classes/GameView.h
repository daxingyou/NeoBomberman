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
	std::vector <Point> calculateSubLine(Point sp,float speed, float degree);//���㸨����
private :
	Boom* createBoom(int id);//����һ��ը��
	Boom* curBoom;
	Point touchlocation;
	float degree;//����Ƕ�
	float speed;//������ٶ�
	void initData();
	boolean shoting;
	std::vector <Point> subline;//������
};
#endif