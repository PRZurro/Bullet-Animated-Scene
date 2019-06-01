/**
 * @file Catapult.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Entity class with constraints and logic that allows it to move and shoots projectiles by player input.
 * @version 0.1
 * @date 25-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_CATAPULT_H_
#define BULLET_ANIMATED_SCENE_CATAPULT_H_

#include <Entity.hpp>

namespace prz
{

	/**
	 * @brief Entity class with constraints and logic that allows it to move and shoots projectiles by player input.
	 * 
	 */
	class Catapult : public Entity
	{
	public:

		/**
		 * @brief Construct a new Catapult object
		 * 
		 * @param scene 
		 * @param name 
		 * @param startPosition 
		 */
		Catapult(Scene& scene, const PString& name, const gltVec3& startPosition = gltVec3(0.f));
		
	public:

		/**
		 * @brief 
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime) override; 

	public:

		/**
		 * @brief Use wheels constraints to move forward
		 * 
		 * @param speed 
		 */
		void move_forward(float speed);

		/**
		 * @brief Use wheels constraints to move back
		 * 
		 * @param speed 
		 */
		void move_back(float speed);

		/**
		 * @brief Use wheels constraints to turn right
		 * 
		 * @param speed 
		 */
		void turn_right(float speed);

		/**
		 * @brief Use wheels constraints to turn left
		 * 
		 * @param speed 
		 */
		void turn_left(float speed);

	public:

		/**
		 * @brief Use arm constraint to do a hit
		 * 
		 * @param speed 
		 */
		void use_arm(float speed);

		/**
		 * @brief Spawn a new projectile over this catapult
		 * 
		 */
		void spawn_new_projectile();

	public:

		/**
		 * @brief Disable all constraint motor speed. 
		 * 
		 */
		void disable_movement();

	private:

		PSPtr<btHingeConstraint> frontWheelConstraintL_;
		PSPtr<btHingeConstraint> frontWheelConstraintR_;
		PSPtr<btHingeConstraint> backWheelConstraintL_;
		PSPtr<btHingeConstraint> backWheelConstraintR_;

	private:

		PSPtr<btHingeConstraint> armConstraint_;

	private:
		
		static unsigned int projectilesCreated_;
	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_CATAPULT_H_