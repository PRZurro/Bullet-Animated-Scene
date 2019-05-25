/**
 * @file World.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 24-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <Declarations.hpp>

#ifndef BULLET_ANIMATED_SCENE_WORLD_H_
#define BULLET_ANIMATED_SCENE_WORLD_H_

namespace prz
{
    class World
    {
	public:

		World();

	public:

		PSPtr< btDiscreteDynamicsWorld> operator->()
		{
			return dynamicsWorld_;
		}

		PSPtr< btDiscreteDynamicsWorld> operator()()
		{
			return dynamicsWorld_;
		}

		PSPtr< btDiscreteDynamicsWorld> operator*()
		{
			return dynamicsWorld_;
		}

		operator btDiscreteDynamicsWorld*()
		{
			return dynamicsWorld_.get();
		}


    private:
        
        PSPtr<btDiscreteDynamicsWorld> dynamicsWorld_;

	private:

		btDefaultCollisionConfiguration collisionConfiguration_;
		btCollisionDispatcher collisionDispatcher_;
		btDbvtBroadphase overlappingPairCache_;
		btSequentialImpulseConstraintSolver constraintSolver_;

    };

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_WORLD_H_