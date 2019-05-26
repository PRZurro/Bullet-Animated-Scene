#include <Platform.hpp>
#include "..\headers\Catapult.hpp"

namespace prz
{
	Catapult::Catapult(Scene& scene, const PString& name) :
		Entity(scene, name)
	{
	}
	void Catapult::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}