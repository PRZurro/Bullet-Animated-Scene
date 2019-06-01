/**
 * @file Demo_Scene_01.hpp
 * @author Pablo Rodriguez (przuro@gmail.com)
 * @brief Example of a scene 
 * @version 0.1
 * @date 26-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_DEMO_SCENE_O1_H_
#define BULLET_ANIMATED_SCENE_DEMO_SCENE_O1_H_

#include <Scene.hpp>

namespace prz
{
    /**
     * @brief Example of a scene 
     * 
     */
    class Demo_Scene_01 : public Scene
    {
    public:

        /**
         * @brief Construct a new Demo Scene 1
         * 
         * @param window 
         */
        Demo_Scene_01(Window& window);

	public:

        /**
         * @brief Initialize the scene
         * 
         */
		void initialize() override;

    };

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_DEMO_SCENE_O1_H_