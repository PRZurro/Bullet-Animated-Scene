/**
 * @file Projectile.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Entity with a dynamic rigid body with a spherical collision shape
 * @version 0.1
 * @date 25-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_PROJECTILE_H_
#define BULLET_ANIMATED_SCENE_PROJECTILE_H_

#include <Entity.hpp>

namespace prz
{

	/**
	 * @brief Entity with a dynamic rigid body with a spherical collision shape
	 * 
	 */
	class Projectile : public Entity
	{
	public:

		/**
		 * @brief Construct a new Projectile
		 * 
		 * @param scene 
		 * @param name 
		 * @param startPosition 
		 * @param size 
		 */
		Projectile
		(
			Scene& scene,
			const PString& name,
			const gltVec3& startPosition = gltVec3(0.f),
			float size = 1.f
		);

	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_PROJECTILE_H_