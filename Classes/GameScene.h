#pragma once

#include "cocos2d.h"
#include "Bump.h"

USING_NS_CC;
/**
	This class will host the main game screen
*/
class GameScene : public Scene
{
	Bump* bumper;
	cocos2d::Sprite* flickSprite;
	cocos2d::Label *velocityLabel;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	bool onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	bool onTouchEnd(cocos2d::Touch*, cocos2d::Event*);

	void update(float) override;
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

