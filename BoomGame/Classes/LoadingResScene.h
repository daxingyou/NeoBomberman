#ifndef __LOADING_RESSECNE_H__
#define __LOADING_RESSECNE_H__

#include <iostream>
#include "cocos2d.h"
#include "LoadLevelInfo.h"
USING_NS_CC;

class LoadingResScene : public Layer
{
public:

	LoadingResScene();
    CREATE_FUNC(LoadingResScene);
    static Scene * createScene();
	virtual bool init();
    
    ProgressTimer *addProgress();
    void loadResources();
	void transitionScene();
	void loadingCallBack(cocos2d::Texture2D *texture);
    void logic(float dt);
	~LoadingResScene();
private:
    
	ProgressTimer* progressBar;
	int numberOfLoadedRes;
	int totalOfLoadedRes;
};
#endif 
