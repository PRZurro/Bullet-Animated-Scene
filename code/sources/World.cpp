#include <World.hpp>

namespace prz
{
	World::World() :
		collisionDispatcher_(&collisionConfiguration_),
		dynamicsWorld_(make_shared<btDiscreteDynamicsWorld>(&collisionDispatcher_, &overlappingPairCache_, &constraintSolver_, &collisionConfiguration_))
	{}
}