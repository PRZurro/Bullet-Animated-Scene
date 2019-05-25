#include <Rigid_Body.hpp>

#include <Rigid_Body_Construction_Info.hpp>

namespace prz
{

	Rigid_Body::Rigid_Body
	(
		const PString& name,
		btVector3& origin,
		btQuaternion& initialRotation,
		RB_Construct_Info constructionInfo,
		float scale
	) :
		scale_(scale)
	{
		btTransform transform;

		transform.setIdentity();
		transform.setOrigin(origin);
		transform.setRotation(initialRotation);

		constructionInfo.motionState = make_shared<btMotionState>(transform);
		rigidBody_ = make_shared<btRigidBody>(constructionInfo);

		sync_model_with_rigid_body();
	}
	Rigid_Body::~Rigid_Body()
	{
	}
	void Rigid_Body::update(float deltaTime)
	{
		sync_model_with_rigid_body();
		auxiliar_update(deltaTime);
	}
	void Rigid_Body::sync_model_with_rigid_body()
	{
		btTransform physicsTransform;
		Matrix44 bulletTransform;

		rigidBody_->getMotionState()->getWorldTransform(physicsTransform);
		physicsTransform.getOpenGLMatrix(glm::value_ptr(bulletTransform));

		model_->set_transformation(bulletTransform);
		model_->scale(scale_); // Reset the lost scale in the OpenGL matrix calculation from bullet
	}
}