/**
 * @file Sensor.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 24-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_SENSOR_H_
#define BULLET_ANIMATED_SCENE_SENSOR_H_

#include <Declarations.hpp>

namespace prz
{

	class Sensor
	{
	public:
		Sensor();
		~Sensor();

	private:

		PSPtr<btGhostObject> ghostSensor_;
		PSPtr<btCollisionShape> collisionShape_;
		
		btTransform transform_;

	};

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_SENSOR_H_BULLET_ANIMATED_SCENE_SENSOR_H_
