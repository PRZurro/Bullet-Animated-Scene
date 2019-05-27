#include <Scene.hpp>

#include <Entity.hpp>
#include <World.hpp>
#include <Game_Manager.hpp>
#include <Rigid_Body.hpp>
#include <Collision_Listener.hpp>

namespace prz
{

	Scene::Scene(Window& window) :
		world_(make_shared<World>()),
		collisionListener_(make_shared<Collision_Listener>(world_)),
		window_(window),
		renderer_(make_shared<gltRenderNode>())
	{
		on_window_resized();
	}

	void Scene::update(float deltaTime)
	{
		if (world_)
		{
			(*world_)->stepSimulation(deltaTime);
		}

		for (auto& pair : entities_)
		{
			pair.second->update(deltaTime);
		}

		if (collisionListener_)
		{
			collisionListener_->update(deltaTime);

			if (gameManager_)
			{
				gameManager_->manage_game(deltaTime, collisionListener_);
			}
		}
	}

	void Scene::render(float deltaTime)
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.2f, 0.2f, 0.2f, 1.f);

		if (renderer_->get_active_camera())
		{
			renderer_->render();
		}
	}

	void Scene::on_window_resized()
	{
		Vector2u windowSize = window_.getSize();

		gltCamera* activeCamera = renderer_->get_active_camera();

		if (activeCamera)
		{
			activeCamera->set_aspect_ratio(float(windowSize.x) / windowSize.y);
		}

		glViewport(0, 0, windowSize.x, windowSize.y);
	}

	PSPtr<Entity> Scene::add_entity(PSPtr<Entity> entity, PSPtr<Entity> parent, bool subscribeToRenderer)
	{
		const PString& entityName = entity->name();

		if (!exists_entity(entityName))
		{
			entities_[entityName] = entity;

			if (subscribeToRenderer)
			{
				auto& rigidBodiesMap = entity->rigidBodies();

				for(auto & rbPair : rigidBodiesMap)
				{
					PSPtr<gltModel> model = *rbPair.second; // .model() as alternative

					renderer_->add(entityName + " rigid body model: " + rbPair.first, model);
				}
			}
			
			return entity;
		}

		return PSPtr<Entity>();
	}

	PSPtr<Entity> Scene::create_entity(const PString& name, PSPtr<Entity> parent)
	{
		return add_entity(make_shared< Entity>(*this, name));
	}

	bool Scene::exists_entity(PSPtr<Entity> entity) const
	{
		return entity && exists_entity(entity->name()) ? true : false;
	}
	btDiscreteDynamicsWorld* const Scene::get_dynamics_world()
	{
		{ return *world_; }
	}
	void Scene::add_camera_and_lights_to_renderer()
	{
		for (auto& pair : cameras_)
		{
			renderer_->add(pair.first, pair.second);
		}

		for (auto& pair : lights_)
		{
			renderer_->add(pair.first, pair.second);
		}
	}

}
