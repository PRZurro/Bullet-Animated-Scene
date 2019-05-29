#include <Catapult.hpp>

#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>
#include <Utilities.hpp>

namespace prz
{
	Catapult::Catapult(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{
		// Setup the chasis
		gltVec3 chasisDimensions(0.5f, 0.05f, 0.5f);

		PSPtr<Dynamic_Rigid_Body> chasis = create_dynamic_rigid_body
		(
			"Chasis",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_box_collision_shape(chasisDimensions),
			1.f,
			btQuaternion::getIdentity(),
			bt_vec3_from(gltVec3(0.f)),
			chasisDimensions
		);

		// Setup the wheels
		
		float wheelCylinderHalfHeight = 0.3f;
		float wheelCylinderRadius = 0.1f;
		btQuaternion wheelCylinderStartRotation(0.f, 90.f, 0.f);

		PSPtr<Dynamic_Rigid_Body> frontWheelL = create_dynamic_rigid_body
		(
			"Front_Wheel_Right",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cylinder.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_cylinder_collision_shape(wheelCylinderRadius, wheelCylinderHalfHeight),
			1.f,
			wheelCylinderStartRotation,
			btVector3(-(wheelCylinderHalfHeight + chasisDimensions.z / 2), 0.f, wheelCylinderHalfHeight + chasisDimensions.z / 2),
			gltVec3(wheelCylinderRadius, wheelCylinderHalfHeight, wheelCylinderHalfHeight)
		);

		PSPtr<Dynamic_Rigid_Body> frontWheelR = create_dynamic_rigid_body
		(
			"Front_Wheel_Left",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cylinder.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_cylinder_collision_shape(wheelCylinderRadius, wheelCylinderHalfHeight),
			1.f,
			wheelCylinderStartRotation,
			btVector3(-wheelCylinderHalfHeight + chasisDimensions.z / 2, 0.f, -(wheelCylinderHalfHeight + chasisDimensions.z / 2)),
			gltVec3(wheelCylinderRadius, wheelCylinderHalfHeight, wheelCylinderHalfHeight)
		);

		PSPtr<Dynamic_Rigid_Body> backWheelL = create_dynamic_rigid_body
		(
			"Back_Wheel_Left",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cylinder.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_cylinder_collision_shape(wheelCylinderRadius, wheelCylinderHalfHeight),
			1.f,
			wheelCylinderStartRotation,
			btVector3(wheelCylinderHalfHeight + chasisDimensions.z / 2, 0.f, wheelCylinderHalfHeight + chasisDimensions.z / 2),
			gltVec3(wheelCylinderRadius, wheelCylinderHalfHeight, wheelCylinderHalfHeight)
		);

		PSPtr<Dynamic_Rigid_Body> backWheelR = create_dynamic_rigid_body
		(
			"Back_Wheel_Right",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cylinder.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_cylinder_collision_shape(wheelCylinderRadius, wheelCylinderHalfHeight),
			1.f,
			wheelCylinderStartRotation,
			btVector3(wheelCylinderHalfHeight + chasisDimensions.z / 2, 0.f, -(wheelCylinderHalfHeight + chasisDimensions.z / 2)),
			gltVec3(wheelCylinderRadius, wheelCylinderHalfHeight, wheelCylinderHalfHeight)
		);

		// Setup the catapult's arm
		PSPtr<Dynamic_Rigid_Body> arm;
		PSPtr<Dynamic_Rigid_Body> armLimitL, armLimitR, armLimitT, armLimitD;


		join_rigid_bodies
		(
			"Chasis",
			"Front_Wheel_Right",
			btVector3(0.f, wheelCylinderHalfHeight, 0.f),
			btVector3(chasisDimensions.z / 2, 0.f, -chasisDimensions.x / 2),
			btVector3(0.f, 1.f, 0.f),
			btVector3(1.f, 0.f, 0.f)
		);

		type_ = "Catapult";
	}
	void Catapult::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
}