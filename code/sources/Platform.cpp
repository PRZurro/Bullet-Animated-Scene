#include <Platform.hpp>

namespace prz
{
	Platform::Platform(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{

	}
	void Platform::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}