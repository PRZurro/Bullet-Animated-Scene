#include "Collision_Shapes_Loader.hpp"

namespace prz
{
	PSPtr<btCollisionShape> Collision_Shapes_Loader::load_sphere_collision_shape(float radius)
	{
		PString name = form_sphere_collision_name(radius);
		PSPtr<btCollisionShape> collisionShape(get_collision_shape(name));

		if (collisionShape)
		{
			return collisionShape;
		}
		else
		{
			collisionShape = make_shared<btSphereShape>(radius);
			loadedCollisionShapes_[name] = collisionShape;
			return loadedCollisionShapes_[name];
		}
	}

	PSPtr<btCollisionShape> Collision_Shapes_Loader::load_cylinder_collision_shape(float radius, float halfHeight)
	{
		PString name = form_cylinder_collision_name(radius, halfHeight);
		PSPtr<btCollisionShape> collisionShape(get_collision_shape(name));

		if (collisionShape)
		{
			return collisionShape;
		}
		else
		{
			collisionShape = make_shared<btCylinderShape>(btVector3(radius, radius, halfHeight));
			loadedCollisionShapes_[name] = collisionShape;
			return loadedCollisionShapes_[name];
		}
	}

	PSPtr<btCollisionShape> Collision_Shapes_Loader::load_box_collision_shape(float width, float height, float length)
	{
		PString name = form_box_collision_name(width, height, length);
		PSPtr<btCollisionShape> collisionShape(get_collision_shape(name));

		if (collisionShape)
		{
			return collisionShape;
		}
		else
		{
			collisionShape = make_shared<btBoxShape>(btVector3(btVector3(width, height, length)));
			loadedCollisionShapes_[name] = collisionShape;
			return loadedCollisionShapes_[name];
		}
	}

	PSPtr<btCollisionShape> Collision_Shapes_Loader::load_box_collision_shape(const gltVec3& dimensions)
	{
		return load_box_collision_shape(dimensions.x, dimensions.y, dimensions.z);
	}

	PSPtr<btCollisionShape> Collision_Shapes_Loader::get_collision_shape(const PString& name)
	{
		if (exists_collision_shape(name))
		{
			return loadedCollisionShapes_[name];
		}

		return PSPtr<btCollisionShape>();
	}


	bool Collision_Shapes_Loader::exists_collision_shape(const PString& name)
	{
		if (loadedCollisionShapes_.find(name) != loadedCollisionShapes_.end())
		{
			return true;
		}

		return false;
	}

	PString Collision_Shapes_Loader::form_sphere_collision_name(float radius)
	{
		return "Sphere_Collision_Shape: - Radius: " + to_string(radius);
	}
	PString Collision_Shapes_Loader::form_cylinder_collision_name(float radius, float halfHeight)
	{
		return "Cylinder_Collision_Shape: - Radius: " + to_string(radius) + " - Half Height: " + to_string(halfHeight);
	}

	PString Collision_Shapes_Loader::form_box_collision_name(float width, float height, float length)
	{
		return "Box_Collision_Shape: - Width: " + to_string(width) + " -Height: " + to_string(height) + " - Z: " + to_string(length);
	}
}
