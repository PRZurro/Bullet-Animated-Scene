#include <Rigid_Body.hpp>

#include <Utilities.hpp>

namespace prz
{

	Rigid_Body::Rigid_Body
	(
		const PString& name,
		PSPtr<Model> model,
		btVector3& origin,
		btQuaternion& initialRotation,
		RB_Construct_Info constructionInfo,
		const gltVec3& scale
	) :
		model_(model),
		name_(name),
		constructionInfo_(constructionInfo)
	{
		constructionInfo_.motionState.reset(new btDefaultMotionState(create_transformation(origin, initialRotation)));
		rigidBody_ = new btRigidBody(constructionInfo_);
		rigidBody_->setFriction(0.7f);
		rigidBody_->setRestitution(0.7f);

		set_scale(scale);

		sync_model_with_rigid_body();
	}
	Rigid_Body::~Rigid_Body()
	{
		delete rigidBody_;
	}
	void Rigid_Body::update(float deltaTime)
	{
		sync_model_with_rigid_body();
		auxiliar_update(deltaTime);
	}
	void Rigid_Body::set_transformation(btTransform& newTransformation)
	{
		rigidBody_->setWorldTransform(newTransformation);
	}

	void Rigid_Body::reset_transformation(btVector3& newOrigin, btQuaternion& newRotation)
	{
		set_transformation(create_transformation(newOrigin, newRotation));
	}

	void Rigid_Body::sync_model_with_rigid_body()
	{
		btTransform physicsTransform;
		Matrix44 bulletTransform;

		btMotionState* m = rigidBody_->getMotionState();

		rigidBody_->getMotionState()->getWorldTransform(physicsTransform);
		physicsTransform.getOpenGLMatrix(glm::value_ptr(bulletTransform));

		model_->set_transformation(bulletTransform);
		model_->scale(scale_.x, scale_.y, scale_.z); // Reset the lost scale in the OpenGL matrix calculation from bullet
	}
}
