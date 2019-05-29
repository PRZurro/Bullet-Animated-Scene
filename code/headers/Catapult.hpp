/**
 * @file Catapult.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief 
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

	class Catapult : public Entity
	{
	public:

		Catapult(Scene& scene, const PString& name, const gltVec3& startPosition = gltVec3(0.f));
		
	public:

		void update(float deltaTime) override; 

	public:

		void move_forward(float speed);
		void move_back(float speed);
		void turn_right(float speed);
		void turn_left(float speed);

	public:

		void use_arm(float speed);
		void spawn_new_projectile();

	public:

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