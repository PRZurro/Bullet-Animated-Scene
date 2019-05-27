#include <Static_Rigid_Body.hpp>

#include <Rigid_Body_Construction_Info.hpp>

namespace prz
{
	Static_Rigid_Body::Static_Rigid_Body
	(
		const PString& name,
		PSPtr<Model> model,
		btVector3& origin,
		PSPtr<btCollisionShape> collisionShape,
		btQuaternion initialRotation,
		const gltVec3& scale
	) :
		Rigid_Body(name, model, origin, initialRotation, RB_Construct_Info(collisionShape, 0.f), scale)
	{
		rigidBody_->setCollisionFlags(rigidBody_->getCollisionFlags() | btCollisionObject::CF_STATIC_OBJECT);
	}
}
