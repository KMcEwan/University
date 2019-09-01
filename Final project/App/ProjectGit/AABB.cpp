/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "AABB.h"
#include "BoundingSphere.h"
#include "CollisionDetector.h"
#include "Utils.h"

const vec2 AABB::getCenter() const
{
	return center;
}

const vec2 AABB::getRadii() const
{
	return radius;
}

void AABB::update(const Transform& transform)
{
	center = transform.getPosition();
}