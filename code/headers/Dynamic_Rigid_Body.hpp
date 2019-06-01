/**
 * @file Dynamic_Rigid_Body.hpp
 * @author Pablo Rodriguez Zurro (przuro@gmail.com)
 * @brief Rigid body that is influenced by all forces of the dynamics world (gravity, collisions, etc..)
 * @version 0.1
 * @date 24-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_DYNAMIC_RIGID_BODY_H_
#define BULLET_ANIMATED_SCENE_DYNAMIC_RIGID_BODY_H_

#include <Rigid_Body.hpp>

#include <Declarations.hpp>

namespace prz
{

	/**
	 * @brief Rigid body that is influenced by all forces of the dynamics world (gravity, collisions, etc..)
	 * 
	 */
	class Dynamic_Rigid_Body : public Rigid_Body
	{
	public:

		/**
		 * @brief Construct a new Dynamic_Rigid_Body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param collisionShape 
		 * @param mass 
		 * @param initialRotation 
		 * @param localInertia 
		 * @param scale 
		 */
		Dynamic_Rigid_Body
		(
			const PString& name,
			PSPtr<gltModel> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btScalar mass,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			btVector3 localInertia = btVector3(0.f, 0.f, 0.f),
			const gltVec3& scale = gltVec3(1.f)
		);

		/**
		 * @brief Destroy the Dynamic_Rigid_Body
		 * 
		 */
		~Dynamic_Rigid_Body();

	public:

		/**
		 * @brief Optional update provided by the abstract base class 
		 * 
		 * @param deltaTime 
		 */
		void auxiliar_update(float deltaTime) override {}

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_DYNAMIC_RIGID_BODY_H_
