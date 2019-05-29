/**
 * @file Collision_Shapes_Loader.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 26-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_COLLISION_SHAPES_LOADER_H_
#define BULLET_ANIMATED_COLLISION_SHAPES_LOADER_H_

#include <Declarations.hpp>

namespace prz
{
	class Collision_Shapes_Loader
    {
	public:

		/*enum ShapeType : unsigned int
		{
			SPHERE = 0x000,
			BOX = 0x001,
			CYLINDER = 0x002
		};*/

	public:

		/**
		 * @brief Get an static instance object of this class
		 *
		 * @return Collision_Shapes_Loader&
		 */
		static Collision_Shapes_Loader& instance()
		{
			static Collision_Shapes_Loader instance;
			return instance;
		}

	public:

		PSPtr<btCollisionShape> load_sphere_collision_shape(float radius);
		PSPtr<btCollisionShape> load_cylinder_collision_shape(float radius, float halfHeight);
		PSPtr<btCollisionShape> load_box_collision_shape(float width, float height, float length);
		PSPtr<btCollisionShape> load_box_collision_shape(const gltVec3& dimensions);
		
	public:

		PSPtr<btCollisionShape> get_collision_shape(const PString& name);
		
	public:

		bool exists_collision_shape(const PString& name);

	public:

		static PString form_sphere_collision_name(float radius);
		static PString form_cylinder_collision_name(float radius, float halfHeight);
		static PString form_box_collision_name(float width, float height, float length);

    private:

        Collision_Shapes_Loader(){}

	private:

		PMap <PString, PSPtr<btCollisionShape>> loadedCollisionShapes_;

    };

} // !namespace prz

#endif // !BULLET_ANIMATED_COLLISION_SHAPES_LOADER_H_
