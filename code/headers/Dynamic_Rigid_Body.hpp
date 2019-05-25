/**
 * @file Dynamic_Rigid_Body.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief
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

	class Dynamic_Rigid_Body : public Rigid_Body
	{
	public:

		Dynamic_Rigid_Body
		(
			const PString& name,
			btVector3& origin,
			btQuaternion& initialRotation,
			PSPtr<btCollisionShape> collisionShape,
			btScalar mass,
			btVector3 localInertia = btVector3(0, 0, 0),
			float scale = 1.f
		);

		~Dynamic_Rigid_Body();

	public:

		void auxiliar_update(float deltaTime) override {}

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_DYNAMIC_RIGID_BODY_H_