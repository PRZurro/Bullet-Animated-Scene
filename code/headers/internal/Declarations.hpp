/**
 * @file Declarations.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Class that defines custom names and typedefs of different libraries and include some interesting library headers to avoid repetition.
 * @version 0.1
 * @date 23-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_DECLARATIONS_H_
#define BULLET_ANIMATED_SCENE_DECLARATIONS_H_

#include <Declarations_STD.hpp>
#include <Declarations_SFML.hpp>
#include <Declarations_OpenGL_Toolkit.hpp>
#include <Declarations_Bullet.hpp>

namespace prz
{

	struct Rigid_Body_Construction_Info;

	using RB_Construct_Info = Rigid_Body_Construction_Info;

	const float mouseSensitivityX = 0.2f;
	const float mouseSensitivityY = 0.2f;

	////////////////////////////////////MATH/////////////////////////////////////

	constexpr float PI			= 3.14159f;
	constexpr float DELTA_TIME	= 0.01667f;          // ~60 fps
	
	constexpr float DEG_TO_RAD	= 0.01745f;
	constexpr float RAD_TO_DEG	= 57.29578f;
} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_DECLARATIONS_H_
