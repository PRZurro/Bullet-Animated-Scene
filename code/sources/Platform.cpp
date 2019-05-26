#include <Platform.hpp>

namespace prz
{
	Platform::Platform(Scene& scene, const PString& name) :
		Entity(scene, name)
	{
	}
	void Platform::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}