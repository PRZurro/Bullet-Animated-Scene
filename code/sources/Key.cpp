#include <Key.hpp>

namespace prz
{
	Key::Key(Scene& scene, const PString& name) :
		Entity(scene, name)
	{
	}
	void Key::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}