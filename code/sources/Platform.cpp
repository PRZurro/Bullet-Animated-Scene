#include <Platform.hpp>

#include <Kinematic_Rigid_Body.hpp>
#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>

namespace prz
{
	Platform::Platform(Scene& scene, const PString& name, const gltVec3& linearFactor, const gltVec3& startPosition, const gltVec3& finalPosition) :
		Entity(scene, name, startPosition),
		finalPosition_(finalPosition),
		speed_(0.f)
	{
		gltVec3 platformDimensions(1.5f, 0.7f, 3.f);

		PSPtr<Kinematic_Rigid_Body> door = create_kinematic_rigid_body
		(
			"Platform",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0, 0, 0),
			Collision_Shapes_Loader::instance().load_box_collision_shape(platformDimensions),
			linearFactor,
			btQuaternion::getIdentity(),
			platformDimensions
		);

		type_ = "Platform";
	}
	void Platform::update(float deltaTime)
	{
		Entity::update(deltaTime);

		if (speed_ != 0.f)
		{
			float distanteToTarget = kinematicRigidBodies_["Platform"]->move_to(finalPosition_, speed_, deltaTime);

			if (distanteToTarget <= 0.05f)
			{
				speed_ = 0.f;
			}
		}
	}
}