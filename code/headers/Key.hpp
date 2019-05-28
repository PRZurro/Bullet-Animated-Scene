/**
 * @file Key.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 25-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_KEY_H_
#define BULLET_ANIMATED_SCENE_KEY_H_

#include <Entity.hpp>

namespace prz
{

	class Key : public Entity
	{
	public:

		Key(Scene& scene, const PString& name, const gltVec3& startPosition = gltVec3(0.f));

	public:

		void update(float deltaTime) override;

	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_KEY_H_