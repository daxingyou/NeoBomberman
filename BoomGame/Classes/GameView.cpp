#include "GameView.h"

bool GameView::init(){
	if (!Layer::init()){
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//boom test 
	Boom* boom_1 = createBoom(1);
	boom_1->setAnchorPoint(Point::ANCHOR_MIDDLE);
	boom_1->setPosition(visibleSize.width/2, visibleSize.height/2);
	this->addChild(boom_1);
	//add touch event
	auto touchEvent = EventListenerTouchOneByOne::create();
	touchEvent->onTouchBegan = CC_CALLBACK_2(GameView::onTouchBegan,this);
	touchEvent->onTouchMoved = CC_CALLBACK_2(GameView::onTouchMoved,this);
	touchEvent->onTouchEnded = CC_CALLBACK_2(GameView::onTouchEnded, this);
	return true;
}

Boom* GameView::createBoom(int id){
	Boom* boom = Boom::create();
	boom->setBoomProperty(id);
	return boom;
}

bool GameView::onTouchBegan(Touch *touch, Event  *event){
	return true;
}

void GameView::onTouchMoved(Touch *touch, Event  *event){

}

void GameView::onTouchEnded(Touch *touch, Event  *event){

}