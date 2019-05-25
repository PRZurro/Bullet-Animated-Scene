#include "Entity.hpp"

#include <Rigid_Body.hpp>

namespace prz
{
	void Entity::update(float deltaTime)
	{
		for (auto& pair : rigidBodies_)
		{
			btTransform physicsTransform;
			Matrix44 bulletTransform;

			PSPtr<btRigidBody> rigidBody= *pair.second;
			PSPtr<gltModel> model = *pair.second;

			rigidBody->getMotionState()->getWorldTransform(physicsTransform);
			physicsTransform.getOpenGLMatrix(glm::value_ptr(bulletTransform));

			model->set_transformation(bulletTransform); 
			model->scale(pair.second->scale()); // Reset the lost scale in the OpenGL matrix calculation from bullet
		}
	}
}
