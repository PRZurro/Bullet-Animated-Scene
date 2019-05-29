#include <Game_Manager_Demo_Scene_01.hpp>

#include <Scene.hpp>
#include <Input_Manager.hpp>
#include <Door.hpp>
#include <Platform.hpp>

namespace prz
{

	Game_Manager_Demo_Scene_01::Game_Manager_Demo_Scene_01(Scene& scene) :
		Game_Manager(scene)
	{
	}

	void Game_Manager_Demo_Scene_01::manage_game(float deltaTime, PSPtr<Collision_Listener> collisionListeners)
	{
		Input_Manager& inputManager = Input_Manager::instance();

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

		if (inputManager.is_key_pressed(PKey::O))
		{
			Door* leftDoor = (Door*)scene_.get_entity("DoorL").get();
			Door* rightDoor = (Door*)scene_.get_entity("DoorR").get();

			float doorSpeed = 4.f;

			leftDoor->set_speed(doorSpeed);
			rightDoor->set_speed(doorSpeed);
		}

		if (inputManager.is_key_pressed(PKey::E))
		{
			Platform* platform = (Platform*)scene_.get_entity("Platform").get();

			platform->set_speed(4.f);
		}

	}
}