#ifndef _GAME_PAY_HANDLER_H_
#define _GAME_PAY_HANDLER_H_
#include "cocos2d.h"

class GamePayHandler
{       
public:
	GamePayHandler() {};
	~GamePayHandler() {};  
	void payCallback(int requestId,int resultId);
	static GamePayHandler* getInstance();
};
#endif

