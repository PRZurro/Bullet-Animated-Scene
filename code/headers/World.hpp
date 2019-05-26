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

#ifndef BULLET_ANIMATED_SCENE_WORLD_H_
#define BULLET_ANIMATED_SCENE_WORLD_H_

#include <Declarations.hpp>

namespace prz
{
    class World
    {
	public:

		World(btVector3& gravity = btVector3(0, -10, 0));
		~World();

	public:

		btDiscreteDynamicsWorld* const operator->() const { return dynamicsWorld_; }
		btDiscreteDynamicsWorld* const operator()() const { return dynamicsWorld_; }
		btDiscreteDynamicsWorld* const operator*() const { return dynamicsWorld_; }
		operator btDiscreteDynamicsWorld* const() const { return dynamicsWorld_; }

	public:

		btDiscreteDynamicsWorld* const dynamicsWorld() const { return dynamicsWorld_; }

    private:
        
		btDiscreteDynamicsWorld* dynamicsWorld_;

	private:

		btDefaultCollisionConfiguration collisionConfiguration_;
		btCollisionDispatcher collisionDispatcher_;
		btDbvtBroadphase overlappingPairCache_;
		btSequentialImpulseConstraintSolver constraintSolver_;

    };

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_WORLD_H_