#include <Game_Manager_Demo_Scene_01.hpp>

#include <Catapult.hpp>
#include <Scene.hpp>
#include <Input_Manager.hpp>
#include <Door.hpp>
#include <Platform.hpp>
#include <Collision_Listener.hpp>
#include <Rigid_Body.hpp>

namespace prz
{

	Game_Manager_Demo_Scene_01::Game_Manager_Demo_Scene_01(Scene& scene) :
		Game_Manager(scene),
		timerProjectileSpawner_(0.f),
		canSpawnProjecitile_(true), 
		doorsOpened_(false)
	{}

	void Game_Manager_Demo_Scene_01::manage_game(float deltaTime, PSPtr<Collision_Listener> collisionListener)
	{

		timerProjectileSpawner_ += deltaTime;

		if (timerProjectileSpawner_ >= 1.f)
		{
			canSpawnProjecitile_ = true;
		}

		Input_Manager& inputManager = Input_Manager::instance();
		Catapult* catapult = (Catapult*)scene_.get_entity("Catapult").get();
		static float wheelSpeed = 350.f;

		// Check collisions and handle them

		if (collisionListener->has_bodies_collided("Catapult", "Platform"))
		{
			Platform* platform = (Platform*)scene_.get_entity("Platform").get();

			platform->set_speed(1.f);
		}

		if (!doorsOpened_ && collisionListener->has_bodies_collided("Catapult", "Key"))
		{
			Door* leftDoor = (Door*)scene_.get_entity("DoorL").get();
			Door* rightDoor = (Door*)scene_.get_entity("DoorR").get();

			float doorSpeed = 4.f;

			leftDoor->set_speed(doorSpeed);
			rightDoor->set_speed(doorSpeed);

			PSPtr<Rigid_Body> key = scene_.get_entity("Key")->get_rigid_body("Key");
			key->model()->set_visible(false);
			key->rigidBody()->setCollisionFlags(key->rigidBody()->CF_NO_CONTACT_RESPONSE);

		}

		// Manage vehicle input

		if (catapult)
		{
			catapult->disable_movement();
			
			if (inputManager.is_key_pressed(PKey::W))
			{
				catapult->move_forward(wheelSpeed / 5.f);
			}
			else if (inputManager.is_key_pressed(PKey::A))
			{
				catapult->turn_right(wheelSpeed);
			}
			else if (inputManager.is_key_pressed(PKey::S))
			{
				catapult->move_back(wheelSpeed / 5.f);
			}
			else if (inputManager.is_key_pressed(PKey::D))
			{
				catapult->turn_left(wheelSpeed);
			}

			if (inputManager.is_key_pressed(PKey::Space))
			{
				catapult->use_arm(2000.f);
			}

			if(canSpawnProjecitile_)

			if (inputManager.is_key_pressed(PKey::R))
			{
				catapult->spawn_new_projectile();
				canSpawnProjecitile_ = false;
				timerProjectileSpawner_ = 0.f;
			}
		}

		// Change between cameras when CTRL + camera number keys are pressed

		if (inputManager.is_key_pressed(PKey::LControl) && inputManager.is_key_pressed(PKey::Num1))
		{
			scene_.renderer()->set_active_camera("Camera01");
		}
		else if (inputManager.is_key_pressed(PKey::LControl) && inputManager.is_key_pressed(PKey::Num2))
		{
			scene_.renderer()->set_active_camera("Camera02");
		}
		else if (inputManager.is_key_pressed(PKey::LControl) && inputManager.is_key_pressed(PKey::Num3))
		{
			scene_.renderer()->set_active_camera("Camera03");
		}
	}
}