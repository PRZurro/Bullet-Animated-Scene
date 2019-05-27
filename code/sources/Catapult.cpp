#include <Platform.hpp>
#include "..\headers\Catapult.hpp"

namespace prz
{
	Catapult::Catapult(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{
	}
	void Catapult::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}