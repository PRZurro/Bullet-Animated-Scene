#include <Catapult.hpp>

#include <Dynamic_Rigid_Body.hpp>
#include <Game.hpp>
#include <Collision_Shapes_Loader.hpp>
#include <Utilities.hpp>
#include <Projectile.hpp>
#include <Scene.hpp>

namespace prz
{

	unsigned int Catapult::projectilesCreated_ = 0;

	Catapult::Catapult(Scene& scene, const PString& name, const gltVec3& startPosition) :
		Entity(scene, name, startPosition)
	{
		type_ = "Catapult";

		// Setup the chasis

		gltVec3 chasisDimensions(1.5f, 0.5f, 1.2f);

		float halfChasisX = chasisDimensions.x / 2.f;
		float halfChasisY = chasisDimensions.y / 2.f;
		float halfChasisZ = chasisDimensions.z / 2.f;

		PSPtr<Dynamic_Rigid_Body> chasis = create_dynamic_rigid_body
		(
			"Chasis",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			bt_vec3_from(gltVec3(0.f)),
			Collision_Shapes_Loader::instance().load_box_collision_shape(chasisDimensions),
			10.f,
			btQuaternion::getIdentity(),
			bt_vec3_from(gltVec3(0.f)),
			chasisDimensions
		);

		// Setup the wheels

		float wheelRadius = 0.45f;
		float wheelHalfRadius = wheelRadius / 2;

		float wheelPosOffsetX = wheelRadius + halfChasisX + 0.5f;
		float wheelPosOffsetY = wheelRadius + halfChasisY + 0.05f;
		float wheelPosOffsetZ = wheelRadius + halfChasisZ;
		float wheelMass = 1.f;
		float wheelFriction = 0.8f;
		float wheelRestitution = 0.3f;

		btQuaternion wheelSphereStartRotation(0.f, 0.f, 0.f);
	
		PSPtr<Dynamic_Rigid_Body> frontWheelL = create_dynamic_rigid_body
		(
			"Front_Wheel_Left",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sphere.obj"),
			btVector3(-wheelPosOffsetX, -wheelPosOffsetY, wheelPosOffsetZ),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(wheelRadius),
			wheelMass,
			wheelSphereStartRotation,
			bt_vec3_from(gltVec3(0.f)),
			gltVec3(wheelRadius)
		);

		PSPtr<Dynamic_Rigid_Body> frontWheelR = create_dynamic_rigid_body
		(
			"Front_Wheel_Right",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sphere.obj"),
			btVector3(-wheelPosOffsetX, -wheelPosOffsetY, -wheelPosOffsetZ),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(wheelRadius),
			wheelMass,
			wheelSphereStartRotation,
			bt_vec3_from(gltVec3(0.f)),
			gltVec3(wheelRadius)
		);

		PSPtr<Dynamic_Rigid_Body> backWheelL = create_dynamic_rigid_body
		(
			"Back_Wheel_Left",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sphere.obj"),
			btVector3(wheelPosOffsetX, -wheelPosOffsetY, wheelPosOffsetZ),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(wheelRadius),
			wheelMass,
			wheelSphereStartRotation,
			bt_vec3_from(gltVec3(0.f)),
			gltVec3(wheelRadius)
		);

		PSPtr<Dynamic_Rigid_Body> backWheelR = create_dynamic_rigid_body
		(
			"Back_Wheel_Right",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/sphere.obj"),
			btVector3(wheelPosOffsetX, -wheelPosOffsetY, -wheelPosOffsetZ),
			Collision_Shapes_Loader::instance().load_sphere_collision_shape(wheelRadius),
			wheelMass,
			wheelSphereStartRotation,
			bt_vec3_from(gltVec3(0.f)),
			gltVec3(wheelRadius)
		);

		frontWheelL->rigidBody()->setFriction(wheelFriction);
		frontWheelR->rigidBody()->setFriction(wheelFriction);
		backWheelL->rigidBody()->setFriction(wheelFriction);
		backWheelR->rigidBody()->setFriction(wheelFriction);

		frontWheelL->rigidBody()->setRestitution(wheelRestitution);
		frontWheelR->rigidBody()->setRestitution(wheelRestitution);
		backWheelL->rigidBody()->setRestitution(wheelRestitution);
		backWheelR->rigidBody()->setRestitution(wheelRestitution);

		// Connect the wheels to the chasis by constraints

		frontWheelConstraintL_ = join_rigid_bodies
		(
			"Chasis",
			"Front_Wheel_Left",
			btVector3(-wheelPosOffsetX, -wheelPosOffsetY, wheelPosOffsetZ),
			bt_vec3_from(gltVec3(0.f)),
			btVector3(0.f, 0.f, 1.f),
			btVector3(0.f, 0.f, 1.f)
		);

		frontWheelConstraintR_ = join_rigid_bodies
		(
			"Chasis",
			"Front_Wheel_Right",
			btVector3(-wheelPosOffsetX, -wheelPosOffsetY, -wheelPosOffsetZ),
			bt_vec3_from(gltVec3(0.f)),
			btVector3(0.f, 0.f, 1.f),
			btVector3(0.f, 0.f, 1.f)
		);

		backWheelConstraintL_ = join_rigid_bodies
		(
			"Chasis",
			"Back_Wheel_Left",
			btVector3(wheelPosOffsetX, -wheelPosOffsetY, wheelPosOffsetZ),
			bt_vec3_from(gltVec3(0.f)),
			btVector3(0.f, 0.f, 1.f),
			btVector3(0.f, 0.f, 1.f)
		);

		backWheelConstraintR_ = join_rigid_bodies
		(
			"Chasis",
			"Back_Wheel_Right",
			btVector3(wheelPosOffsetX, -wheelPosOffsetY, -wheelPosOffsetZ),
			bt_vec3_from(gltVec3(0.f)),
			btVector3(0.f, 0.f, 1.f),
			btVector3(0.f, 0.f, 1.f)
		);

		// Setup the catapult's arm

		gltVec3 armDimensions(1.8f, 0.2f, 0.4f);

		PSPtr<Dynamic_Rigid_Body> arm = create_dynamic_rigid_body
		(
			"Arm",
			make_shared<gltModelObj>(Game::assetsFolderPath() + "models/obj/cube.obj"),
			bt_vec3_from(gltVec3(0.f, chasisDimensions.y, -halfChasisZ)),
			Collision_Shapes_Loader::instance().load_box_collision_shape(armDimensions),
			1.f,
			btQuaternion::getIdentity(),
			bt_vec3_from(gltVec3(0.f)),
			armDimensions
		);

		armConstraint_ = join_rigid_bodies
		(
			"Chasis",
			"Arm",
			btVector3(- (halfChasisX / 2 + 0.5f), halfChasisY + 0.5f, 0.f),
			btVector3(-armDimensions.x / 2, -armDimensions.y / 2, -armDimensions.z / 2),
			btVector3(0.f, 0.f, -1.f),
			btVector3(0, 0.f, -1.f)
		);

		// Configure the constraints settings  

		frontWheelConstraintL_->setMaxMotorImpulse(50.f);
		frontWheelConstraintR_->setMaxMotorImpulse(50.f);
		backWheelConstraintL_->setMaxMotorImpulse(50.f);
		backWheelConstraintR_->setMaxMotorImpulse(50.f);

		frontWheelConstraintL_->enableMotor(true);
		frontWheelConstraintR_->enableMotor(true);
		backWheelConstraintL_->enableMotor(true);
		backWheelConstraintR_->enableMotor(true);

		armConstraint_->setMaxMotorImpulse(1000.f);
		armConstraint_->enableMotor(true);
		armConstraint_->setLimit(0.f, 90.f);

	}

