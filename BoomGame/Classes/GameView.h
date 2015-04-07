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
private :
	Boom* createBoom();//产生一个炸弹
};



#endif