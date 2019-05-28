#include <Projectile.hpp>

#include <Game.hpp>
#include <Dynamic_Rigid_Body.hpp>
#include <Collision_Shapes_Loader.hpp>
#include <Utilities.hpp>

namespace prz
{
	Projectile::Projectile(Scene& scene, const PString& name, const gltVec3& startPosition, float size) :
		Entity(scene, name, startPosition)
	{
		PSPtr<Dynamic_Rigid_Body> projectile = create_dynamic_rigid_body
		(
			"Projectile_Rigid_Body",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sphere.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(size),
			1.f,
			btQuaternion::getIdentity(),
			bt_vec3_from(gltVec3(0.f)),
			gltVec3(size)
		);
	}
}