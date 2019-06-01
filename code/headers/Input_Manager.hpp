/**
 * @file Input_Manager.hpp
 * @author Pablo Rodriguez Zurro (przuro@gmail.com)
 * @brief Save the keyboard and mouse pointer information collected from SFML	
 * @version 0.1
 * @date 23-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_INPUT_MANAGER_H_
#define BULLET_ANIMATED_SCENE_INPUT_MANAGER_H_

#include <Declarations.hpp>

#include <SFML/System.hpp>

using namespace sf;

namespace prz
{
	/**
	 * @brief Save the keyboard and mouse pointer information collected from SFML	
	 * 
	 */
	class Input_Manager
	{
	public:

		/**
		 * @brief Get an static instance object of this class
		 *
		 * @return InputManager&
		 */
		static Input_Manager& instance()
		{
			static Input_Manager instance;
			return instance;
		}

	public:

		/**
		 * @brief Update the keyboard state with the input event
		 *
		 * @param event
		 */
		void update(Event& event)
		{
			switch (event.type)
			{
			case Event::KeyPressed:

				keysPressed_[event.key.code] = true;

				break;

			case Event::KeyReleased:

				keysPressed_[event.key.code] = false;

				break;

			case Event::MouseButtonPressed:

				isMousePressed_ = true;

				break;

			case Event::MouseButtonReleased:

				isMousePressed_ = false;
				break;

			case Event::MouseMoved:

				prevMouseX_ = curMouseX_;
				prevMouseY_ = curMouseY_;

				curMouseX_ = event.mouseMove.x;
				curMouseY_ = event.mouseMove.y;

				break;
			}
		}

	public:

		/**
		 * @brief Get the state of a key
		 *
		 * @param key
		 * @return true
		 * @return false
		 */
		bool is_key_pressed(const PKey& key) const
		{
			return keysPressed_.count(key) == 1 && keysPressed_.at(key) == true;
		}

		/**
		 * @brief Return if the mouse has been pressed
		 * 
		 * @return true 
		 * @return false 
		 */
		bool is_mouse_pressed()
		{
			return isMousePressed_;
		}

	public:

		/**
		 * @brief Return the current position in x axis of the mouse pointer
		 * 
		 * @return const unsigned& curMouseX 
		 */
		const unsigned int& curMouseX()
		{
			return curMouseX_;
		}

		/**
		 * @brief Return the current position in y axis of the mouse pointer
		 * 
		 * @return const unsigned& curMouseY 
		 */
		const unsigned int& curMouseY()
		{
			return curMouseY_;
		}

		/**
		 * @brief Return the previous position in x axis of the mouse pointer
		 * 
		 * @return const unsigned& prevMouseX 
		 */
		const unsigned int& prevMouseX()
		{
			return prevMouseX_;
		}

		/**
		 * @brief Return the previous position in y axis of the mouse pointer
		 * 
		 * @return const unsigned& prevMouseY 
		 */
		const unsigned int& prevMouseY()
		{
			return prevMouseY_;
		}

	private:

		/**
		 * @brief Construct a new Input Manager object, private to avoid undesired instantiation
		 *
		 */
		Input_Manager():
			isMousePressed_(false)
		{
			curMouseX_ = prevMouseX_ = curMouseY_ = prevMouseY_ = 0;
		}

	private:

		PMap< PKey, bool> keysPressed_;

		unsigned int  curMouseX_, prevMouseX_;
		unsigned int  curMouseY_, prevMouseY_;

	private: 

		bool isMousePressed_;
	};

} // !namespace prz 

#endif // !BULLET_ANIMATED_SCENE_INPUT_MANAGER_H_
