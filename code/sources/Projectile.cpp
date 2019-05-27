#include <Projectile.hpp>

#include <Game.hpp>
#include <Dynamic_Rigid_Body.hpp>
#include <Collision_Shapes_Loader.hpp>

namespace prz
{
	Projectile::Projectile(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{
		PSPtr<Dynamic_Rigid_Body> projectile = create_dynamic_rigid_body
		(
			"Projectile_Rigid_Body",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sphere.obj"),
			btVector3(0.f, 0.f, 0.f),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(1.f),
			1.f
		);
	}
	void Projectile::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}