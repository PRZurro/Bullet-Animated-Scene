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

#ifndef BULLET_ANIMATED_SCENE_Catapult_H_
#define BULLET_ANIMATED_SCENE_Catapult_H_

#include <Entity.hpp>

namespace prz
{

	class Catapult : public Entity
	{
	public:

		Catapult(Scene& scene, const PString& name);
		
	protected:
	private:
	};

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_Catapult_H_