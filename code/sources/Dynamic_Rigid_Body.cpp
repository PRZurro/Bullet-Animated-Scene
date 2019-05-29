#include <Dynamic_Rigid_Body.hpp>

#include <Rigid_Body_Construction_Info.hpp>

namespace prz
{
	Dynamic_Rigid_Body::Dynamic_Rigid_Body
	(
		const PString& name,
		PSPtr<gltModel> model,
		btVector3& origin,
		PSPtr<btCollisionShape> collisionShape,
		btScalar mass,
		btQuaternion initialRotation,
		btVector3 localInertia,
		const gltVec3& scale
	) :
		Rigid_Body(name, model, origin, initialRotation, RB_Construct_Info(collisionShape, mass, localInertia), scale)
	{
		rigidBody_->setActivationState(DISABLE_DEACTIVATION);
	}

	Dynamic_Rigid_Body::~Dynamic_Rigid_Body()
	{
	}
}
