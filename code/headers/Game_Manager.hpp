/**
 * @file Game_Manager.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
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

	class Game_Manager
	{
	public:

		Game_Manager(Scene & scene);
		~Game_Manager(){}

	public:

		void update();

	public:

		Scene& scene() { return scene_; }

	private:

		Scene& scene_;

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_GAME_MANAGER_H_