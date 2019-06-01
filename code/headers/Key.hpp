/**
 * @file Key.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Class to manage and create a configured entity for the demo that represents a key. 
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

	/**
	 * @brief Entity to manage and create a configured key for the demo. 
	 * 
	 */
	class Key : public Entity
	{
	public:

		/**
		 * @brief Construct a new Key
		 * 
		 * @param scene 
		 * @param name 
		 * @param linearFactor 
		 * @param startPosition 
		 * @param finalPosition 
		 * @param speed 
		 */
		Key
		(
			Scene& scene,
			const PString& name,
			const gltVec3& linearFactor,
			const gltVec3& startPosition = gltVec3(0.f),
			const gltVec3& finalPosition = gltVec3(0.f),
			float speed = 1.f
		);

	public:

		/**
		 * @brief Update the key
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime) override;

	private:

		PSPtr<Kinematic_Rigid_Body> keyRB_;
		float speed_;
		gltVec3 prevPoint_;
		gltVec3 nextPoint_;
	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_KEY_H_