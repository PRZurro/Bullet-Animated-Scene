#include <Key.hpp>

namespace prz
{
	Key::Key(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{
	}
	void Key::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}