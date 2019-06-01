/**
 * @file Kinematic_Rigid_Body.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Rigid body that is not influenced by the chosen forces and capable of independent movement from any other rigid body
 * @version 0.1
 * @date 24-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_KINEMATIC_RIGID_BODY_H_
#define BULLET_ANIMATED_SCENE_KINEMATIC_RIGID_BODY_H_

#include <Static_Rigid_Body.hpp>

#include <Declarations.hpp>

namespace prz
{
	
	/**
	 * @brief Rigid body that is not influenced by the chosen forces and capable of independent movement from any other rigid body
	 * 
	 */
	class Kinematic_Rigid_Body : public Static_Rigid_Body
	{
	public:

		/**
		 * @brief Construct a new Kinematic_Rigid_Body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param collisionShape 
		 * @param linearFactor 
		 * @param initialRotation 
		 * @param scale 
		 */
		Kinematic_Rigid_Body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			const gltVec3& linearFactor,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			const gltVec3& scale = gltVec3(1.f)
		);

		/**
		 * @brief Destroy the Kinematic_Rigid_Body
		 * 
		 */
		~Kinematic_Rigid_Body()
		{}

	public:
		
		/**
		 * @brief Abstract class inherited method to update the kinematic rigid body. Deprecated
		 * 
		 * @param deltaTime 
		 */
		void auxiliar_update(float deltaTime) override {}

	public:

		/**
		 * @brief Translate the transformation matrix by a translation vector
		 * 
		 * @param translation 
		 */
		void translate(btVector3& translation);

		/**
		 * @brief Rotate the transformation matrix by a rotation quaternion
		 * 
		 * @param rotation 
		 */
		void rotate(btQuaternion& rotation);
		
		/**
		 * @brief Move to the input point with a speed and delta time
		 * 
		 * @param to 
		 * @param speed 
		 * @param deltaTime 
		 * @return float 
		 */
		virtual float move_to(const gltVec3& to, float speed, float deltaTime);

	public: 

		/**
		 * @brief Overrided method from parent class due to some extra logic needed to synchronize the Bullet OpenGL Matrix and OpenGL toolkit matrix
		 * 
		 */
		void sync_model_with_rigid_body() override;
	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_KINEMATIC_RIGID_BODY_H_
