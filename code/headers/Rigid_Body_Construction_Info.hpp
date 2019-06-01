/**
 * @file Rigid_Body_Construction_Info.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Class to store the construction information of a rigid body
 * @version 0.1
 * @date 25-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_RIGID_BODY_CONSTRUCTION_INFO_H_
#define BULLET_ANIMATED_SCENE_RIGID_BODY_CONSTRUCTION_INFO_H_

#include <Declarations.hpp>

namespace prz
{

	/**
	 * @brief Class to store the construction information of a rigid body
	 * 
	 */
	struct Rigid_Body_Construction_Info
	{
		Rigid_Body_Construction_Info
        (
            PSPtr<btCollisionShape> iCollisionShape,
            btScalar iMass,
            btVector3 iLocalInertia = btVector3(0.f, 0.f, 0.f)
        ) : 
			collisionShape(iCollisionShape),
            mass(iMass),
			localInertia(iLocalInertia),
			motionState()
        {
			collisionShape->calculateLocalInertia(mass, localInertia);
        }

		/**
		 * @brief Operator to return the bullet rigid body construction info by the stored values in this object
		 * 
		 * @return btRigidBody::btRigidBodyConstructionInfo 
		 */
		operator btRigidBody::btRigidBodyConstructionInfo()
		{

			btDefaultMotionState* motionStatess = motionState.get();

			return btRigidBody::btRigidBodyConstructionInfo
			(
				mass,
				motionState.get(),
				collisionShape.get(),
				localInertia
			);
		}

		PSPtr<btCollisionShape> collisionShape;
		PSPtr<btDefaultMotionState> motionState;
		btScalar mass;
		btVector3 localInertia;
		
	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_RIGID_BODY_CONSTRUCTION_INFO_H_
