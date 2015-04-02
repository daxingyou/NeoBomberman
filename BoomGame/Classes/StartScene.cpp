#include "StartScene.h"
#include "GameScene.h"
USING_NS_CC;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    // 1. super init fir
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Ìí¼ÓÓÎÏ·±³¾°
	Sprite* game_bg = Sprite::create("game_bg.png");
	game_bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(game_bg,-1);

	//for test create a start button
	MenuItemImage* image = MenuItemImage::create("start_game_txt.png", "start_game_txt.png", CC_CALLBACK_0(StartScene::startGame,this));
	Menu* start_menu = Menu::create(image, NULL);
	start_menu->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(start_menu);
    return true;

}

void StartScene::startGame(){
	Director::getInstance()->replaceScene(TransitionFade::create(1, GameScene::create()));
}