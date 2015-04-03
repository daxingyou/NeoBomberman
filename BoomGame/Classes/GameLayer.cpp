#include "GameLayer.h""

bool GameLayer::init(){
	if (!Layer::init()){
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//Ìí¼ÓÓÎÏ·±³¾°
	Sprite* game_bg = Sprite::create("game_bg.png");
	game_bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(game_bg, -1);
	return true;

}