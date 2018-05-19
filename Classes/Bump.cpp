#include "Bump.h"
#include "cocos2d.h"

USING_NS_CC;
Bump::Bump(int x, int y, float size) : MovingObject(x,y,size)
{
	float trueSize = size * NORMAL_SIZE;
	_sprite = Sprite::create("Bumper-normal.png");
	PhysicsMaterial mat(1.0f, 1.0f, 1000.0f);
	auto body = PhysicsBody::createCircle(50, mat);

	body->setDynamic(true);
	body->setGravityEnable(false);
	body->setLinearDamping(1.0f);
	_sprite->setPhysicsBody(body);
	_sprite->setScale(0.5f);
	_sprite->setPosition(x, y);
}

Bump::~Bump()
{
}

void Bump::flick(cocos2d::Vec2 force)
{
	
	if (force.length() > 1000.0f) {
		force.normalize();
		force.scale(1000.0f);
	}
	_sprite->getPhysicsBody()->setVelocity(force);
	//_sprite->setOpacity(0.5);
}
