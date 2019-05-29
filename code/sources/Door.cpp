#include <Door.hpp>

#include <Kinematic_Rigid_Body.hpp>
#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>
#include <Utilities.hpp>

namespace prz
{
	Door::Door(Scene& scene, const PString& name, const gltVec3& linearFactor, const gltVec3& startPosition, const gltVec3& finalPosition) :
		Entity(scene, name, startPosition),
		finalPosition_(finalPosition),
		speed_(0.f)
	{	
		gltVec3 doorDimensions = gltVec3(0.25, 50.f, 2.f);

		PSPtr<Kinematic_Rigid_Body> door = create_kinematic_rigid_body
		(
			"Door",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_box_collision_shape(doorDimensions),
			linearFactor,
			btQuaternion::getIdentity(),
			doorDimensions
		);

		type_ = "Door";
	}
	void Door::update(float deltaTime)
	{
		Entity::update(deltaTime);

		if (speed_ != 0.f)
		{
			float distanteToTarget = kinematicRigidBodies_["Door"]->move_to(finalPosition_, speed_, deltaTime);

			if (distanteToTarget <= 0.05f)
			{
				speed_ = 0.f;
			}
		}
	}
}
