#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;

class GameLayer : public Layer{
public:
	bool init();
	CREATE_FUNC(GameLayer);

};
#endif