/**
 * @file Static_Rigid_Body.hpp
 * @author Pablo Rodriguez Zurro (przuro@gmail.com)
 * @brief Rigid body that is not affected by physics (but can affect other rigid bodies) nor collisions and can't move 
 * @version 0.1
 * @date 24-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_STATIC_RIGID_BODY_H_
#define BULLET_ANIMATED_SCENE_STATIC_RIGID_BODY_H_

#include <Rigid_Body.hpp>

#include <Declarations.hpp>

namespace prz
{

	/**
	 * @brief Rigid body that is not affected by physics (but can affect other rigid bodies) nor collisions and can't move 
	 */
	class Static_Rigid_Body : public Rigid_Body
	{
	public:

		/**
		 * @brief Construct a new Static_Rigid_Body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param collisionShape 
		 * @param initialRotation 
		 * @param scale 
		 */
		Static_Rigid_Body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

		/**
		 * @brief Destroy the Static_Rigid_Body
		 * 
		 */
		~Static_Rigid_Body(){}

	public:

		/**
		 * @brief Not used
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime) override {}

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_STATIC_RIGID_BODY_H_