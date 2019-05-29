#include <Key.hpp>

#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>
#include <Utilities.hpp>
#include <Kinematic_Rigid_Body.hpp>

namespace prz
{
	Key::Key(Scene& scene, const PString& name, const gltVec3& linearFactor, const gltVec3& startPosition, const gltVec3& finalPosition, float speed) :
		Entity(scene, name, startPosition),
		speed_(speed),
		prevPoint_(startPosition_),
		nextPoint_(finalPosition)
	{
		type_ = "Key";

		float scale = 3.f;

		keyRB_ = create_kinematic_rigid_body
		(
			"Key",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sora_keyblade.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(1.f),
			linearFactor,
			btQuaternion::getIdentity(),
			gltVec3(scale)
		);
	}
	void Key::update(float deltaTime)
	{
		Entity::update(deltaTime);

		float distanteToTarget = keyRB_->move_to(nextPoint_, speed_, deltaTime);
		
		if (distanteToTarget <= 0.05f)
		{
			gltVec3 nextPointTemp = nextPoint_;
			nextPoint_ = prevPoint_;
			prevPoint_ = nextPointTemp;
		}
	}
}