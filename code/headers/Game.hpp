/**
 * @file Game.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Core class that encapsulates the workings of a game in a SFML application.
 * @version 0.1
 * @date 09-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_GAME_H_
#define BULLET_ANIMATED_SCENE_GAME_H_

#include <Declarations.hpp>

#include <SFML/Window.hpp>

using namespace sf;

namespace prz
{

	class Input_Manager;
	class Scene;
	
	/**
	 * @brief Core class that encapsulates the workings of a game in a SFML application.
	 * 
	 */
	class Game
	{
	public:

		/**
		 * @brief Construct a new Game
		 * 
		 * @param windowWidth 
		 * @param windowHeight 
		 * @param windowTitle 
		 * @param vSync 
		 * @param windowStyle 
		 * @param depth 
		 */
		Game
		(
			unsigned int windowWidth, 
			unsigned int windowHeight,
			const PString& windowTitle = "PRZuro Bullet Animated Scene",
			bool vSync = true, const 
			WindowStyle& windowStyle = DEFAULT,
			unsigned int depth = 32
		);

		/**
		 * @brief Destroy the Game
		 * 
		 */
		~Game()
		{}

	public:

		/**
		 * @brief Run the game
		 * 
		 */
		void run();
		
		/**
		 * @brief Stop the game
		 * 
		 */
		void stop()
		{
			isRunning_ = false;
		}

	public:

		/**
		 * @brief Return if the game is running
		 * 
		 * @return true 
		 * @return false 
		 */
		bool isRunning()
		{
			return isRunning_;
		}

	public:

		/**
		 * @brief Return the assets folder path
		 * 
		 * @return const PString& 
		 */
		static const PString& assetsFolderPath()
		{
			return assetsFolderPath_;
		}

	private:

		/**
		 * @brief Store and handle some events
		 * 
		 * @param inputManager 
		 */
		void poll_events(Input_Manager& inputManager);
		
		/**
		 * @brief Calculate the time between frames
		 * 
		 */
		void calculate_delta_time() 
		{
			curTime = HighClock::now();

			deltaTime_ = static_cast<float>(ElapsedTime(curTime - prevTime).count());

			prevTime = curTime;
		}

	private:

		Window window_;
		PSPtr<Scene> scene_;

	private:

		Event event_;
		
	private:

		float deltaTime_;
		PTimePoint curTime;
		PTimePoint prevTime;

	private:

		bool isRunning_;

	private:

		static PString assetsFolderPath_;
	};

} // !namespace prz 

#endif // !BULLET_ANIMATED_SCENE_GAME_H_
