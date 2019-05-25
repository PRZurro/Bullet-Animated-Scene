/**
 * @file Declarations_OpenGL_Toolkit.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 23-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BULLET_ANIMATED_SCENE_DECLARATIONS_OPENGL_TOOLKIT_H_
#define BULLET_ANIMATED_SCENE_DECLARATIONS_OPENGL_TOOLKIT_H_

#include <Node.hpp>
#include <Light.hpp>
#include <Model.hpp>
#include <OpenGL.hpp>
#include <Model_Obj.hpp>
#include <Render_Node.hpp>

using namespace glt;

namespace prz
{

	using gltModel = glt::Model;
	using gltModelObj = glt::Model_Obj;
	using gltCamera = glt::Camera;
	using gltLight = glt::Light;
	using gltNode = glt::Node;
	using gltRenderNode = glt::Render_Node;

} // !namespace prz

#endif // !BULLET_ANIMATED_SCENE_DECLARATIONS_OPENGL_TOOLKIT_H_
