/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by Kirsty McEwan, Lauren McNally, Matthew McMahon Wood as a group assignment for the Game Physics module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Drag.h"
#include <glm\glm.hpp>

void Drag::updateForce(PhysicsParameters * Parameters, float dt)
{
	vec2 drag = Parameters->Velocity;
	float dragCoeff = length(drag);
	dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;
	if (length(drag) != 0)
	{
		drag = -dragCoeff * normalize(drag);
		Parameters->AddForce(drag);
	}
}
