#ifndef __AIBULLET_H__
#define __AIBULLET_H__

#include "GameUtil.h"
#include "GameObject.h"

class AIBullet : public GameObject
{
public:
	AIBullet();
	AIBullet(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r, int ttl);
	AIBullet(const AIBullet& b);
	virtual ~AIBullet(void);

	virtual void Update(int t);

	void SetTimeToLive(int ttl) { mTimeToLive = ttl; }
	int GetTimeToLive(void) { return mTimeToLive; }

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

protected:
	int mTimeToLive;
};

#endif