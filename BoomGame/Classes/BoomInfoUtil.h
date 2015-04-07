#ifndef _IMAGE_INFO_UTIL_
#define _IMAGE_INFO_UTIL_
#include "BoomInfo.h"
#include "cocos2d.h"
#include <map>
using namespace cocos2d;
using namespace std;

class BoomInfoUtil{
public:
	static BoomInfoUtil* getInstance();
	BoomInfo getInfoById(int id);
private:
	void init();
	BoomInfoUtil();
	~BoomInfoUtil();
private:
	static BoomInfoUtil* m_instance;
	std::map<int, BoomInfo> infoMap;

};
#endif