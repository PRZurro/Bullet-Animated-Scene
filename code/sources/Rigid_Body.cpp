#include <Rigid_Body.hpp>

namespace prz
{

	Rigid_Body::Rigid_Body(const PString& name, PSPtr<btCollisionShape> collisionShape)
	{
		btTransform transform;
		transform.setIdentity();
		transform.setOrigin(btVector3(0, 10, 0));
	}

	Rigid_Body::~Rigid_Body()
	{
	}
}