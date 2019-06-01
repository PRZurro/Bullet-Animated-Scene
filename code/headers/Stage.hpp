/**
 * @file Stage.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Class to manage and create a configured entity for the demo that saves the static objects of the scene(floors, walls...)
 * @version 0.1
 * @date 25-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_STAGE_H_
#define BULLET_ANIMATED_SCENE_STAGE_H_

#include <Entity.hpp>

namespace prz
{
	
	/**
	 * @brief Class to manage and create a configured entity for the demo that saves the static objects of the scene(floors, walls...)
	 * 
	 */
	class Stage : public Entity
	{
	public:	

		/**
		 * @brief Construct a new Stage
		 * 
		 * @param scene 
		 * @param name 
		 * @param startPosition 
		 */
		Stage(Scene& scene, const PString& name, const gltVec3& startPosition = gltVec3(0.f));
		
	public:

		/**
		 * @brief Does nothing 
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime) override;

	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_STAGE_H_