/**
 * @file Entity.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Core class that manage and store rigid bodies and the constraints that unites them
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
	
	/**
	 * @brief Core class that manage and store rigid bodies
	 * 
	 */
	class Entity
	{
	public:

		/**
		 * @brief Construct a new Entity
		 * 
		 * @param scene 
		 * @param name 
		 * @param startPosition 
		 */
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

		/**
		 * @brief Destroy the Entity
		 * 
		 */
		~Entity() {}

	public:

		/**
		 * @brief Update the members of this entity
		 * 
		 * @param deltaTime 
		 */
		virtual void update(float deltaTime);

	public:

		/**
		 * @brief Add a kinematic rigid body
		 * 
		 * @param name 
		 * @param kinematicRigidBody 
		 * @return true 
		 * @return false 
		 */
		bool add_kinematic_rigid_body(const PString& name, PSPtr<Kinematic_Rigid_Body> kinematicRigidBody);

		/**
		 * @brief Add a static rigid body
		 * 
		 * @param name 
		 * @param staticRigidBody 
		 * @return true 
		 * @return false 
		 */
		bool add_static_rigid_body(const PString& name, PSPtr<Static_Rigid_Body> staticRigidBody);

		/**
		 * @brief Add a dynamic rigid body
		 * 
		 * @param name 
		 * @param dynamicRigidBody 
		 * @return true 
		 * @return false 
		 */
		bool add_dynamic_rigid_body(const PString& name, PSPtr<Dynamic_Rigid_Body> dynamicRigidBody);
		
	public:

		/**
		 * @brief Create a dynamic rigid body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param collisionShape 
		 * @param mass 
		 * @param initialRotation 
		 * @param localInertia 
		 * @param scale 
		 * @return PSPtr<Dynamic_Rigid_Body> 
		 */
		PSPtr<Dynamic_Rigid_Body> create_dynamic_rigid_body
		(	
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btScalar mass,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			btVector3 localInertia = btVector3(0.f, 0.f, 0.f),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);
		
		/**
		 * @brief Create a static rigid body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param collisionShape 
		 * @param initialRotation 
		 * @param scale 
		 * @return PSPtr<Static_Rigid_Body> 
		 */
		PSPtr<Static_Rigid_Body> create_static_rigid_body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

		/**
		 * @brief Create a kinematic rigid body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param collisionShape 
		 * @param linearFactor 
		 * @param initialRotation 
		 * @param scale 
		 * @return PSPtr<Kinematic_Rigid_Body> 
		 */
		PSPtr<Kinematic_Rigid_Body> create_kinematic_rigid_body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			PSPtr<btCollisionShape> collisionShape,
			const gltVec3& linearFactor,
			btQuaternion initialRotation = btQuaternion::getIdentity(),
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

	public:


		/**
		 * @brief Join two rigid bodies by: 
		 * 
		 * @param nameRigidBodyA 
		 * @param nameRigidBodyB 
		 * @param pivotA 
		 * @param pivotB 
		 * @param axisA 
		 * @param axisB 
		 * @param disableCollide 
		 * @return PSPtr<btHingeConstraint> 
		 */
		PSPtr<btHingeConstraint> join_rigid_bodies
		(
			const PString& nameRigidBodyA,
			const PString& nameRigidBodyB,
			const btVector3& pivotA,
			const btVector3& pivotB,
			const btVector3& axisA,
			const btVector3& axisB,
			bool disableCollide = true
		);

	public:

		/**
		 * @brief Return if exists an entity with the input name
		 * 
		 * @param name 
		 * @return true 
		 * @return false 
		 */
		bool exists_rigid_body(const PString& name)
		{
			return rigidBodies_.find(name) != rigidBodies_.end();
		}

	public:

		/**
		 * @brief Translate all kinematic bodies
		 * 
		 * @param translation 
		 */
		void translate(btVector3& translation);

	public:

		/**
		 * @brief Return the rigid body by name
		 * 
		 * @param name 
		 * @return PSPtr<Rigid_Body> 
		 */
		PSPtr<Rigid_Body> get_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? rigidBodies_[name] : PSPtr<Rigid_Body>();
		}

		/**
		 * @brief Return the dynamic rigid body by name
		 * 
		 * @param name 
		 * @return PSPtr<Dynamic_Rigid_Body> 
		 */
		PSPtr<Dynamic_Rigid_Body> get_dynamic_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? dynamicRigidBodies_[name] : PSPtr<Dynamic_Rigid_Body>();
		}

		/**
		 * @brief Return the kinematic rigid body by name
		 * 
		 * @param name 
		 * @return PSPtr<Kinematic_Rigid_Body> 
		 */
		PSPtr<Kinematic_Rigid_Body> get_kinematic_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? kinematicRigidBodies_[name] : PSPtr<Kinematic_Rigid_Body>();
		}

		/**
		 * @brief Return the static rigid body by name
		 * 
		 * @param name 
		 * @return PSPtr<Static_Rigid_Body> 
		 */
		PSPtr<Static_Rigid_Body> get_static_rigid_body(const PString& name)
		{
			return exists_rigid_body(name) ? staticRigidBodies_[name] : PSPtr<Static_Rigid_Body>();
		}

	public:

		/**
		 * @brief Return the rigid bodies map reference
		 * 
		 * @return PMap<PString, PSPtr<Rigid_Body>>& 
		 */
		PMap<PString, PSPtr<Rigid_Body>>& rigidBodies() { return rigidBodies_; }

		/**
		 * @brief Return the scene owner
		 * 
		 * @return Scene& 
		 */
		Scene& scene() { return sceneParent_; }

		/**
		 * @brief Return the name of this entity
		 * 
		 * @return const PString& 
		 */
		const PString& name() const { return name_; }

		/**
		 * @brief Return the type of this entity
		 * 
		 * @return const PString& 
		 */
		const PString& type() const { return type_; }

	protected:

		PMap<PString, PSPtr<Rigid_Body>> rigidBodies_;

	protected:

		PMap<PString, PSPtr<Dynamic_Rigid_Body>> dynamicRigidBodies_;
		PMap<PString, PSPtr<Kinematic_Rigid_Body>> kinematicRigidBodies_;
		PMap<PString, PSPtr<Static_Rigid_Body>> staticRigidBodies_;

	protected:

		PMap<PString, PSPtr<btHingeConstraint>> hingeConstraints_;

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
