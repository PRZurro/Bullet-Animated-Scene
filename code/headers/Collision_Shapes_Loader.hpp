/**
 * @file Collision_Shapes_Loader.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Loader and storage of collision shapes
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
	/**
	 * @brief Loader and storage of collision shapes
	 * 
	 */
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

		/**
		 * @brief Load a sphere collision shape by:
		 * 
		 * @param radius 
		 * @return PSPtr<btCollisionShape> 
		 */
		PSPtr<btCollisionShape> load_sphere_collision_shape(float radius);

		/**
		 * @brief Load a cylinder collision shape by: 
		 * 
		 * !! Detected some collision errors due to the scale !! 
		 * 
		 * @param radius 
		 * @param halfHeight 
		 * @return PSPtr<btCollisionShape> 
		 */
		PSPtr<btCollisionShape> load_cylinder_collision_shape(float radius, float halfHeight);

		/**
		 * @brief Load a box collision shape by:
		 * 
		 * @param width 
		 * @param height 
		 * @param length 
		 * @return PSPtr<btCollisionShape> 
		 */
		PSPtr<btCollisionShape> load_box_collision_shape(float width, float height, float length);

		/**
		 * @brief Load a box collision shape by:
		 * 
		 * @param dimensions 
		 * @return PSPtr<btCollisionShape> 
		 */
		PSPtr<btCollisionShape> load_box_collision_shape(const gltVec3& dimensions);
		
	public:

		/**
		 * @brief Return the collision shape with name
		 * 
		 * @param name 
		 * @return PSPtr<btCollisionShape> 
		 */
		PSPtr<btCollisionShape> get_collision_shape(const PString& name);
		
	public:

		/**
		 * @brief Return if exists a collision shape by name
		 * 
		 * @param name 
		 * @return true 
		 * @return false 
		 */
		bool exists_collision_shape(const PString& name);

	public:

		/**
		 * @brief Create and return a sphere collision shape name by:
		 * 
		 * @param radius 
		 * @return PString 
		 */
		static PString form_sphere_collision_name(float radius);

		/**
		 * @brief Create and return a cylinder collision shape name by:
		 * 
		 * @param radius 
		 * @param halfHeight 
		 * @return PString 
		 */
		static PString form_cylinder_collision_name(float radius, float halfHeight);

		/**
		 * @brief Create and return a box collision shape name by:
		 * 
		 * @param width 
		 * @param height 
		 * @param length 
		 * @return PString 
		 */
		static PString form_box_collision_name(float width, float height, float length);

  private:

		/**
		 * @brief Construct a new Collision_Shapes_Loader (private)
		 * 
		 */
    Collision_Shapes_Loader(){}

	private:

		PMap <PString, PSPtr<btCollisionShape>> loadedCollisionShapes_;

    };

} // !namespace prz

#endif // !BULLET_ANIMATED_COLLISION_SHAPES_LOADER_H_
