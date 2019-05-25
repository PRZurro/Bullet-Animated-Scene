/**
 * @file View.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 07-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_SCENE_H_
#define BULLET_ANIMATED_SCENE_SCENE_H_

#include <Camera.hpp>

#include <Declarations.hpp>

#include <SFML/Window.hpp>

using namespace sf;

namespace prz
{

	class Entity;
	class World;

	class Scene
	{
	public:

		Scene(Window& window);
		~Scene()
		{
			world_.reset(); // Destroy the world before the rigidbodies
		}


	public:

		void update(float deltaTime);
		void render(float deltaTime);

	public:

		virtual void initialize();

	public:

		void display()
		{
			window_.display();
		}

	public:

		void on_window_resized();

	public:

		PSPtr<Entity> add_entity(PSPtr<Entity> entity, PSPtr<Entity> parent = PSPtr < Entity>(), bool subscribeToRenderer = true);
		PSPtr<Entity> create_entity(const PString& name, PSPtr<Entity> parent = PSPtr < Entity>());
		
	public:

		bool exists_entity(PSPtr<Entity> entity) const;
		bool exists_entity(const PString& name) const { return entities_.find(name) != entities_.end(); }

	public:

		PSPtr<Entity> get_entity(const PString& name) { return exists_entity(name) ? entities_[name] : PSPtr<Entity>(); }
		PSPtr<btDiscreteDynamicsWorld> get_dynamics_world();

	public:

		const PSPtr<Camera> activeCamera() const { return activeCamera_; }
		PSPtr<World> world(){ return world_; }

	protected:

		PMap<PString, PSPtr<Entity>> entities_;
		PSPtr<World> world_;

	protected:

		Window& window_;
		PSPtr<gltRenderNode> renderer_;
		PSPtr<gltCamera> activeCamera_;

	protected:

		PSPtr<gltLight> light_;
	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_SCENE_H_
