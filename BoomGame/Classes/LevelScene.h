#ifndef __LEVELSCENE_H__
#define __LEVELSCENE_H__

#include <iostream>
#include "cocos2d.h"

class LevelScene : public cocos2d::Scene
{
public:  

    virtual bool init();  
    CREATE_FUNC(LevelScene);
    void menuCloseCallback(Ref* pSender);
    static LevelScene *getInstance();
    
private:
    static LevelScene *instance;
}; 
#endif 
