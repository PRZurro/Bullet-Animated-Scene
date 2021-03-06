#include <Collision_Listener.hpp>

#include <World.hpp>
#include <Entity.hpp>

namespace prz
{
	bool Collision_Listener::has_bodies_collided(btRigidBody* bodyA, btRigidBody* bodyB)
	{
		if (collisionsRegistry_.find(bodyA) != collisionsRegistry_.end())
		{
			if (collisionsRegistry_[bodyA] == bodyB)
			{
				return true;
			}
		}

		return false;
	}

	bool Collision_Listener::has_bodies_collided(const PString& typeA, const PString& typeB)
	{

		if (collisionsRegistryByEntityType_.find(typeA) != collisionsRegistryByEntityType_.end())
		{
			if (collisionsRegistryByEntityType_[typeA] == typeB)
			{
				return true;
			}
		}

		return false;
	}

	Collision_Listener::Collision_Listener(PSPtr<World> world) :
		world_(world)
	{}

	void Collision_Listener::register_collisions()
	{
		if (world_)
		{
			btDynamicsWorld* btWorld = *world_;

			int nManifolds = btWorld->getDispatcher()->getNumManifolds();
			for (int i = 0; i < nManifolds; i++)
			{
				btPersistentManifold* manifold = btWorld->getDispatcher()->getManifoldByIndexInternal(i);
				btCollisionObject* objectA = (btCollisionObject*)(manifold->getBody0());
				btCollisionObject* objectB= (btCollisionObject*)(manifold->getBody1());
				
				int nContacts= manifold->getNumContacts();
				for (int j = 0; j < nContacts; j++)
				{
					btManifoldPoint& point = manifold->getContactPoint(j);
					if (point.getDistance() < 0.f)
					{
						register_collision(objectA, objectB);
					}
				}
			}
		}
	}
	void Collision_Listener::register_collision(btCollisionObject* objectA, btCollisionObject* objectB)
	{
		collisionsRegistry_[objectA] = objectB; 
		collisionsRegistry_[objectB] = objectA;

		Entity* entityA = (Entity*)objectA->getUserPointer();
		Entity* entityB = (Entity*)objectB->getUserPointer();

		PString typeA = entityA->type();
		PString typeB = entityB->type();

		collisionsRegistryByEntityType_[typeA] = typeB;
		collisionsRegistryByEntityType_[typeB] = typeA;

	}
}