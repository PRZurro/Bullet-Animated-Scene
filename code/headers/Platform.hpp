/**
 * @file Platform.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 25-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_PLATFORM_H_
#define BULLET_ANIMATED_SCENE_PLATFORM_H_

#include <Entity.hpp>

namespace prz
{

	class Platform : public Entity
	{
	public:

		Platform
		(
			Scene& scene,
			const PString& name,
			const gltVec3& startPosition = gltVec3(0.f),
			const gltVec3& finalPosition = gltVec3(0.f)
		);

	public:

		void update(float deltaTime) override;

	public:

		void set_speed(float speed)
		{
			speed_ = speed;
		}

	private:

		gltVec3 finalPosition_;
		gltVec3 currentPosition_;
		float speed_;

	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_PLATFORM_H_