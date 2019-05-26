#include <Door.hpp>

namespace prz
{
	Door::Door(Scene& scene, const PString& name) :
		Entity(scene, name)
	{
	}
	void Door::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}
