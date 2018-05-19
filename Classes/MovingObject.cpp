#include "MovingObject.h"


MovingObject::MovingObject(int x, int y, float size) : _x(x), _y(y), _size(size)
{
	
}

MovingObject::~MovingObject()
{}


cocos2d::Sprite * MovingObject::getSprite()
{
	return _sprite;
}

