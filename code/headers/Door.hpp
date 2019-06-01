/**
 * @file Door.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Entity with a kinematic rigid body representing a part of a sliding door
 * @version 0.1
 * @date 25-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_Door_H_
#define BULLET_ANIMATED_SCENE_Door_H_

#include <Entity.hpp>

namespace prz
{
	
	/**
	 * @brief Entity with a kinematic rigid body representing a part of a sliding door
	 * 
	 */
	class Door : public Entity
	{
	public:
		
		/**
		 * @brief Construct a new Door
		 * 
		 * @param scene 
		 * @param name 
		 * @param linearFactor 
		 * @param startPosition 
		 * @param finalPosition 
		 */
		Door
		(
			Scene& scene,
			const PString& name,
			const gltVec3& linearFactor,
			const gltVec3& startPosition = gltVec3(0.f),
			const gltVec3& finalPosition = gltVec3(0.f)
		);

	public:

		/**
		 * @brief Update the door entity
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

#endif // !BULLET_ANIMATED_SCENE_Door_H_