/**
 * @file Platform.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Entity class with a kinematic rigid body that represents a moving platform
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

	/**
	 * @brief Entity class with a kinematic rigid body that represents a moving platform
	 * 
	 */
	class Platform : public Entity
	{
	public:

		/**
		 * @brief Construct a new Platform
		 * 
		 * @param scene 
		 * @param name 
		 * @param linearFactor 
		 * @param startPosition 
		 * @param finalPosition 
		 */
		Platform
		(
			Scene& scene,
			const PString& name,
			const gltVec3& linearFactor,
			const gltVec3& startPosition = gltVec3(0.f),
			const gltVec3& finalPosition = gltVec3(0.f)
		);

	public:

		/**
		 * @brief Update the platform entity
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime) override;

	public:

		/**
		 * @brief Set the speed
		 * 
		 * @param speed 
		 */
		void set_speed(float speed)
		{
			speed_ = speed;
		}

	private:

		gltVec3 finalPosition_;
		float speed_;

	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_PLATFORM_H_