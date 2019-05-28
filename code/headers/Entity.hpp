/**
 * @file Entity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 09-05-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BULLET_ANIMATED_SCENE_ENTITY_H_
#define BULLET_ANIMATED_SCENE_ENTITY_H_

#include <Declarations.hpp>

namespace prz
{

	class Scene;
	class Rigid_Body;
	class Dynamic_Rigid_Body;
	class Kinematic_Rigid_Body;
	class Static_Rigid_Body;

	class Entity
	{
	public:
 
		Entity
		(
			Scene& scene,
			const PString& name,
			const gltVec3& startPosition = gltVec3(0.f)
		) :
			sceneParent_(scene),
			name_(name),
			startPosition_(startPosition)
		{}

		~Entity() {}

	public:

		virtual void update(float deltaTime);

	public:

		bool add_kinematic_rigid_body(const PString& name, PSPtr<Kinematic_Rigid_Body> kinematicRigidBody);
		bool add_static_rigid_body(const PString& name, PSPtr<Static_Rigid_Body> staticRigidBody);
		bool add_dynamic_rigid_body(const PString& name, PSPtr<Dynamic_Rigid_Body> dynamicRigidBody);
		
	public:

		PSPtr<Dynamic_Rigid_Body> create_dynamic_rigid_body
		(	
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btScalar mass,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			btVector3 localInertia = btVector3(0, 0, 0),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);
		
		PSPtr<Static_Rigid_Body> create_static_rigid_body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

		PSPtr<Kinematic_Rigid_Body> create_kinematic_rigid_body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

	public:

		bool exists_rigid_body(const PString& name)
		{
			return rigidBodies_.find(name) != rigidBodies_.end();
		}

	public:

		void translate(btVector3& translation);

	public:

		PSPtr<Rigid_Body> get_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? rigidBodies_[name] : PSPtr<Rigid_Body>();
		}

		PSPtr<Dynamic_Rigid_Body> get_dynamic_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? dynamicRigidBodies_[name] : PSPtr<Dynamic_Rigid_Body>();
		}

		PSPtr<Kinematic_Rigid_Body> get_kinematic_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? kinematicRigidBodies_[name] : PSPtr<Kinematic_Rigid_Body>();
		}

		PSPtr<Static_Rigid_Body> get_static_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? staticRigidBodies_[name] : PSPtr<Static_Rigid_Body>();
		}

	public:

		PMap<PString, PSPtr<Rigid_Body>>& rigidBodies() { return rigidBodies_; }
		Scene& scene() { return sceneParent_; }
		const PString& name() const { return name_; }
		const PString& type() const { return type_; }

	protected:

		PMap<PString, PSPtr<Rigid_Body>> rigidBodies_;

	protected:

		PMap<PString, PSPtr<Dynamic_Rigid_Body>> dynamicRigidBodies_;
		PMap<PString, PSPtr<Kinematic_Rigid_Body>> kinematicRigidBodies_;
		PMap<PString, PSPtr<Static_Rigid_Body>> staticRigidBodies_;

	protected:

		Scene& sceneParent_;

	protected:

		gltVec3 startPosition_;

	protected:

		PString name_;

	protected:

		PString type_;
	
	};

} // !namespace prz 

#endif // !BULLET_ANIMATED_SCENE_ENTITY_H_
