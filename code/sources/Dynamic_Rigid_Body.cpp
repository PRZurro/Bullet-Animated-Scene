#include <Dynamic_Rigid_Body.hpp>

#include <Rigid_Body_Construction_Info.hpp>

namespace prz
{
	Dynamic_Rigid_Body::Dynamic_Rigid_Body
	(
		const PString& name,
		btVector3& origin,
		btQuaternion& initialRotation,
		PSPtr<btCollisionShape> collisionShape,
		btScalar mass,
		btVector3 localInertia,
		float scale
	) :
		Rigid_Body(name, origin, initialRotation, RB_Construct_Info(collisionShape, mass, localInertia), scale)
	{
		rigidBody_->setActivationState(DISABLE_DEACTIVATION);
	}
	Dynamic_Rigid_Body::~Dynamic_Rigid_Body()
	{
	}
}