#include "Boom.h"
#include "BoomInfoUtil.h"

bool Boom::init(){
	if (!Node::init()){
		return false;
	}
	myBoom = Sprite::create("boom.png");
	myBoom->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	myBoom->setPosition(0,0);
	this->addChild(myBoom);
	return true;
}


void Boom::setBoomProperty(int type){
	BoomInfo info = BoomInfoUtil::getInstance()->getInfoById(type);
	string str = info.image_name + ".png";
	CCLOG("name =  %s", str.c_str());
	Texture2D* texture = TextureCache::getInstance()->addImage(str);
	myBoom->setTexture(texture);
	this->range = info.range;
	this->damage = info.damage;
	this->weight = info.weight;
}