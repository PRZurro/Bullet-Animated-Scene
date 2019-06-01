/**
 * @file World.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Bullet's dynamics world encapsulation class
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
	/**
	* @brief Bullet's dynamics world encapsulation class
	*
	*/
	class World
	{
	public:

		/**
		* @brief Construct a new World
		*
		* @param gravity
		*/
		World(btVector3& gravity = btVector3(0.f, -10.f, 0.f));

		/**
		* @brief Destroy the World
		* 
		*/
		~World();

	public:

		/**
		* @brief Operator -> to return a pointer to the dynamics world
		* 
		* @return btDiscreteDynamicsWorld* const 
		*/
		btDiscreteDynamicsWorld* const operator->() const { return dynamicsWorld_; }

		/**
		* @brief Operator () to return a pointer to the dynamics world
		*
		* @return btDiscreteDynamicsWorld* const
		*/
		btDiscreteDynamicsWorld* const operator()() const { return dynamicsWorld_; }

		/**
			* @brief Operator * to return a pointer to the dynamics world
			* 
			* @return btDiscreteDynamicsWorld* const 
			*/
		btDiscreteDynamicsWorld* const operator*() const { return dynamicsWorld_; }

		/**
		* @brief Operator to return a pointer to the dynamics world
		* 
		* @return btDiscreteDynamicsWorld* const 
		*/
		operator btDiscreteDynamicsWorld* const() const { return dynamicsWorld_; }

	public:

		/**
		* @brief Return the dynamics world
		* 
		* @return btDiscreteDynamicsWorld* const 
		*/
		btDiscreteDynamicsWorld* const dynamicsWorld() const { return dynamicsWorld_; }

	private:
        
		btDiscreteDynamicsWorld* dynamicsWorld_;

	private:

		// Dynamics world settings 

		btDefaultCollisionConfiguration collisionConfiguration_;
		btCollisionDispatcher collisionDispatcher_;
		btDbvtBroadphase overlappingPairCache_;
		btSequentialImpulseConstraintSolver constraintSolver_;

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_WORLD_H_