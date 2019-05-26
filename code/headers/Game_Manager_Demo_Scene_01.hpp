/**
 * @file Game_Manager_Demo_Scene_01.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 24-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_GAME_MANAGER_DEMO_SCENE_01_H_
#define BULLET_ANIMATED_SCENE_GAME_MANAGER_DEMO_SCENE_01_H_

#include <Game_Manager.hpp>

namespace prz
{

	class Game_Manager_Demo_Scene_01 : public Game_Manager
	{
	public:

		Game_Manager_Demo_Scene_01(Scene& scene);

	public:

		void manage_game(float deltaTime, PSPtr<Collision_Listener> collisionListeners) override;

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_GAME_MANAGER_DEMO_SCENE_01_H_
