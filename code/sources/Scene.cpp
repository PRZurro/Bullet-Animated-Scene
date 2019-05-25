#include <Scene.hpp>

#include <Entity.hpp>
#include <World.hpp>
#include <Game_Manager.hpp>
#include <Rigid_Body.hpp>
#include <Collision_Listener.hpp>WW


namespace prz
{

	Scene::Scene(Window& window) :
		world_(make_shared<World>()),
		gameManager_(make_shared<Game_Manager>(*this)),
		collisionListener_(make_shared<Collision_Listener>(world_)),
		window_(window),
		renderer_(make_shared<gltRenderNode>()),
		activeCamera_(make_shared< gltCamera>(20.f, 1.f, 50.f, 1.f))
	{
		on_window_resized();
	}

	void Scene::update(float deltaTime)
	{
		(*world_)->stepSimulation(deltaTime);

		for (auto& pair : entities_)
		{
			pair.second->update(deltaTime);
		}
	}

	void Scene::render(float deltaTime)
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.5, 0.5, 0.5, 1.0);

		renderer_->render();
	}

	void Scene::initialize()
	{
		(*world_)->setGravity(btVector3(0, -10, 0));
		light_->translate(glt::Vector3(10.f, 10.f, 10.f));
	}

	void Scene::on_window_resized()
	{
		Vector2u windowSize = window_.getSize();
		activeCamera_->set_aspect_ratio(float(windowSize.x) / windowSize.y);
		glViewport(0, 0, windowSize.x, windowSize.y);
	}

	PSPtr<Entity> Scene::add_entity(PSPtr<Entity> entity, PSPtr<Entity> parent, bool subscribeToRenderer)
	{
		if (!exists_entity(entity))
		{
			entities_[entity->name()] = entity;

			if (subscribeToRenderer)
			{
				for(auto & pair : entity->rigidBodies())
				{
					renderer_->add(pair.first, pair.second->model());
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
	PSPtr<btDiscreteDynamicsWorld> Scene::get_dynamics_world()
	{
		{ return *(*world_); }
	}
}
