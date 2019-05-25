#include <Kinematic_Rigid_Body .hpp>

namespace prz
{
	Kinematic_Rigid_Body::Kinematic_Rigid_Body
	(
		const PString& name,
		btVector3& origin,
		btQuaternion& initialRotation,
		PSPtr<btCollisionShape> collisionShape,
		float scale
	) :
		Static_Rigid_Body(name, origin, initialRotation, collisionShape, scale)
	{
		rigidBody_->setCollisionFlags(rigidBody_->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	}
	Kinematic_Rigid_Body::~Kinematic_Rigid_Body()
	{
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
