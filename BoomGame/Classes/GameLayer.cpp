#include "GameLayer.h"
#include "GameView.h"

bool GameLayer::init(){
	if (!Layer::init()){
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//add game background
	Sprite* game_bg = Sprite::create("game_bg.png");
	game_bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(game_bg, -1);
    
	//add game view 
	GameView* view = GameView::create();
	view->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	view->setPosition(0,0);
	this->addChild(view);

	return true;

}