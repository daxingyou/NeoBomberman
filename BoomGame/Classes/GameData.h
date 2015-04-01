#ifndef _GAMEDATA_H_
#define _GAMEDATA_H_

class GAMEDATA{
public:
	static GAMEDATA* getInstance();

	void clear();
	void setSoundState(bool state);
	bool getSoundState();
	void setMusicState(bool state);
	bool getMusicState();

	//CC_SYNTHESIZE(std::string, curBgName, CurBgName);
	//CC_SYNTHESIZE(std::string, curMapName, CurMapName);
	//CC_SYNTHESIZE(int, money, Money);
	//CC_SYNTHESIZE(int, groupNum, GroupNum);
	//CC_SYNTHESIZE(std::string, currLevelFile, CurrLevelFile);
	//CC_SYNTHESIZE(std::string, nextLevelFile, NextLevelFile);
	//CC_SYNTHESIZE(bool, isFinishedAddGroup, isFinishedAddGroup);

private:
	GAMEDATA();
	void init();
	static GAMEDATA* _instance;
};

#endif
