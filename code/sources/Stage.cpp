#include <Stage.hpp>

#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>

namespace prz
{
	Stage::Stage(Scene& scene, const PString& name) :
		Entity(scene, name)
	{
		create_static_rigid_body
		(
			"Floor_01",
			make_shared<Model_Obj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0,0,0),
			Collision_Shapes_Loader::instance().load_box_collision_shape(0.5f, 0.5f, 0.5f)
		);

		create_static_rigid_body
		(
			"Floor_02",
			make_shared<Model_Obj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0, 0, 0),
			Collision_Shapes_Loader::instance().load_box_collision_shape(0.5f, 0.5f, 0.5f)
		);

		create_static_rigid_body
		(
			"Floor_03",
			make_shared<Model_Obj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0, 0, 0),
			Collision_Shapes_Loader::instance().load_box_collision_shape(0.5f, 0.5f, 0.5f)
		);

	}
	void Stage::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}
