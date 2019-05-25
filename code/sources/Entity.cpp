#include "Entity.hpp"

#include <Rigid_Body.hpp>

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
}
