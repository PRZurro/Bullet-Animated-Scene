/**
 * @file Game_Manager.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Abstract class to manage the logic of the game application
 * @version 0.1
 * @date 24-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_GAME_MANAGER_H_
#define BULLET_ANIMATED_SCENE_GAME_MANAGER_H_

#include <Declarations.hpp>

namespace prz
{

	class Scene;
	class Collision_Listener;

	/**
	 * @brief Abstract class to manage the logic of the game application
	 * 
	 */
	class Game_Manager
	{
	public:

		/**
		 * @brief Construct a new Game_Manager
		 * 
		 * @param scene 
		 */
		Game_Manager(Scene & scene);

		/**
		 * @brief Destroy the Game_Manager
		 * 
		 */
		~Game_Manager(){}

	public:

		/**
		 * @brief Manage the scene logic
		 * 
		 * @param deltaTime 
		 * @param collisionListeners 
		 */
		virtual void manage_game(float deltaTime, PSPtr<Collision_Listener> collisionListeners) = 0;

	public:

		Scene& scene() { return scene_; }

	protected:

		Scene& scene_;

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_GAME_MANAGER_H_
