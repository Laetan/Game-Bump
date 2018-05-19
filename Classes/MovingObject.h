#pragma once
#include "cocos2d.h"

class MovingObject
{
protected:
	float _size;
	int _x, _y;
	float _speed;
	double _direction;
	cocos2d::Sprite * _sprite;
	cocos2d::PhysicsBody * _body;
public:
	MovingObject(int x = 0, int y = 0, float size = 0);
	~MovingObject();

	//virtual void move(float delta) = 0;

	cocos2d::Sprite* getSprite();
};

