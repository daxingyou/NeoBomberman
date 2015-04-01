#include "GamePayHandler.h"
#include "GameData.h"

static GamePayHandler* _instance = nullptr;
GamePayHandler* GamePayHandler::getInstance()
{
	if (!_instance)
	{
		_instance = new GamePayHandler();
	}
	return _instance;
}

void GamePayHandler::payCallback(int requestId,int resultId){
	//GAMESTATE::getInstance()->setIsPaying(false);
	switch (requestId)
	{
	case 1:
		//GAMESTATE::getInstance()->setGamePause(false);
		break;
	default:
		//GAMESTATE::getInstance()->setGamePause(false);
		break;
	}
}

