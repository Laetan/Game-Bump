#pragma once
#include "MovingObject.h"

class Bump : public MovingObject
{
	const float NORMAL_SIZE = 8.0f;
public:
	Bump(int x, int y, float size = 1.0f);
	~Bump();

	void flick(cocos2d::Vec2);
	
};

