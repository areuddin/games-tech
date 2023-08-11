#ifndef __AISPACESHIP_H__
#define __AISPACESHIP_H__

#include "GameUtil.h"
#include "GameObject.h"
#include "Shape.h"

class AISpaceship : public GameObject
{
public:
	AISpaceship();
	AISpaceship(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r);
	AISpaceship(const AISpaceship& s);
	virtual ~AISpaceship(void);

	virtual void Update(int t);
	virtual void Render(void);

	virtual void Thrust(float t);
	virtual void Rotate(float r);
	virtual void Shoot(void);

	void SetAISpaceshipShape(shared_ptr<Shape> spaceship_shape) { mAISpaceshipShape = spaceship_shape; }
	void SetAIThrusterShape(shared_ptr<Shape> thruster_shape) { mAIThrusterShape = thruster_shape; }
	void SetAIBulletShape(shared_ptr<Shape> bullet_shape) { mAIBulletShape = bullet_shape; }

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

private:
	float mThrust;

	shared_ptr<Shape> mAISpaceshipShape;
	shared_ptr<Shape> mAIThrusterShape;
	shared_ptr<Shape> mAIBulletShape;
};

#endif