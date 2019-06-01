/**
 * @file Collision_Listener.hpp
 * @author Pablo Rodriguez Zurro (przuro@gmail.com)
 * @brief Class to store the collisions that happened in the world
 * @version 0.1
 * @date 25-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_COLLISION_LISTENER_H_
#define BULLET_ANIMATED_SCENE_COLLISION_LISTENER_H_

#include <Declarations.hpp>

namespace prz
{
	class World;		

	/**
	 * @brief Class to store the collisions that happened in the world
	 * 
	 */
	class Collision_Listener
	{
	public:

		/**
		 * @brief Construct a new Collision_Listener
		 * 
		 * @param world 
		 */
		Collision_Listener(PSPtr<World> world);

	public:

		/**
		 * @brief Update the collision listener. Store all collisions happened in the dynamics world
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime)
		{
			collisionsRegistry_.clear();
			register_collisions();
		}

	public:

		/**
		 * @brief Check all collisions and register them
		 * 
		 */
		void register_collisions();

	public:

		/**
		 * @brief Return if two bodies by pointer has collided
		 * 
		 * @param bodyA 
		 * @param bodyB 
		 * @return true 
		 * @return false 
		 */
		bool has_bodies_collided(btRigidBody* bodyA, btRigidBody* bodyB);

		/**
		 * @brief Return if two bodies by name has collided
		 * 
		 * @param typeA 
		 * @param typeB 
		 * @return true 
		 * @return false 
		 */
		bool has_bodies_collided(const PString& typeA, const PString& typeB);

	private:

		/**
		 * @brief Register a single collision
		 * 
		 * @param objectA 
		 * @param objectB 
		 */
		void register_collision(btCollisionObject* objectA, btCollisionObject* objectB);

	private:

		PMap<btCollisionObject* , btCollisionObject*> collisionsRegistry_;
		PMap<PString, PString> collisionsRegistryByEntityType_;

	private:

		PSPtr<World> world_;
	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_COLLISION_LISTENER_H_
