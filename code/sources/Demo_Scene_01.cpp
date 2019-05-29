#include <Demo_Scene_01.hpp>

#include <Game_Manager_Demo_Scene_01.hpp>
#include <Key.hpp>
#include <Catapult.hpp>
#include <Platform.hpp>
#include <Stage.hpp>
#include <Door.hpp>
#include <Target.hpp>
#include <Projectile.hpp>
#include <Utilities.hpp>

namespace prz
{
	Demo_Scene_01::Demo_Scene_01(Window& window) :
		Scene(window)
	{}

	void Demo_Scene_01::initialize()
	{
		// Add the camera and the lights to the scene

		cameras_["Camera01"] = make_shared<gltCamera>(20.f, 1.f, 100.f, window_.getSize().x / window_.getSize().y);
		cameras_["Camera02"] = make_shared<gltCamera>(20.f, 1.f, 100.f, window_.getSize().x / window_.getSize().y);
		cameras_["Camera03"] = make_shared<gltCamera>(20.f, 1.f, 100.f, window_.getSize().x / window_.getSize().y);
		lights_["Light01"] = make_shared<Light>();
		lights_["Light02"] = make_shared<Light>();

		add_camera_and_lights_to_renderer();

		renderer_->set_active_camera("Camera01");

		cameras_["Camera01"]->translate(gltVec3(0.f, 17.f, 37.f));
		cameras_["Camera02"]->translate(gltVec3(0.f, 60.f, -20.f));
		cameras_["Camera02"]->rotate_around_x(degrees_to_radians(-90.f));
		cameras_["Camera03"]->translate(gltVec3(35.f, 10.f, 1.f));
		cameras_["Camera03"]->rotate_around_z(degrees_to_radians(20.f));
		cameras_["Camera03"]->rotate_around_y(degrees_to_radians(90.f));

		lights_["Light01"]->translate(gltVec3(0.f, 8.f, 0.f));
		lights_["Light01"]->set_intensity(0.75f);
		lights_["Light01"]->set_color(gltVec3(0.8f, 1.f, 0.3f));

		lights_["Light02"]->translate(gltVec3(0.f, 10.f, 1.f));
		lights_["Light02"]->set_intensity(1.5f);
		lights_["Light02"]->set_color(gltVec3(1.f, 1.f, 1.f));

		// Set the game manager

		gameManager_ = make_shared<Game_Manager_Demo_Scene_01>(*this);

		// Add the entities

		PSPtr<Entity> stage = add_entity(PSPtr<Stage>(make_shared<Stage>(*this, "Stage")));

		PSPtr<Entity> leftDoor = add_entity(PSPtr<Door>(make_shared<Door>
		(
			*this,
			"DoorL",
			gltVec3(0.f, 0.f, 1.f), // Linear factor
			gltVec3(-2.f, 5.f, 2.f),
			gltVec3(-2.f, 5.f, 6.f)
		)));

		PSPtr<Entity> rightDoor = add_entity(PSPtr<Door>(make_shared<Door>
		(
			*this,
			"DoorR",
			gltVec3(0.f, 0.f, 1.f), // Linear factor
			gltVec3(-2.f, 5.f, -2.f),
			gltVec3(-2.f, 5.f, -6.f)
		)));

		PSPtr<Entity> platform = add_entity(PSPtr<Platform>(make_shared<Platform>
		(
			*this,
			"Platform",
			gltVec3(1.f, 0.f, 1.f), // Linear factor
			gltVec3(9.f, 0.f, 3.5f),
			gltVec3(5.f, 0.0f, -2.5f)
		)));

		PSPtr<Entity> projectileTest = add_entity(PSPtr<Projectile>(make_shared<Projectile>(*this, "Projectile", gltVec3(9.f, 3.f, 3.5f))));

		PSPtr<Entity> target = add_entity(PSPtr<Target>(make_shared<Target>
		(
			*this,
			"Target",
			gltVec3(-15.5f, 10.f, 0.f),
			gltVec3(0.25f, 10.f, 4.f)
		)));

		//PSPtr<Entity> catapult = add_entity(PSPtr<Catapult>(make_shared<Catapult>
		//	(
		//		*this,
		//		"Catapult",
		//		gltVec3(15.f, 6.5f, 0.f)
		//		)));

		//PSPtr<Entity> key = add_entity(PSPtr<Key>(make_shared<Key>(*this, "Key")));
	}
}