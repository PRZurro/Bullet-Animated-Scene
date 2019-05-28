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

	float Kinematic_Rigid_Body::move_to(const gltVec3& to, float speed)
	{
		gltVec3 from = extract_translation(model_->get_transformation());
		gltVec3 direction = glm::normalize(to - from);

		btVector3 btDirection = btVector3(direction.x, direction.y, direction.z);
		btVector3 totalTranslation = btDirection * speed;

		translate(totalTranslation);

		return glm::length(to - from);
	}

	void Kinematic_Rigid_Body::sync_model_with_rigid_body()
	{
		// Instead of get the motion state, it should take the 
		btTransform physicsTransform = rigidBody_->getWorldTransform();
		Matrix44 bulletTransform;

		physicsTransform.getOpenGLMatrix(glm::value_ptr(bulletTransform));

		model_->set_transformation(bulletTransform);
		model_->scale(scale_.x, scale_.y, scale_.z); // Reset the
	}
}
