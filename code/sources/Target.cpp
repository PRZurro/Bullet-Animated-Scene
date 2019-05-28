#include <Target.hpp>

#include <Game.hpp>
#include <Dynamic_Rigid_Body.hpp>
#include <Collision_Shapes_Loader.hpp>
#include <Utilities.hpp>

namespace prz
{
	Target::Target(Scene& scene, const PString& name, const gltVec3& startPosition, const gltVec3& dimensions) :
		Entity(scene, name, startPosition)
	{
		PSPtr<Dynamic_Rigid_Body> target = create_dynamic_rigid_body
		(
			"Target_Rigid_Body",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_box_collision_shape(dimensions),
			1.f,
			btQuaternion::getIdentity(),
			bt_vec3_from(gltVec3(0.f)),
			dimensions
		);
	}
}