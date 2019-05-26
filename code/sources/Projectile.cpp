#include <Projectile.hpp>

namespace prz
{
	Projectile::Projectile(Scene& scene, const PString& name):
		Entity(scene, name)
	{}
	void Projectile::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}