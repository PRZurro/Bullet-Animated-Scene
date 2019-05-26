#include <World.hpp>

namespace prz
{
	World::World(btVector3& gravity) :
		collisionDispatcher_(&collisionConfiguration_),
		dynamicsWorld_(new btDiscreteDynamicsWorld(&collisionDispatcher_, &overlappingPairCache_, &constraintSolver_, &collisionConfiguration_))
	{
		dynamicsWorld_->setGravity(gravity);
	}
	World::~World()
	{
		delete dynamicsWorld_;
	}
}