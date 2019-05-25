#include "Entity.hpp"

#include <Dynamic_Rigid_Body.hpp>
#include <Kinematic_Rigid_Body .hpp>
#include <Static_Rigid_Body.hpp>

namespace prz
{
	void Entity::update(float deltaTime)
	{
		for (auto& pair : rigidBodies_)
		{
			PSPtr<Rigid_Body> rigidBody = pair.second;

			pair.second->update(deltaTime);

		}
	}
	void Entity::translate(btVector3& translation)
	{
		for (auto& pair : kinematicRigidBodies_)
		{
			pair.second->translate(translation);
		}
	}
}
