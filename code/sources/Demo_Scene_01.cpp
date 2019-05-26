#include <Demo_Scene_01.hpp>

#include <Game_Manager_Demo_Scene_01.hpp>
#include <Key.hpp>
#include <Catapult.hpp>
#include <Platform.hpp>
#include <Stage.hpp>
#include <Door.hpp>

namespace prz
{
	Demo_Scene_01::Demo_Scene_01(Window& window) :
		Scene(window)
	{}

	void Demo_Scene_01::initialize()
	{
		// Add the camera and the lights to the scene

		cameras_["Camera01"] = make_shared<gltCamera>(20.f, 1.f, 50.f, 1.f);
		lights_["Light01"] = make_shared<Light>();

		add_camera_and_lights_to_renderer();

		renderer_->set_active_camera("Camera01");

		cameras_["Camera01"]->translate(gltVec3(10.f, 10.f, 10.f));
		lights_["Light01"]->translate(gltVec3(0.f, 0.f, 5.f));
	
		// Set the game manager

		gameManager_ = make_shared<Game_Manager_Demo_Scene_01>(*this);

		// Add the entities

		PSPtr<Entity> stage = add_entity(PSPtr<Stage>(make_shared<Stage>(*this, "Stage")));
		/*PSPtr<Entity> catapult = add_entity(PSPtr<Catapult>(make_shared<Catapult>(*this, "Catapult")));
		PSPtr<Entity> platform = add_entity(PSPtr<Platform>(make_shared<Platform>(*this, "Platform")));
		PSPtr<Entity> door = add_entity(PSPtr<Door>(make_shared<Door>(*this, "Door")));
		PSPtr<Entity> key = add_entity(PSPtr<Key>(make_shared<Key>(*this, "Key")));
*/
		//////


	}
}