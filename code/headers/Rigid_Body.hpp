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


#ifndef BULLET_ANIMATED_SCENE_RIGID_BODY_H_
#define BULLET_ANIMATED_SCENE_RIGID_BODY_H_

#include <Declarations.hpp>

namespace prz
{
    class Rigid_Body
    {
    public:
    
        Rigid_Body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			btQuaternion& initialRotation,
			RB_Construct_Info constructionInfo,
			float scale = 1.f
		);

		~Rigid_Body();

	public:

		void update(float deltaTime);
		virtual void auxiliar_update(float deltaTime) = 0;

	public:

		void set_transformation(btTransform& newTransformation);
		void reset_transformation(btVector3& newOrigin, btQuaternion& newRotation);
		void set_scale(float scale)
		{
			scale_ = scale;
		}

	public:
		
		operator PSPtr<gltModel>() { return model_; }
		operator btRigidBody* const() { return rigidBody_; }

	public:

		 PSPtr<gltModel> model() { return model_; }
		 btRigidBody* const rigidBody() { return rigidBody_; }
		 float scale() { return scale_; }

	protected:

		void sync_model_with_rigid_body();

	protected:

		PSPtr<gltModel> model_;
		btRigidBody* rigidBody_; 

	protected:

		float scale_;

    };

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_RIGID_BODY_H_