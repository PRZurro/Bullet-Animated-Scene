#include <Static_Rigid_Body.hpp>

#include <Rigid_Body_Construction_Info.hpp>

namespace prz
{
	Static_Rigid_Body::Static_Rigid_Body
	(
		const PString& name,
		btVector3& origin,
		btQuaternion& initialRotation,
		PSPtr<btCollisionShape> collisionShape,
		float scale
	) :
		Rigid_Body(name, origin, initialRotation, RB_Construct_Info(collisionShape, 0.f), scale)
	{}
}