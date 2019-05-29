#include <Kinematic_Rigid_Body.hpp>

#include <Utilities.hpp>

namespace prz
{
	Kinematic_Rigid_Body::Kinematic_Rigid_Body
	(
		const PString& name,
		PSPtr<gltModel> model,
		btVector3& origin,
		PSPtr<btCollisionShape> collisionShape,
		const gltVec3& linearFactor,
		btQuaternion initialRotation,
		const gltVec3& scale
	) :
		Static_Rigid_Body(name, model, origin, collisionShape, initialRotation, scale)
	{
		rigidBody_->setLinearFactor(bt_vec3_from(linearFactor));
		rigidBody_->setAngularFactor(bt_vec3_from(gltVec3(0.f)));
		rigidBody_->setGravity(bt_vec3_from(gltVec3(0.f)));
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

		// NOT WORKING
	}

	float Kinematic_Rigid_Body::move_to(const gltVec3& to, float speed, float deltaTime)
	{
		// Calculate the direction of the movement
		gltVec3 from = glt_vec3_from(rigidBody_->getWorldTransform().getOrigin());
		btVector3 direction = bt_vec3_from(glm::normalize(to - from));

		// Calculate the movement
		rigidBody_->translate(direction * speed * deltaTime);
		rigidBody_->setLinearVelocity(direction * speed); // If the linear velocity is not applied the objects over this will only fall by gravity, won't be afected by the movement of this kinematic object.

		// Update the current position to avoid unwanted movement in some frames
		return glm::distance(from, to);
	}

	void Kinematic_Rigid_Body::sync_model_with_rigid_body()
	{
		// Instead of get the motion state, it should take the 
		btTransform physicsTransform = rigidBody_->getWorldTransform();
		Matrix44 bulletTransform;

		physicsTransform.getOpenGLMatrix(glm::value_ptr(bulletTransform));

		model_->set_transformation(bulletTransform);
		model_->scale(scale_.x, scale_.y, scale_.z); 
	}
}
