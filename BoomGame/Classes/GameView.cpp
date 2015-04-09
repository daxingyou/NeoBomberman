#include "GameView.h"
#define GRAVITR (10)
#define MAX_SPEED (25)//抛出物体的最大速度


bool GameView::init(){
	if (!Layer::init()){
		return false;
	}
	initData();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//boom test 
    curBoom = createBoom(1);
	curBoom->setAnchorPoint(Point::ANCHOR_MIDDLE);
	curBoom->setPosition(visibleSize.width / 5, visibleSize.height / 4);
	this->addChild(curBoom);
	//add touch event
	auto touchEvent = EventListenerTouchOneByOne::create();
	touchEvent->onTouchBegan = CC_CALLBACK_2(GameView::onTouchBegan,this);
	touchEvent->onTouchMoved = CC_CALLBACK_2(GameView::onTouchMoved,this);
	touchEvent->onTouchEnded = CC_CALLBACK_2(GameView::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, this);
	//scheduleUpdate();
	schedule(schedule_selector(GameView::updateTest),1.0f, kRepeatForever,0);
	return true;
}

void GameView::initData(){
	 degree = 0;
	 speed = 0;
	 //speed_x = 0;
	 //speed_y = 0;
	 shoting = false;
}

Boom* GameView::createBoom(int id){
	Boom* boom = Boom::create();
	boom->setBoomProperty(id);
	return boom;
}

bool GameView::onTouchBegan(Touch *touch, Event  *event){
	touchlocation = touch->getLocation();
	CCLOG("onTouch Began");
	return true;
}

void GameView::onTouchMoved(Touch *touch, Event  *event){
	Point curpoint = touch->getLocation();
	int distance = curpoint.distance(touchlocation);

}

void GameView::onTouchEnded(Touch *touch, Event  *event){
	Point endpint = touch->getLocation();
	int distance = endpint.distance(touchlocation);
	degree = getDegreeByPoint(touchlocation, endpint);
	//get the force by distance
	speed = getSpeedByDistance(distance);
	shoting = true;
}

float GameView::getDegreeByPoint(Point sp,Point ep){
	float deg = atan(abs(ep.y - sp.y) / abs(ep.x - sp.x));
	CCLOG("DEGREE = %f", CC_RADIANS_TO_DEGREES(deg));
	//decide the direction
	return deg;
}

//get force by move distacne
float GameView::getSpeedByDistance(float distance){
	if (distance > 0){
		float mySpeed = distance * 1;//
		if (mySpeed > MAX_SPEED){
			mySpeed = MAX_SPEED;
		}
		return mySpeed;
	}
	return 0;
}

void GameView::update(float dt){
	if (shoting){
		/*speed_y += GRAVITR*dt;
		curBoom->setPosition(curBoom->getPosition().x + speed_x, curBoom->getPosition().y - speed_y);*/
	}	
}

void GameView::updateTest(float dt){
	if (shoting){
		//speed_y += GRAVITR*dt;
		//curBoom->setPosition(curBoom->getPosition().x + speed_x, curBoom->getPosition().y - speed_y);
	}
}

std::vector <Point> GameView::calculateSubLine(Point sp,float speed, float degree){
	float speed_x = speed*cos(degree);
	float speed_y = speed*sin(degree);
	float t = speed_y / GRAVITR;
	Point top = Point(sp.x+speed_x*t, sp.y+speed_y - GRAVITR*t*t / 2);//抛物线的顶点坐标
	//间隔5个像素，绘制一个点
	float y = sp.y;
	float x = sp.x;
	while (y > 0){
		x += 5;
		y = -(x - top.x)*(x - top.x) + top.y;
		subline.push_back(Point(x,y));
	}
	return subline;
} 