#include <Kinematic_Rigid_Body.hpp>

namespace prz
{
	Kinematic_Rigid_Body::Kinematic_Rigid_Body
	(
		const PString& name,
		PSPtr<Model> model,
		btVector3& origin,
		PSPtr<btCollisionShape> collisionShape,
		btQuaternion initialRotation,
		const gltVec3& scale
	) :
		Static_Rigid_Body(name, model, origin, collisionShape, initialRotation, scale)
	{
		rigidBody_->setCollisionFlags(rigidBody_->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	}

	void Kinematic_Rigid_Body::translate(btVector3& translation)
	{
		btTransform newTrans = rigidBody_->getWorldTransform();
		newTrans.getOrigin() += translation;
		set_transformation(newTrans);
	}

	void Kinematic_Rigid_Body::rotate(btQuaternion& rotation)
	{
		btTransform newTrans = rigidBody_->getWorldTransform();
		newTrans.getRotation() *= rotation;
		set_transformation(newTrans);
	}
}
