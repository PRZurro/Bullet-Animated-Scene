/**
 * @file Game.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
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

	class Game
	{
	public:

		Game
		(
			unsigned int windowWidth, 
			unsigned int windowHeight,
			const PString& windowTitle = "PRZuro Bullet Animated Scene",
			bool vSync = true, const 
			WindowStyle& windowStyle = DEFAULT,
			unsigned int depth = 32
		);

		~Game()
		{}

	public:

		void run();
		
		void stop()
		{
			isRunning_ = false;
		}

	public:

		bool isRunning()
		{
			return isRunning_;
		}

	public:

		static const PString& assetsFolderPath()
		{
			return assetsFolderPath_;
		}

	private:

		void poll_events(Input_Manager& inputManager);
		
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
