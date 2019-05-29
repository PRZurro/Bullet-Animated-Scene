/**
 * @file Collision_Listener.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
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

	class Collision_Listener
	{
	public:

		Collision_Listener(PSPtr<World> world);

	public:

		void update(float deltaTime)
		{
			collisionsRegistry_.clear();
			register_collisions();
		}

	public:

		void register_collisions();

	public:

		bool has_bodies_collided(btRigidBody* bodyA, btRigidBody* bodyB);
		bool has_bodies_collided(const PString& typeA, const PString& typeB);

	private:

		void register_collision(btCollisionObject* objectA, btCollisionObject* objectB);

	private:

		PMap<btCollisionObject* , btCollisionObject*> collisionsRegistry_;
		PMap<PString, PString> collisionsRegistryByEntityType_;

	private:

		PSPtr<World> world_;
	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_COLLISION_LISTENER_H_
