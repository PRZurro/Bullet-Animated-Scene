/**
 * @file Game_Manager_Demo_Scene_01.hpp
 * @author Pablo Rodriguez Zurro (przuro@gmail.com)
 * @brief Logic manager of the example scene
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
	/**
	 * @brief Logic manager of the example scene
	 * 
	 */
	class Game_Manager_Demo_Scene_01 : public Game_Manager
	{
	public:

		/**
		 * @brief Construct a new Game_Manager_Demo_Scene_01
		 * 
		 * @param scene 
		 */
		Game_Manager_Demo_Scene_01(Scene& scene);

	public:

		/**
		 * @brief Method provided by the abstract class parent. 
		 * 
		 * @param deltaTime 
		 * @param collisionListener 
		 */
		void manage_game(float deltaTime, PSPtr<Collision_Listener> collisionListener) override;

	private:

		float timerProjectileSpawner_;
		bool canSpawnProjecitile_;
		bool doorsOpened_;
	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_GAME_MANAGER_DEMO_SCENE_01_H_
