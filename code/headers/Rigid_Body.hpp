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

#include <Rigid_Body_Construction_Info.hpp>

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
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

		~Rigid_Body();

	public:

		void update(float deltaTime);
		virtual void auxiliar_update(float deltaTime) = 0;

	public:

		void set_transformation(btTransform& newTransformation);
		void reset_transformation(btVector3& newOrigin, btQuaternion& newRotation);

		void set_scale(gltVec3 scale)
		{
			scale_ = scale;
		}
		void set_scale(float scale)
		{
			scale_ = gltVec3(scale, scale, scale);
		}

	public:
		
		operator PSPtr<gltModel>() { return model_; }
		operator btRigidBody* const() { return rigidBody_; }

	public:

		 PSPtr<gltModel> model() { return model_; }
		 btRigidBody* const rigidBody() { return rigidBody_; }
		 const gltVec3& scale() { return scale_; }
		 const PString& name() { return name_; };

	protected:

		virtual void sync_model_with_rigid_body();

	protected:

		PSPtr<gltModel> model_;
		btRigidBody* rigidBody_; 

	protected:

		gltVec3 scale_;

	protected:

		PString name_;

	protected:

		Rigid_Body_Construction_Info constructionInfo_;

    };

} // !namespace prz


#endif // !BULLET_ANIMATED_SCENE_RIGID_BODY_H_