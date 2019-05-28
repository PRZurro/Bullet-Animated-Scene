/**
 * @file Scene.hpp
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
	class Game_Manager;
	class Collision_Listener;

	class Scene
	{
	public:

		Scene(Window& window);

		~Scene()
		{
			world_.reset(); // Destroy the world before the rigid bodies
		}

	public:

		void update(float deltaTime);
		void render(float deltaTime);

	public:

		virtual void initialize() {}

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
		btDiscreteDynamicsWorld* const get_dynamics_world();
	public:

		PSPtr<World> world() { return world_; }
		PSPtr<Game_Manager> gameManager() { return gameManager_; }
		PSPtr<Collision_Listener> collisionListener() { return collisionListener_; }
		gltCamera* const activeCamera() const { return renderer_->get_active_camera(); }
		PSPtr<gltRenderNode> renderer() { return renderer_; }

	protected:

		void add_camera_and_lights_to_renderer();
		
	protected:

		PMap<PString, PSPtr<Entity>> entities_;

	protected:

		PSPtr<World> world_;
		PSPtr<Game_Manager> gameManager_;
		PSPtr<Collision_Listener> collisionListener_;

	protected:

		Window& window_;
		PSPtr<gltRenderNode> renderer_;

	protected:

		PMap<PString, PSPtr<gltCamera>> cameras_;
		PMap<PString, PSPtr<gltLight>> lights_;
	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_SCENE_H_
