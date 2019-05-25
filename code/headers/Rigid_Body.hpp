/**
 * @file Rigid_Body.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief 
 * @version 0.1
 * @date 23-05-2019
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <Declarations.hpp>

#ifndef BULLET_ANIMATED_SCENE_RIGID_BODY_H_
#define BULLET_ANIMATED_SCENE_RIGID_BODY_H_

namespace prz
{
    class Rigid_Body
    {
    public:
    
        Rigid_Body(const PString& name, PSPtr<btCollisionShape> collisionShape);
        ~Rigid_Body();

	public:
		
		operator PSPtr<gltModel>() { return model_; }
		operator PSPtr<btRigidBody>() { return rigidBody_; }
		operator btRigidBody*() { return rigidBody_.get(); }

	public:

		 PSPtr<gltModel> model() { return model_; }
		 PSPtr<btRigidBody> rigidBody() { return rigidBody_; }
		 PSPtr<btCollisionShape> collisionShape() { return collisionShape_; }
		 PSPtr<btDefaultMotionState> motionState() { return motionState_; }
		 float scale() { return scale_; }

	protected:

		PSPtr<gltModel> model_;
		PSPtr<btRigidBody> rigidBody_;
		
	protected:

		PSPtr<btCollisionShape> collisionShape_;
		PSPtr<btDefaultMotionState> motionState_;

	protected:

		float scale_;

    };

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_RIGID_BODY_H_