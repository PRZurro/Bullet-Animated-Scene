#include <Door.hpp>

#include <Kinematic_Rigid_Body.hpp>
#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>

namespace prz
{
	Door::Door(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{

		Collision_Shapes_Loader& shapesLoader = Collision_Shapes_Loader::instance();
		
		PSPtr<Kinematic_Rigid_Body> door = create_kinematic_rigid_body
		(
			"Door",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0, 0, 0),
			shapesLoader.load_box_collision_shape(1.f, 10.f, 4.f),
			btQuaternion::getIdentity(),
			gltVec3(0.5f, 5.f, 2.f)
		);

	}
	void Door::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}
