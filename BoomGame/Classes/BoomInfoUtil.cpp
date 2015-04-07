#include "BoomInfoUtil.h"
#include "json/document.h"
#include "json/rapidjson.h"
#define RETURN_IF(cond)           if((cond)) return

BoomInfoUtil* BoomInfoUtil::m_instance = nullptr;

BoomInfoUtil::BoomInfoUtil(){
	init();
}

BoomInfoUtil::~BoomInfoUtil(){
	CC_SAFE_DELETE(m_instance);
}


BoomInfoUtil* BoomInfoUtil::getInstance(){
	if(m_instance == nullptr){
		m_instance = new BoomInfoUtil();
	}
	return m_instance;
}


void BoomInfoUtil::init(){
	string jsonStr = FileUtils::getInstance()->getStringFromFile("json/boomInfo.json");
	rapidjson::Document _mDoc;
	string mstr = jsonStr;
	RETURN_IF(NULL==mstr.c_str()||!mstr.compare(""));
	_mDoc.Parse<0>(mstr.c_str());
	RETURN_IF(_mDoc.HasParseError() || !_mDoc.IsObject());
	const rapidjson::Value &pArr = _mDoc["boom"];
	CCLOG("boom type size = %d",pArr.Capacity());
	for(int i=0;i<pArr.Capacity();++i){
		BoomInfo info;
		const rapidjson::Value &temp = pArr[i];
		int key = temp["id"].GetInt();
		info.id = key;
		info.image_name=temp["name"].GetString();
		info.range = temp["range"].GetInt();
		info.weight = temp["weight"].GetInt();
		infoMap.insert(make_pair(key,info));
	}
	return;
}

BoomInfo BoomInfoUtil::getInfoById(int id){
	auto it = infoMap.find(id);
	CCASSERT(it!=infoMap.end(),"can't get boom info of the id");
	return it->second;
}


