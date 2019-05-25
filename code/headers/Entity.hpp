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
	class Dynamic_Rigid_Body;
	class Kinematic_Rigid_Body;
	class Static_Rigid_Body;

	class Entity
	{
	public:

		Entity(Scene& scene, const PString& name) :
			sceneParent_(scene),
			name_(name)
		{}

		~Entity() {}

	public:

		virtual void update(float deltaTime);

	public:

		bool add_rigid_body(const PString& name, PSPtr<Rigid_Body> rigidBody)
		{
			if (!exists_rigid_body(name))
			{
				rigidBodies_[name] = rigidBody;
				return true;
			}

			return false;
		}

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

	public:

		PMap<PString, PSPtr<Rigid_Body>>& rigidBodies() { return rigidBodies_; }
		Scene& scene() { return sceneParent_; }
		const PString& name() const { return name_; }

	protected:

		PMap<PString, PSPtr<Rigid_Body>> rigidBodies_;

	protected:

		PMap<PString, PSPtr<Dynamic_Rigid_Body>> dynamicRigidBodies_;
		PMap<PString, PSPtr<Kinematic_Rigid_Body>> kinematicRigidBodies_;
		PMap<PString, PSPtr<Static_Rigid_Body>> staticRigidBodies_;

	protected:

		Scene& sceneParent_;

	protected:

		PString name_;
	
	};

} // !namespace prz 

#endif // !BULLET_ANIMATED_SCENE_ENTITY_H_
