/**
 * @file Rigid_Body.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief Abstract core class to manage and store the information of a bullet rigid body and a model node of OpenGL toolkit
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
	
	/**
	 * @brief Abstract core class to manage and store the information of a bullet rigid body and a model node of OpenGL toolkit
	 * 
	 */
    class Rigid_Body
    {
    public:

		/**
		 * @brief Construct a new Rigid_Body
		 * 
		 * @param name 
		 * @param model 
		 * @param origin 
		 * @param initialRotation 
		 * @param constructionInfo 
		 * @param scale 
		 */
        Rigid_Body
		(
			const PString& name,
			PSPtr<Model> model,
			btVector3& origin,
			btQuaternion& initialRotation,
			RB_Construct_Info constructionInfo,
			const gltVec3& scale = gltVec3(1.f, 1.f, 1.f)
		);

		/**
		 * @brief Destroy the Rigid_Body
		 * 
		 */
		~Rigid_Body();

	public:

		/**
		 * @brief Update the rigid body
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);	

		/**
		 * @brief Optional method provided to child classes extra logic
		 * 
		 * @param deltaTime 
		 */
		virtual void auxiliar_update(float deltaTime) = 0;

	public:

		/**
		 * @brief Set the transformation of the rigid body (that will by syncronized to the OpenGL Toolkit's model)
		 * 
		 * @param newTransformation 
		 */
		void set_transformation(btTransform& newTransformation);

		/**
		 * @brief Reset the transformation of the rigid body (that will by syncronized to the OpenGL Toolkit's model)
		 * 
		 * @param newOrigin 
		 * @param newRotation 
		 */
		void reset_transformation(btVector3& newOrigin, btQuaternion& newRotation);

		/**
		 * @brief Set the scale
		 * 
		 * @param scale 
		 */
		void set_scale(gltVec3 scale)
		{
			scale_ = scale;
		}

		/**
		 * @brief Set the scale
		 * 
		 * @param scale 
		 */
		void set_scale(float scale)
		{
			scale_ = gltVec3(scale, scale, scale);
		}

	public:	
		
		/**
		 * @brief Operator to return the OpenGL Toolkit's model
		 * 
		 * @return PSPtr<gltModel> 
		 */
		operator PSPtr<gltModel>() { return model_; }

		/**
		 * @brief Operator to return the bullet rigid body 
		 * 
		 * @return btRigidBody* const 
		 */
		operator btRigidBody* const() { return rigidBody_; }

	public:

		/**
		 * @brief Return the OpenGL Toolkit's model
		 * 
		 * @return PSPtr<gltModel> 
		 */
		 PSPtr<gltModel> model() { return model_; }

		 /**
		  * @brief Return the bullet's rigid body
		  * 
		  * @return btRigidBody* const 
		  */
		 btRigidBody* const rigidBody() { return rigidBody_; }

		 /**
		  * @brief Return the scale
		  * 
		  * @return const gltVec3& 
		  */
		 const gltVec3& scale() { return scale_; }

		 /**
		  * @brief Return the name
		  * 
		  * @return const PString& 
		  */
		 const PString& name() { return name_; };

	protected:

		/**
		 * @brief Synchronize the OpenGL Tookit's model with the Bullet's rigid body
		 * 
		 */
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