	void Catapult::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}

	void Catapult::move_forward(float speed)
	{
		speed = -speed;
		backWheelConstraintL_->setMotorTargetVelocity(speed / 10);
		backWheelConstraintR_->setMotorTargetVelocity(speed / 10);
		frontWheelConstraintL_->setMotorTargetVelocity(speed);
		frontWheelConstraintR_->setMotorTargetVelocity(speed);
	}

	void Catapult::move_back(float speed)
	{
		move_forward(-speed);
	}

	void Catapult::turn_right(float speed)
	{
		frontWheelConstraintL_->setMotorTargetVelocity(speed);
		backWheelConstraintL_->setMotorTargetVelocity(speed);

		frontWheelConstraintR_->setMotorTargetVelocity(-speed);
		backWheelConstraintR_->setMotorTargetVelocity(-speed);
	}

	void Catapult::turn_left(float speed)
	{
		frontWheelConstraintR_->setMotorTargetVelocity(speed);
		backWheelConstraintR_->setMotorTargetVelocity(speed);

		frontWheelConstraintL_->setMotorTargetVelocity(-speed);
		backWheelConstraintL_->setMotorTargetVelocity(-speed);
	}

	void Catapult::use_arm(float speed)
	{
		armConstraint_->setMotorTargetVelocity(speed);
	}

	void Catapult::spawn_new_projectile()
	{
		sceneParent_.add_entity
		(
			make_shared<Projectile>
			(
				sceneParent_, 
				"Projectile" + projectilesCreated_++,
				glt_vec3_from(dynamicRigidBodies_["Chasis"]->rigidBody()->getWorldTransform().getOrigin() + btVector3(0.f, 5.f, 0.f)), 
				0.4f
			)
		);
	}

	void Catapult::disable_movement()
	{
		frontWheelConstraintL_->setMotorTargetVelocity(0.f);
		frontWheelConstraintR_->setMotorTargetVelocity(0.f);
		backWheelConstraintL_->setMotorTargetVelocity(0.f);
		backWheelConstraintR_->setMotorTargetVelocity(0.f);
		armConstraint_->setMotorTargetVelocity(-2.f); // Setting to -2.f will automatically lower the arm. 
	}
}