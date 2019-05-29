#include <Stage.hpp>

#include <Static_Rigid_Body.hpp>
#include <Model.hpp>
#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>

namespace prz
{
	Stage::Stage(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{
		gltVec3 floorShapeDimensions(4.f, 0.7f, 6.5f);
		float floorsSeparation = 15.f;

		Collision_Shapes_Loader& shapesLoader = Collision_Shapes_Loader::instance();
		PSPtr<Static_Rigid_Body> floor01 = create_static_rigid_body
		(
			"Floor_01",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(-floorsSeparation, 0.f, 0.f),
			shapesLoader.load_box_collision_shape(floorShapeDimensions),
			btQuaternion::getIdentity(),
			floorShapeDimensions
		);

		PSPtr<Static_Rigid_Body> floor02 = create_static_rigid_body
		(
			"Floor_02",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0.f, 0.f, 0.f),
			shapesLoader.load_box_collision_shape(floorShapeDimensions),
			btQuaternion::getIdentity(),
			floorShapeDimensions
		);

		PSPtr<Static_Rigid_Body> floor03 = create_static_rigid_body
		(
			"Floor_03",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(floorsSeparation, 0.f, 0.f),
			shapesLoader.load_box_collision_shape(floorShapeDimensions),
			btQuaternion::getIdentity(),
			floorShapeDimensions
		);

		gltVec3 wallShapeDimensions(0.5f, 5.f, 1.25f);

		PSPtr<Static_Rigid_Body> wall01 = create_static_rigid_body
		(
			"Wall_01",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(-1.25f, 5.35f, 5.3f),
			shapesLoader.load_box_collision_shape(wallShapeDimensions),
			btQuaternion::getIdentity(),
			wallShapeDimensions
		);

		PSPtr<Static_Rigid_Body> wall02 = create_static_rigid_body
		(
			"Wall_02",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(-1.25f, 5.35f, -5.3),
			shapesLoader.load_box_collision_shape(wallShapeDimensions),
			btQuaternion::getIdentity(),
			wallShapeDimensions
		);

		type_ = "Stage";
	}
	void Stage::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}
