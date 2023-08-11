#include "GameWorld.h"
#include "AIBullet.h"
#include "BoundingSphere.h"

// PUBLIC INSTANCE CONSTRUCTORS ///////////////////////////////////////////////

/** Constructor. AIBullets live for 2s by default. */
AIBullet::AIBullet()
	: GameObject("AIBullet"), mTimeToLive(2000)
{
}

/** Construct a new AIBullet with given position, velocity, acceleration, angle, rotation and lifespan. */
AIBullet::AIBullet(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r, int ttl)
	: GameObject("AIBullet", p, v, a, h, r), mTimeToLive(ttl)
{
}

/** Copy constructor. */
AIBullet::AIBullet(const AIBullet& b)
	: GameObject(b),
	mTimeToLive(b.mTimeToLive)
{
}

/** Destructor. */
AIBullet::~AIBullet(void)
{
}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////

/** Update AIBullet, removing it from game world if necessary. */
void AIBullet::Update(int t)
{
	// Update position/velocity
	GameObject::Update(t);
	// Reduce time to live
	mTimeToLive = mTimeToLive - t;
	// Ensure time to live isn't negative
	if (mTimeToLive < 0) { mTimeToLive = 0; }
	// If time to live is zero then remove AIBullet from world
	if (mTimeToLive == 0) {
		if (mWorld) mWorld->FlagForRemoval(GetThisPtr());
	}

}

bool AIBullet::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Asteroid")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void AIBullet::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}
