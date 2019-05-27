#include "Entity.hpp"

#include <Scene.hpp>
#include <Rigid_Body.hpp>
#include <Dynamic_Rigid_Body.hpp>
#include <Kinematic_Rigid_Body.hpp>
#include <Static_Rigid_Body.hpp>

namespace prz
{
	void Entity::update(float deltaTime)
	{
		for (auto& pair : rigidBodies_)
		{
			PSPtr<Rigid_Body> rigidBody = pair.second;

			pair.second->update(deltaTime);
		}
	}

	bool Entity::add_kinematic_rigid_body(const PString& name, PSPtr<Kinematic_Rigid_Body> kinematicRigidBody)
	{
		if (!exists_rigid_body(name))
		{
			// Add the pointer to this entity, save the rigid body and add the rigid body to the bullet World

			kinematicRigidBody->rigidBody()->setUserPointer(this);
			rigidBodies_[name] = kinematicRigidBody;
			kinematicRigidBodies_[name] = kinematicRigidBody;
			sceneParent_.get_dynamics_world()->addRigidBody(*kinematicRigidBodies_[name]);
			
			return true;
		}

		return false;
	}

	bool Entity::add_static_rigid_body(const PString& name, PSPtr<Static_Rigid_Body> staticRigidBody)
	{
		if (!exists_rigid_body(name))
		{
			// Add the pointer to this entity, save the rigid body and add the rigid body to the bullet World

			staticRigidBody->rigidBody()->setUserPointer(this);
			rigidBodies_[name] = staticRigidBody;
			staticRigidBodies_[name] = staticRigidBody;
			sceneParent_.get_dynamics_world()->addRigidBody(*staticRigidBodies_[name]);

			return true;
		}

		return false;
	}

	bool Entity::add_dynamic_rigid_body(const PString& name, PSPtr<Dynamic_Rigid_Body> dynamicRigidBody)
	{
		if (!exists_rigid_body(name))
		{
			// Add the pointer to this entity, save the rigid body and add the rigid body to the bullet World

			dynamicRigidBody->rigidBody()->setUserPointer(this);
			rigidBodies_[name] = dynamicRigidBody;
			dynamicRigidBodies_[name] = dynamicRigidBody;
			sceneParent_.get_dynamics_world()->addRigidBody(*dynamicRigidBodies_[name]);

			return true;
		}

		return false;
	}

	PSPtr<Dynamic_Rigid_Body> Entity::create_dynamic_rigid_body(const PString& name, PSPtr<Model> model, btVector3& origin, PSPtr<btCollisionShape> collisionShape, btScalar mass, btQuaternion initialRotation, btVector3 localInertia, const gltVec3& scale)
	{
		if (add_dynamic_rigid_body(name, make_shared<Dynamic_Rigid_Body>
		(
			name,
			model,
			origin + btVector3(startPosition_.x, startPosition_.y, startPosition_.z),
			collisionShape,
			mass,
			initialRotation,
			localInertia,
			scale
		)))
		{
			return dynamicRigidBodies_[name];
		}

		return PSPtr<Dynamic_Rigid_Body>();
	}

	PSPtr<Static_Rigid_Body> Entity::create_static_rigid_body(const PString& name, PSPtr<Model> model, btVector3& origin, PSPtr<btCollisionShape> collisionShape, btQuaternion initialRotation, const gltVec3& scale)
	{
		if (add_static_rigid_body(name, make_shared<Static_Rigid_Body>
		(
			name,
			model,
			origin + btVector3(startPosition_.x, startPosition_.y, startPosition_.z),
			collisionShape,
			initialRotation,
			scale
		)))
		{
			return staticRigidBodies_[name];
		}

		return PSPtr<Static_Rigid_Body>();
	}

	PSPtr<Kinematic_Rigid_Body> Entity::create_kinematic_rigid_body(const PString& name, PSPtr<Model> model, btVector3& origin, PSPtr<btCollisionShape> collisionShape, btQuaternion initialRotation, const gltVec3& scale)
	{
		if (add_kinematic_rigid_body(name, make_shared<Kinematic_Rigid_Body>
		(
			name,
			model,
			origin + btVector3(startPosition_.x, startPosition_.y, startPosition_.z),
			collisionShape,
			initialRotation,
			scale
		)))
		{
			return kinematicRigidBodies_[name];
		}

		return PSPtr<Kinematic_Rigid_Body>();
	}

	void Entity::translate(btVector3& translation)
	{
		for (auto& pair : kinematicRigidBodies_)
		{
			pair.second->translate(translation);
		}
	}
}
