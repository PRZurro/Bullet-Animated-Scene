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
		gltVec3 floorScale(floorShapeDimensions);
		float floorsSeparation = 15.f;

		Collision_Shapes_Loader& shapesLoader = Collision_Shapes_Loader::instance();
		PSPtr<Static_Rigid_Body> floor01 = create_static_rigid_body
		(
			"Floor_01",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(-floorsSeparation, 0.f, 0.f),
			shapesLoader.load_box_collision_shape(floorShapeDimensions.x, floorShapeDimensions.y, floorShapeDimensions.z),
			btQuaternion::getIdentity(),
			floorShapeDimensions
		);

		PSPtr<Static_Rigid_Body> floor02 = create_static_rigid_body
		(
			"Floor_02",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(0.f, 0.f, 0.f),
			shapesLoader.load_box_collision_shape(floorShapeDimensions.x, floorShapeDimensions.y, floorShapeDimensions.z),
			btQuaternion::getIdentity(),
			floorShapeDimensions
		);

		PSPtr<Static_Rigid_Body> floor03 = create_static_rigid_body
		(
			"Floor_03",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			btVector3(floorsSeparation, 0.f, 0.f),
			shapesLoader.load_box_collision_shape(floorShapeDimensions.x, floorShapeDimensions.y, floorShapeDimensions.z),
			btQuaternion::getIdentity(),
			floorShapeDimensions
		);
	}
	void Stage::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}
