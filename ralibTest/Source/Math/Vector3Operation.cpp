#include "Vector3Operation.h"

Vector3 operator - (const Vector3& src)
{
	return Vector3{
		-src.x,
		-src.y,
		-src.z
	};
}
