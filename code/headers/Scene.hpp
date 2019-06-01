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
	
	/**
	 * @brief Core class that store and manages all the entities, the Bullet's dynamics world and the OpenGL Toolkit's renderer
	 * 
	 */
	class Scene
	{
	public:

		/**
		 * @brief Construct a new Scene
		 * 
		 * @param window 
		 */
		Scene(Window& window);

		/**
		 * @brief Destroy the Scene
		 * 
		 */
		~Scene()
		{
			world_.reset(); // Destroy the world before the rigid bodies
		}

	public:

		/**
		 * @brief Update the scene
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);

		/**
		 * @brief Render the scene
		 * 
		 * @param deltaTime 
		 */
		void render(float deltaTime);

	public:
		
		/**
		 * @brief Initialize the scene (for child classes)
		 * 
		 */
		virtual void initialize() {}

	public:

		/**
		 * @brief Swap the window frames
		 * 
		 */
		void display()
		{
			window_.display();
		}

	public:

		/**
		 * @brief Method called when the window's size has changed
		 * 
		 */
		void on_window_resized();

	public:

		/**
		 * @brief Add an entity by:
		 * 
		 * @param entity 
		 * @param parent 
		 * @param subscribeToRenderer 
		 * @return PSPtr<Entity> 
		 */
		PSPtr<Entity> add_entity(PSPtr<Entity> entity, PSPtr<Entity> parent = PSPtr < Entity>(), bool subscribeToRenderer = true);

		/**
		 * @brief Create an empty entity 
		 * 
		 * @param name 
		 * @param parent 
		 * @return PSPtr<Entity> 
		 */
		PSPtr<Entity> create_entity(const PString& name, PSPtr<Entity> parent = PSPtr < Entity>());
		
	public:

		/**
		 * @brief Return if is stored the information of the input entity in this scene
		 * 
		 * @param entity 
		 * @return true 
		 * @return false 
		 */
		bool exists_entity(PSPtr<Entity> entity) const;

		/**
		 * @brief Return if is stored an entity with the input name
		 * 
		 * @param name 
		 * @return true 
		 * @return false 
		 */
		bool exists_entity(const PString& name) const { return entities_.find(name) != entities_.end(); }

	public:

		/**
		 * @brief Return the entity by name
		 * 
		 * @param name 
		 * @return PSPtr<Entity> 
		 */
		PSPtr<Entity> get_entity(const PString& name) { return exists_entity(name) ? entities_[name] : PSPtr<Entity>(); }

		/**
		 * @brief Return a pointer to the dynamics world
		 * 
		 * @return btDiscreteDynamicsWorld* const 
		 */
		btDiscreteDynamicsWorld* const get_dynamics_world();
	public:

		/**
		 * @brief Return the dynamics world encapsulation class
		 * 
		 * @return PSPtr<World> 
		 */
		PSPtr<World> world() { return world_; }

		/**
		 * @brief Return the game manager of this scene
		 * 
		 * @return PSPtr<Game_Manager> 
		 */
		PSPtr<Game_Manager> gameManager() { return gameManager_; }

		/**
		 * @brief Return the collisions listener
		 * 
		 * @return PSPtr<Collision_Listener> 
		 */
		PSPtr<Collision_Listener> collisionListener() { return collisionListener_; }


		/**
		 * @brief Return the active camera
		 * 
		 * @return gltCamera* const 
		 */
		gltCamera* const activeCamera() const { return renderer_->get_active_camera(); }

		/**
		 * @brief Return the scene renderer 
		 * 
		 * @return PSPtr<gltRenderNode> 
		 */
		PSPtr<gltRenderNode> renderer() { return renderer_; }

	protected:

		/**
		 * @brief Add the stored camera and lighst to the renderer
		 * 
		 */
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
