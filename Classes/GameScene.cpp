#include "GameScene.h"
#include "Bump.h"

USING_NS_CC;

cocos2d::Scene * GameScene::createScene()
{
	return GameScene::create();
}

bool GameScene::init()
{
	if (!Scene::initWithPhysics()) return false;

	auto screenSize = Director::getInstance()->getVisibleSize();
	getPhysicsWorld()->setDebugDrawMask(true);

	bumper = new Bump(screenSize.width / 2, screenSize.height / 2);
	this->addChild(bumper->getSprite());
	velocityLabel = Label::createWithSystemFont("Bump : ", "Arial", 50);
	velocityLabel->setAnchorPoint(Vec2(1, 0));
	velocityLabel->setPosition(Vec2(screenSize.width, 0));
	this->addChild(velocityLabel);
	flickSprite = Sprite::create("flick.png");
	flickSprite->setAnchorPoint(Vec2(0.5f, 0));
	Size bumperSize = bumper->getSprite()->getContentSize();
	flickSprite->setPosition(bumperSize.width / 2, bumperSize.height / 2);
	flickSprite->setRotation(90);
	flickSprite->setScaleY(0.5f);
	bumper->getSprite()->addChild(flickSprite,-10);



	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* event) {
		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event) {
		Vec2 move(touch->getStartLocation(), touch->getLocation());
		float angle =180 + CC_RADIANS_TO_DEGREES( move.getAngle(Vec2(0, 1)));
		float speed = move.length()*0.05f;
		(speed > 5) && (speed = 5);
		flickSprite->setRotation(angle);
		flickSprite->setScaleY(speed);
		flickSprite->setScaleX(speed/2.0f);
		return ;
	};

	listener->onTouchCancelled = listener->onTouchEnded = [=](Touch* touch, Event* event) {
		Vec2 move(touch->getLocation(), touch->getStartLocation());
		bumper->flick(move * 10);
		flickSprite->setScale(0.5f);
		return ;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//scheduleUpdate();
	return true;

}

void GameScene::update(float delta) {
	Vec2 v = bumper->getSprite()->getPhysicsBody()->getVelocity();
	float velo = v.getLength();
	char str[500];
	char* format = "Bump : %.2f";
	sprintf(str, format, velo);
	velocityLabel->setString(str);
}

