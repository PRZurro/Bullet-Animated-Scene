/**
 * @file Target.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 28-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_TARGET_H_
#define BULLET_ANIMATED_SCENE_TARGET_H_

#include <Entity.hpp>

namespace prz
{

    class Target : public Entity
    {
	public:

		Target
		(
			Scene& scene, 
			const PString& name, 
			const gltVec3& startPosition = gltVec3(0.f), 
			const gltVec3& dimensions = gltVec3(1.f)
		);

    };

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_TARGET_H_
