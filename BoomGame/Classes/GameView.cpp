#include "GameView.h"

bool GameView::init(){
	if (!Layer::init()){
		return false;
	}
	//添加点击事件
	auto touchEvent = EventListenerTouchOneByOne::create();
	touchEvent->onTouchBegan = CC_CALLBACK_2(GameView::onTouchBegan,this);
	touchEvent->onTouchMoved = CC_CALLBACK_2(GameView::onTouchMoved,this);
	touchEvent->onTouchEnded = CC_CALLBACK_2(GameView::onTouchEnded, this);
	return true;
}

Boom* GameView::createBoom(){
	Boom* boom = Boom::create();
}